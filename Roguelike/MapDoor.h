#pragma once
#include <Tilemap/ObjectLayer.h>

namespace uut
{
	class TilesetLayer;
}

namespace uutRPG
{
	using namespace uut;

// 	class MapDoor : public ObjectLayerItem
// 	{
// 	public:
// 		MapDoor(TilesetLayer* layer, uint8_t doorClosed, uint8_t doorOpen, bool opened = false);
// 
// 		void SetOpened(bool opened);
// 
// 		bool IsOpened() const;
// 
// 		virtual void Update(float deltaTime) override {}
// 		virtual void Draw(Graphics* graphics) const override {}
// 		virtual bool IsBlocked() const override { return !IsOpened(); }
// 
// 	protected:
// 		WeakPtr<TilesetLayer> _tilelayer;
// 		uint8_t _tileClosed;
// 		uint8_t _tileOpened;
// 		bool _opened;
// 
// 		virtual void OnInit() override;
// 
// 		void UpdateTile();
// 	};
}