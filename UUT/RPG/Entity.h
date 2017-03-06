#pragma once
#include <Core/Object.h>
#include "LevelIndex.h"

namespace uutRPG
{
	using namespace uut;

	class Entity : public Object
	{
		UUT_OBJECT(uutRPG, Entity, Object)
	public:
		Entity();

		const LevelIndex& GetLevelIndex() const;

	protected:
		LevelIndex _index;
	};
}