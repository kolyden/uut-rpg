#pragma once
#include <Resources/Resource.h>
#include <Core/Collections/List.h>
#include <Core/Math/Vector2.h>

namespace uutRPG
{
	using namespace uut;

	class LevelLayer;

	class Level : public Resource
	{
		UUT_OBJECT(uutRPG, Level, Resource)
	public:
		Level();

		void SetSize(const Vector2& size);
		const Vector2& GetSize() const;

		bool AddLayer(const SharedPtr<LevelLayer>& layer);
		bool InsertLayer(int index, const SharedPtr<LevelLayer>& layer);

		uint GetLayerCount() const;
		SharedPtr<LevelLayer> GetLayer(int index) const;

		virtual void Update(float deltaTime);

	protected:
		List<SharedPtr<LevelLayer>> _layers;
		Vector2 _size;
	};
}