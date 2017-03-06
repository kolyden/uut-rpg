#pragma once
#include "GridLayer.h"

namespace uutRPG
{
	class Tileset;

	class TilemapLayer : public GridLayer
	{
		UUT_OBJECT(uutRPG, TilemapLayer, GridLayer)
	public:

		SharedPtr<Tileset> GetTileset() const;

	protected:
		SharedPtr<Tileset> _tileset;
	};
}