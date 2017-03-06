#include "GridLayer.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(GridLayer)
	{}

	const Vector2& GridLayer::GetCellSize() const
	{
		return _cellSize;
	}

	const IntVector2& GridLayer::GetCellCount() const
	{
		return _cellCount;
	}
}