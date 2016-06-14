#pragma once
#include <Core/Windows/Application.h>
#include <GUI/DebugGUI.h>
#include <Video/Graphics.h>
#include <Core/Timer.h>

#pragma comment(lib, "SDL2/SDL2.lib")

namespace uut
{
	class ObjectLayer;
	class Tilemap;
	class Player;
	class TilesetLayer;

	class SampleApp : public Application
	{
	public:
		SampleApp();

	protected:
		static const int texSize = 402;

		SharedPtr<DebugGUI> _gui;
		SharedPtr<Graphics> _graphics;
		SharedPtr<Font> _font;
		SharedPtr<Tilemap> _tilemap;
		List<WeakPtr<TilesetLayer>> _tileLayers;
		WeakPtr<ObjectLayer> _objectLayer;
		SharedPtr<Player> _player;

		Timer _timer;

		virtual void OnInit() override;
		virtual void OnFrame() override;
	};
}