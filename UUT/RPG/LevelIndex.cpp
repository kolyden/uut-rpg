#include "LevelIndex.h"
#include "Level.h"

namespace uutRPG
{
	UUT_VALUETYPE_IMPLEMENT(LevelIndex)
	{}

	const LevelIndex LevelIndex::Empty;

	LevelIndex::LevelIndex()
		: _data(0)
	{
	}

	LevelIndex::LevelIndex(const SharedPtr<Level>& level, intptr_t data)
		: _level(level)
		, _data(data)
	{
	}

	LevelIndex::LevelIndex(const SharedPtr<Level>& level, void* data)
		: _level(level)
		, _ptr(data)
	{

	}

	SharedPtr<Level> LevelIndex::GetLevel() const
	{
		return _level.Lock();
	}

	LevelIndex LevelIndex::GetNeighbor(int direction) const
	{
		if (auto level = _level.Lock())
			return level->GetCellNeighbor(*this, direction);

		return Empty;
	}

	intptr_t LevelIndex::GetData() const
	{
		return _data;
	}

	void* LevelIndex::GetPtr() const
	{
		return _ptr;
	}

	bool LevelIndex::IsValid() const
	{
		return !_level.Expired() && (_level.Lock())->IsIndexValid(*this);
	}
}