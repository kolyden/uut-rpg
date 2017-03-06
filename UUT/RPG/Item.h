#pragma once
#include <Core/Object.h>
#include <Core/HashString.h>

namespace uutRPG
{
	using namespace uut;

	class ItemType;

	class Item : public Object
	{
		UUT_OBJECT(uutRPG, Item, Object)
	public:
		Item();

	protected:
		SharedPtr<ItemType> _itemType;
	};

}