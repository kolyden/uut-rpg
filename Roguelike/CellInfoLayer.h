#pragma once
#include <Tilemap/InfoLayer.h>

namespace uutRPG
{
	using namespace uut;

	struct CellInfo
	{
		bool blocked;
	};

// 	class CellInfoLayer : public InfoLayer<CellInfo>
// 	{
// 		UUT_OBJECT(uutRPG, CellInfoLayer, TilemapLayer)
// 	public:
// 		CellInfoLayer();
// 
// 		void SetBlocked(int x, int y, bool blocked) { Get(x, y).blocked = blocked; }
// 		bool IsBlocked(int x, int y) const { return Get(x, y).blocked; }
// 
// 		void Update(float deltaTime) override {}
// 	};
}