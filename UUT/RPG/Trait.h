#pragma once
#include <Core/Object.h>
#include <Core/HashString.h>

namespace uutRPG
{
	using namespace uut;

	class Trait : public Object
	{
		UUT_OBJECT(uutRPG, Trait, Object)
	public:
		Trait();

	protected:
		uint16_t _max;
		HashString _name;
	};

	class Attribute : public Trait
	{
	public:
	};

	class Skill : public Trait
	{
	public:
	};

	class TraitValue
	{
	public:
		Trait* _trait;
		uint16_t _value;
	};
}