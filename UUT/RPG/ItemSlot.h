#pragma once
#include <Core/Object.h>
#include <Core/HashString.h>

namespace uutRPG
{
	using namespace uut;

	class ItemSlot : public Object
	{
		UUT_OBJECT(uutRPG, ItemSlot, Object)
	public:
		ItemSlot();

	protected:
		HashString _name;
	};
}