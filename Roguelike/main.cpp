#include "main.h"
#include <Core/Context.h>
#include <Resources/ResourceLoader.h> // TODO: fix link bug
#include <Windows.h>
#include <Video/BitmapFont.h>
#include <Tilemap/Tilemap.h>
#include <Tilemap/TilesetLayer.h>
#include <Tilemap/Tileset.h>
#include <Tilemap/ObjectLayer.h>
// #include <Tilemap/TilesetLayerRender.h>
// #include <Tilemap/ObjectLayerRender.h>
#include "CellInfoLayer.h"
#include "Player.h"
#include "MapDoor.h"
#include <Tilemap/BlockedLayer.h>
#include <Core/Time.h>

namespace uut
{
	SampleApp::SampleApp()
	{
		_windowSize = IntVector2(800, 600);
	}

	void SampleApp::OnInit()
	{
		ModuleInstance<ResourceCache> cache;

		_graphics = SharedPtr<Graphics>::Make(Graphics::MT_OPAQUE, Graphics::PM_2D);
		_font = cache->Load<Font>("Consolas.fnt");

		/*
		_tilemap = SharedPtr<Tilemap>::Make();
		_tilemap->SetSize(IntVector2(26, 20));
		_tilemap->SetCellSize(Vector2(30));
		auto layer1 = _tilemap->AddLayer<TilesetLayer>("Background");
		auto layer2 = _tilemap->AddLayer<TilesetLayer>("Foreground");
		auto layer3 = _tilemap->AddLayer<ObjectLayer>("Objects");
		auto layer4 = _tilemap->AddLayer<BlockedLayer>("Info");

		auto render1 = _tilemap->AddLayer<TilesetLayerRender>("render1");
		auto render2 = _tilemap->AddLayer<TilesetLayerRender>("render2");
		auto render3 = _tilemap->AddLayer<ObjectLayerRender>("render3");

		render1->SetTilesetLayer(layer1);
		render2->SetTilesetLayer(layer2);
		render3->SetObjectLayer(layer3);
		_tilemapRenders << WeakPtr<TilemapRender>(render1)
			<< WeakPtr<TilemapRender>(render2)
			<< WeakPtr<TilemapRender>(render3);

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
				layer4->Set(x, y, 1);
			}
			else
			{
				tile = grassTile;
				layer4->Set(x, y, 0);
			}
		});
		layer1->SetTile(5, 0, 1); layer4->Set(5, 0, 0);

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
		layer2->SetTile(3, 3, treeTile); layer4->Set(3, 3, 1);
		layer2->SetTile(6, 7, treeTile); layer4->Set(6, 7, 1);
		layer2->SetTile(2, 8, treeTile); layer4->Set(2, 8, 1);
		layer2->SetTile(4, 0, torchTile);
		layer2->SetTile(6, 0, torchTile);
		layer2->SetTile(5, 5, welltile); layer4->Set(5, 5, 1);

		_player = new Player(_cache->Load<Texture2D>("angel.png"), layer4);
		layer3->AddItem(IntVector2(5, 1), _player);
		layer3->AddItem(IntVector2(5, 0), new MapDoor(layer2, 2, 3));
		layer3->AddItem(IntVector2(8, 1), new MapDoor(layer2, 18, 19));
		*/
	}

	void SampleApp::OnFrame()
	{
		if (_tilemap)
			_tilemap->Update(Time::GetDeltaTime());

// 		if (_player)
// 		{
// 			if (Input::IsKeyDown(SDL_SCANCODE_LEFT)) _player->Move(Direction::West);
// 			if (Input::IsKeyDown(SDL_SCANCODE_RIGHT)) _player->Move(Direction::East);
// 			if (Input::IsKeyDown(SDL_SCANCODE_UP)) _player->Move(Direction::North);
// 			if (Input::IsKeyDown(SDL_SCANCODE_DOWN)) _player->Move(Direction::South);
// 			if (Input::IsKeyDown(SDL_SCANCODE_H)) _player->TravelTo(IntVector2(5, 1));
// 		}

		///////////////////////////////////////////////////////////////
		ModuleInstance<Renderer> render;
		if (render->BeginScene())
		{
			_graphics->BeginRecord();
			_graphics->Clear(Color32::Green);
			
			_graphics->EndRecord();
			_graphics->Draw();

			render->EndScene();
			render->Present();
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