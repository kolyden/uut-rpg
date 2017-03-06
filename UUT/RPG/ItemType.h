#pragma once
#include <Core/HashString.h>
#include <Core/Object.h>

namespace uutRPG
{
	using namespace uut;

	class ItemType : public Object
	{
		UUT_OBJECT(uutRPG, ItemType, Object)
	public:
		ItemType();

	protected:
		HashString _name;
	};

}