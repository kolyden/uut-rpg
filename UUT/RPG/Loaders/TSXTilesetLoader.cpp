#include "TSXTilesetLoader.h"
#include <Core/IO/Stream.h>
#include "../Tileset.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(TSXTilesetLoader)
	{}

	SharedPtr<Resource> TSXTilesetLoader::Load(const SharedPtr<Stream>& stream)
	{
		if (!stream->GetPath().IsExtension("tsx"))
			return nullptr;

		return nullptr;
	}

	const Type* TSXTilesetLoader::GetResourceType() const
	{
		return Tileset::GetTypeStatic();
	}
}