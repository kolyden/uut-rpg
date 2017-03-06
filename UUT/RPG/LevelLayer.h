#pragma once
#include <Core/Object.h>
#include <Core/HashString.h>

namespace uutRPG
{
	using namespace uut;

	class Level;

	class LevelLayer : public Object
	{
		UUT_OBJECT(uutRPG, LevelLayer, Object)
	public:
		LevelLayer();

		SharedPtr<Level> GetLevel() const;
		const HashString& GetName() const;

	protected:
		WeakPtr<Level> _level;
		HashString _name;
		bool _enabled;

		void Update(float deltaTime);

		virtual void OnUpdate(float deltaTime) {}

		friend class Level;
	};
}