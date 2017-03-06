#pragma once
#include <Core/Object.h>

namespace uutRPG
{
	using namespace uut;

	class LevelIndex;

	class Level : public Object
	{
		UUT_OBJECT(uutRPG, Level, Object)
	public:
		Level();

		virtual int GetDirectionsCount() const = 0;
		virtual LevelIndex GetCellNeighbor(const LevelIndex& index, int direction) const = 0;

		virtual bool IsIndexValid(const LevelIndex& index) const = 0;

	protected:
		LevelIndex CreateIndex(uintptr_t data);
		LevelIndex CreateIndex(void* data);
	};
}