#include "LevelLayer.h"
#include <Core/Math/Vector2.h>
#include <Core/Math/IntVector2.h>

namespace uutRPG
{
	class GridLayer : public LevelLayer
	{
		UUT_OBJECT(uutRPG, GridLayer, LevelLayer)
	public:

		const Vector2& GetCellSize() const;
		const IntVector2& GetCellCount() const;

	protected:
		Vector2 _cellSize;
		IntVector2 _cellCount;
	};
}