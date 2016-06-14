#include "main.h"
#include <Core/Math/Math.h>
#include <Core/Math/Rect.h>
#include <IMGUI/imgui.h>
#include <Core/Context.h>
#include <Core/Reflection/PropertyInfo.h>
#include <Core/Plugin.h>
#include <Core/Variant.h>
#include <Core/Enum.h>
#include <Core/Reflection/MethodInfo.h>
#include <Core/Reflection/ConstructorInfo.h>
#include <Core/Reflection/ConverterInfo.h>
#include <Windows.h>
#include <Resources/ResourceLoader.h>
#include <Video/BitmapFont.h>
#include <Video/Loaders/BitmapFontLoader.h>
#include <Tilemap/Tilemap.h>
#include <Tilemap/TilesetLayer.h>
#include <Tilemap/Tileset.h>
#include <Tilemap/ObjectLayer.h>
#include <Tilemap/PassabilityLayer.h>
#include <Tilemap/InfoLayer.h>
#include "CellInfoLayer.h"
#include "Player.h"
#include "MapDoor.h"

namespace uut
{
	SampleApp::SampleApp()
	{
		_windowSize = IntVector2(800, 600);
	}

	void SampleApp::OnInit()
	{
		_gui = new DebugGUI();
		_graphics = new Graphics();
		_graphics->SetProjection(Graphics::PM_2D);
		_font = _cache->Load<Font>("Consolas.fnt");

		_tilemap = new Tilemap();
		_tilemap->SetSize(IntVector2(11));
		_tilemap->SetCellSize(Vector2(32));
		auto layer1 = _tilemap->AddLayer<TilesetLayer>("Tiles");
		auto layer2 = _tilemap->AddLayer<TilesetLayer>("Objects");
		auto layer3 = _tilemap->AddLayer<ObjectLayer>("Characters");
		auto layer4 = _tilemap->AddLayer<CellInfoLayer>("Passability");
		_tileLayers << WeakPtr<TilesetLayer>(layer1) << WeakPtr<TilesetLayer>(layer2);
		_objectLayer = layer3;

		auto tileset = new Tileset();
		tileset->SetTexture(_cache->Load<Texture2D>("rogueliketiles.png"));
		tileset->GenerateItems(IntVector2(16));

		layer1->SetTileset(tileset);
		layer1->ForEach([this, layer4](int x, int y, uint8_t& tile)
		{
			const uint8_t grassTile = 1;
			const uint8_t wallTile = 7;

			if (x == 0 || y == 0 || x == _tilemap->GetSize().x - 1 || y == _tilemap->GetSize().y - 1)
			{
				tile = wallTile;
				layer4->SetBlocked(x, y, true);
			}
			else
			{
				tile = grassTile;
				layer4->SetBlocked(x, y, false);
			}
		});
		layer1->SetTile(5, 0, 1); layer4->SetBlocked(5, 0, false);

		Dictionary<Direction, IntVector2> pairs = {
			{ Direction::North, IntVector2::Zero },
			{ Direction::West, IntVector2::Zero }
		};

		const uint8_t treeTile = 0;
		const uint8_t torchTile = 16;
		const uint8_t welltile = 42;
		layer2->SetTileset(tileset);
		layer2->SetTransparent(true);
		layer2->Clear();
		layer2->SetTile(3, 3, treeTile); layer4->SetBlocked(3, 3, true);
		layer2->SetTile(6, 7, treeTile); layer4->SetBlocked(6, 7, true);
		layer2->SetTile(2, 8, treeTile); layer4->SetBlocked(2, 8, true);
		layer2->SetTile(4, 0, torchTile);
		layer2->SetTile(6, 0, torchTile);
		layer2->SetTile(5, 5, welltile); layer4->SetBlocked(5, 5, true);

		_player = new Player(_cache->Load<Texture2D>("angel.png"), layer4);
		layer3->AddItem(IntVector2(5, 1), _player);
		layer3->AddItem(IntVector2(5, 0), new MapDoor(layer2, 2, 3));
		layer3->AddItem(IntVector2(8, 1), new MapDoor(layer2, 18, 19));

		_timer.Start();
	}

	void SampleApp::OnFrame()
	{
		_timer.Update();
		_gui->NewFrame();

		if (_tilemap)
			_tilemap->Update(_timer.GetDeltaTime());

		if (_player)
		{
			if (Input::IsKeyDown(SDL_SCANCODE_LEFT)) _player->Move(Direction::West);
			if (Input::IsKeyDown(SDL_SCANCODE_RIGHT)) _player->Move(Direction::East);
			if (Input::IsKeyDown(SDL_SCANCODE_UP)) _player->Move(Direction::North);
			if (Input::IsKeyDown(SDL_SCANCODE_DOWN)) _player->Move(Direction::South);
		}

		///////////////////////////////////////////////////////////////
		_renderer->Clear(Color32(114, 144, 154));
		if (_renderer->BeginScene())
		{
			_graphics->SetMaterial(Graphics::MT_TRANSPARENT);
			_graphics->SetProjection(Graphics::PM_2D);
// 			if (_font)
// 				_graphics->PrintText(Vector2(10, 10), 15, "qwertyuiopasdfghjklzxcvbnm", _font, Color32::Black);
			_graphics->Flush();

			for (auto& layer : _tileLayers)
			{
				if (layer && layer->IsVisible())
					layer->DrawLayer(_graphics);
			}
			if (_objectLayer)
				_objectLayer->DrawLayer(_graphics);
			_graphics->Flush();

			_gui->SetupCamera();
			_gui->Draw();

			_renderer->EndScene();
		}
	}
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow)
{
	uut::SampleApp app;
	app.Run();

	return 0;
}