#include "Player.h"
#include <Core/Math/Rect.h>
#include <Video/Texture2D.h>
#include <Video/Graphics.h>
#include "MapDoor.h"

namespace uutRPG
{
// 	Player::Player(Texture2D* tex, BlockedLayer* passability)
// 		: _texture(tex)
// 		, _passability(passability)
// 		, _moving(false)
// 	{
// 	}
// 
// 	void Player::Update(float deltaTime)
// 	{
// 		if (!_moving)
// 		{
// 			while (!_path.IsEmpty())
// 			{
// 				if (_path[0] == _position)
// 					_path.RemoveAt(0);
// 				else
// 				{
// 					if (!MoveTo(_path[0]))
// 					{
// 						_path.Clear();
// 						return;
// 					}
// 
// 					_path.RemoveAt(0);
// 					return;
// 				}
// 			}
// 
// 			return;
// 		}
// 
// 		const float moveTime = 0.1f;
// 
// 		_time += deltaTime;
// 		if (_time >= moveTime)
// 		{
// 			_moving = false;
// 			_offset = Vector2::Zero;
// 		}
// 		else
// 		{
// 			const float t = 1.0f - _time / moveTime;
// 			Vector2 size = _layer->GetTilemap()->GetCellSize();
// 			size.y *= -1;
// 			_offset = -Vector2::Scale(size, _movingDelta*t);
// 		}
// 	}
// 
// 	bool Player::Move(Direction dir)
// 	{
// 		if (_moving)
// 			return false;
// 
// 		static const Dictionary<Direction, IntVector2> dirOffset = {
// 			{ Direction::West, IntVector2(-1, 0) },
// 			{ Direction::East, IntVector2(+1, 0) },
// 			{ Direction::North, IntVector2(0, -1) },
// 			{ Direction::South, IntVector2(0, +1) }
// 		};
// 
// 		IntVector2 offset;
// 		if (!dirOffset.TryGetValue(dir, offset))
// 			return false;
// 
// 		const IntVector2 newPos = _position + offset;
// 		if (_passability->Get(newPos.x, newPos.y) > 0)
// 			return false;
// 
// 		auto item = _layer->GetItem(newPos);
// 		if (item != nullptr)
// 		{
// 			if (item->IsBlocked())
// 			{
// 				auto door = dynamic_cast<MapDoor*>(item);
// 				if (door == nullptr)
// 					return false;
// 
// 				door->SetOpened(true);
// 				return false;
// 			}
// 		}
// 
// 		_moving = true;
// 		_movingDelta = newPos - _position;
// 		_time = 0;
// 		_position = newPos;
// 		Update(0);
// 
// 		return true;
// 	}
// 
// 	bool Player::MoveTo(const IntVector2& newPos)
// 	{
// 		if (_moving)
// 			return false;
// 
// 		const IntVector2 offset = newPos - _position;
// 		if (offset == IntVector2::Zero)
// 			return false;
// 
// 		if (_passability->Get(newPos.x, newPos.y) > 0)
// 			return false;
// 
// 		auto item = _layer->GetItem(newPos);
// 		if (item != nullptr)
// 		{
// 			if (item->IsBlocked())
// 			{
// 				auto door = dynamic_cast<MapDoor*>(item);
// 				if (door == nullptr)
// 					return false;
// 
// 				door->SetOpened(true);
// 				return false;
// 			}
// 		}
// 
// 		_moving = true;
// 		_movingDelta = newPos - _position;
// 		_time = 0;
// 		_position = newPos;
// 		Update(0);
// 
// 		return true;
// 	}
// 
// 	bool Player::TravelTo(const IntVector2& position)
// 	{
// 		if (_moving)
// 			return false;
// 
// 		_path.Clear();
// 		return _passability->MakePath(_position, position, _path);
// 	}
// 
// 	void Player::Draw(Graphics* graphics) const
// 	{
// 		auto tilemap = _layer->GetTilemap();
// 		auto& size = tilemap->GetSize();
// 		auto& cellSize = tilemap->GetCellSize();
// 
// 		auto pos = IntVector2(_position.x, size.y - _position.y - 1);
// 		graphics->DrawQuad(Rect(Vector2::Scale(cellSize, pos) + _offset, cellSize), 15, _texture);
// 	}
}