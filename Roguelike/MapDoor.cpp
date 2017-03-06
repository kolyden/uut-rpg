#include "MapDoor.h"

namespace uutRPG
{
// 	MapDoor::MapDoor(TilesetLayer* layer, uint8_t doorClosed, uint8_t doorOpen, bool opened)
// 		: _tilelayer(layer)
// 		, _tileClosed(doorClosed)
// 		, _tileOpened(doorOpen)
// 		, _opened(opened)
// 	{}
// 
// 	void MapDoor::SetOpened(bool opened)
// 	{
// 		if (_opened == opened)
// 			return;
// 
// 		_opened = opened;
// 		UpdateTile();
// 	}
// 
// 	bool MapDoor::IsOpened() const
// 	{
// 		return _opened;
// 	}
// 
// 	////////////////////////////////////////////////////////////////////////////
// 	void MapDoor::OnInit()
// 	{
// 		UpdateTile();
// 	}
// 
// 	void MapDoor::UpdateTile()
// 	{
// 		_tilelayer->SetTile(_position.x, _position.y,
// 		                    _opened ? _tileOpened : _tileClosed);
// 	}
}