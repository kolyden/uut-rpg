#include "TilemapLayer.h"
#include "Tileset.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(TilemapLayer)
	{}

	SharedPtr<Tileset> TilemapLayer::GetTileset() const
	{
		return _tileset;
	}
}