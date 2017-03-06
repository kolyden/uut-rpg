#include "Level.h"
#include "LevelLayer.h"

namespace uutRPG
{
	UUT_OBJECT_IMPLEMENT(Level)
	{}

	Level::Level()
	{
	}

	void Level::SetSize(const Vector2& size)
	{
		_size = size;
	}

	const Vector2& Level::GetSize() const
	{
		return _size;
	}

	bool Level::AddLayer(const SharedPtr<LevelLayer>& layer)
	{
		return InsertLayer(_layers.Count(), layer);
	}

	bool Level::InsertLayer(int index, const SharedPtr<LevelLayer>& layer)
	{
		if (!layer || !layer->_level.Expired())
			return false;

		layer->_level = GetSharedThis();
		_layers.Insert(index, layer);
		return true;
	}

	uint Level::GetLayerCount() const
	{
		return _layers.Count();
	}

	SharedPtr<LevelLayer> Level::GetLayer(int index) const
	{
		return _layers[index];
	}

	void Level::Update(float deltaTime)
	{
		for (auto& layer : _layers)
			layer->Update(deltaTime);
	}
}