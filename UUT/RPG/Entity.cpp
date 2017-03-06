#include "Entity.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(Entity)
	{}

	Entity::Entity()
	{
	}

	const LevelIndex& Entity::GetLevelIndex() const
	{
		return _index;
	}

}