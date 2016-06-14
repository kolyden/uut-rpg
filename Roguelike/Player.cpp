#include "Player.h"
#include <Core/Math/Rect.h>
#include <Video/Texture2D.h>
#include <Tilemap/Tilemap.h>
#include <Video/Graphics.h>
#include "CellInfoLayer.h"
#include "MapDoor.h"

namespace uut
{
	Player::Player(Texture2D* tex, CellInfoLayer* passability)
		: _texture(tex)
		, _passability(passability)
		, _moving(false)
	{
	}

	void Player::Update(float deltaTime)
	{
		if (!_moving)
			return;

		const float moveTime = 0.1f;

		_time += deltaTime;
		if (_time >= moveTime)
		{
			_moving = false;
			_offset = Vector2::Zero;
		}
		else
		{
			const float t = 1.0f - _time / moveTime;
			const auto& size = _layer->GetTilemap()->GetCellSize();
			switch (_moveDir)
			{
			case Direction::West: _offset = Vector2::Scale(size, Vector2(+t, 0)); break;
			case Direction::East: _offset = Vector2::Scale(size, Vector2(-t, 0)); break;
			case Direction::North: _offset = Vector2::Scale(size, Vector2(0, -t)); break;
			case Direction::South: _offset = Vector2::Scale(size, Vector2(0, +t)); break;
			}
		}
	}

	void Player::Move(Direction dir)
	{
		if (_moving)
			return;

		static const Dictionary<Direction, IntVector2> dirOffset = {
			{ Direction::West, IntVector2(-1, 0) },
			{ Direction::East, IntVector2(+1, 0) },
			{ Direction::North, IntVector2(0, -1) },
			{ Direction::South, IntVector2(0, +1) }
		};

		IntVector2 offset;
		if (!dirOffset.TryGetValue(dir, offset))
			return;

		const IntVector2 newPos = _position + offset;
		if (_passability->IsBlocked(newPos.x, newPos.y))
			return;

		auto item = _layer->GetItem(newPos);
		if (item != nullptr)
		{
			if (item->IsBlocked())
			{
				auto door = dynamic_cast<MapDoor*>(item);
				if (door == nullptr)
					return;

				door->SetOpened(true);
				return;
			}
		}

		_position = newPos;
		_moving = true;
		_moveDir = dir;
		_time = 0;
		Update(0);
	}

	void Player::Move(int dx, int dy)
	{
		SetPosition(_position + IntVector2(dx, dy));
	}

	void Player::Draw(Graphics* graphics) const
	{
		auto tilemap = _layer->GetTilemap();
		auto& size = tilemap->GetSize();
		auto& cellSize = tilemap->GetCellSize();

		auto pos = IntVector2(_position.x, size.y - _position.y - 1);
		graphics->DrawQuad(Rect(Vector2::Scale(cellSize, pos) + _offset, cellSize), 15, _texture);
	}
}