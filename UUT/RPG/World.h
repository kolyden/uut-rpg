#pragma once
#include <Core/Module.h>

namespace uutRPG
{
	using namespace uut;

	class Level;

	class World : public Module
	{
		UUT_MODULE(uutRPG, World, Module)
	public:
		World();

	protected:
		List<SharedPtr<Level>> _levels;
	};
}