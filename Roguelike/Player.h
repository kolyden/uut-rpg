#pragma once
#include <Tilemap/ObjectLayer.h>
#include <Core/Math/Vector2.h>

namespace uut
{
	class Texture2D;
	class BlockedLayer;

	enum class  Direction
	{
		North, East, South, West
	};

	class Player : public ObjectLayerItem
	{
	public:
		Player(Texture2D* tex, BlockedLayer* passability);

		void Update(float deltaTime) override;

		bool Move(Direction dir);
		bool MoveTo(const IntVector2& position);

		bool TravelTo(const IntVector2& position);

		void Draw(Graphics* graphics) const override;

	protected:
		SharedPtr<Texture2D> _texture;
		WeakPtr<BlockedLayer> _passability;
		bool _moving;
		Vector2 _movingDelta;
		float _time;
		Vector2 _offset;
		List<IntVector2> _path;
	};
}