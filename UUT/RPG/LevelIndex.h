#pragma once
#include <Core/ValueType.h>

namespace uutRPG
{
	using namespace uut;

	class Level;

	class LevelIndex : public ValueType
	{
		UUT_VALUETYPE(uutRPG, LevelIndex, ValueType)
	public:
		LevelIndex();
		LevelIndex(const SharedPtr<Level>& level, intptr_t data);
		LevelIndex(const SharedPtr<Level>& level, void* data);

		SharedPtr<Level> GetLevel() const;

		intptr_t GetData() const;
		void* GetPtr() const;

		bool IsValid() const;

		static const LevelIndex Empty;

	protected:
		WeakPtr<Level> _level;
		union
		{
			intptr_t _data;
			void* _ptr;
		};
	};
}