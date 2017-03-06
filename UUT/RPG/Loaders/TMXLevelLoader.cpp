#include "TMXLevelLoader.h"
#include <Core/IO/Stream.h>
#include "../Level.h"
#include "../TilemapLayer.h"
#include "../Tileset.h"
#include "TSXTilesetLoader.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(TMXLevelLoader)
	{}

	SharedPtr<Resource> TMXLevelLoader::Load(const SharedPtr<Stream>& stream)
	{
		if (!stream->GetPath().IsExtension("tmx"))
			return nullptr;

		return nullptr;
	}

	const Type* TMXLevelLoader::GetResourceType() const
	{
		return Level::GetTypeStatic();
	}
}