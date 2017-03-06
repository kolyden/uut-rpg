#pragma once
#include <Core/Collections/List.h>
#include "Item.h"
#include <Core/Ptr.h>

namespace uutRPG
{
	using namespace uut;

	class ItemContainer
	{
	public:

	protected:
		List<SharedPtr<Item>> _data;
	};

}
