#pragma once
#include <Tilemap/ObjectLayer.h>
#include <Core/Math/Vector2.h>

namespace uut
{
	class Texture2D;
	class CellInfoLayer;

	enum class  Direction
	{
		North, East, South, West
	};

	class Player : public ObjectLayerItem
	{
	public:
		Player(Texture2D* tex, CellInfoLayer* passability);

		void Update(float deltaTime) override;
		void Move(Direction dir);
		void Move(int dx, int dy);
		void Draw(Graphics* graphics) const override;

	protected:
		SharedPtr<Texture2D> _texture;
		WeakPtr<CellInfoLayer> _passability;
		bool _moving;
		Direction _moveDir;
		float _time;
		Vector2 _offset;
	};
}