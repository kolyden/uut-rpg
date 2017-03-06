#pragma once
#include <Resources/ResourceLoader.h>

namespace uutRPG
{
	using namespace uut;

	class TMXLevelLoader : public ResourceLoader
	{
		UUT_OBJECT(uutRPG, TMXLevelLoader, ResourceLoader)
	public:
		virtual SharedPtr<Resource> Load(const SharedPtr<Stream>& stream) override;
		virtual const Type* GetResourceType() const override;
	};
}