#pragma once
#include <Core/Collections/List.h>
#include <Core/Ptr.h>

namespace uutRPG
{
	using namespace uut;

	class Trait;

	class TraitContainer
	{
	public:
		TraitContainer();

	protected:
		List<SharedPtr<Trait>> _traits;
	};
}