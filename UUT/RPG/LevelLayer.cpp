#include "LevelLayer.h"
#include "Level.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(LevelLayer)
	{}

	LevelLayer::LevelLayer()
		: _enabled(false)
	{
	}

	SharedPtr<Level> LevelLayer::GetLevel() const
	{
		return _level.Lock();
	}

	const HashString& LevelLayer::GetName() const
	{
		return _name;
	}

	void LevelLayer::Update(float deltaTime)
	{
		if (_enabled)
			OnUpdate(deltaTime);
	}

}