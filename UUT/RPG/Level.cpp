#include "Level.h"
#include "LevelIndex.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(Level)
	{}

	Level::Level()
	{
	}

	////////////////////////////////////////////////////////////////////
	LevelIndex Level::CreateIndex(uintptr_t data)
	{
		return LevelIndex(GetSharedThis(), data);
	}

	LevelIndex Level::CreateIndex(void* data)
	{
		return LevelIndex(GetSharedThis(), data);
	}
}