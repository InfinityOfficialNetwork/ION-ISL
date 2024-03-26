module;

#include <cstdint>
#include <stdfloat>

import <Windows.h>;
export module ION.Core.Object;

export namespace ION::Core
{
	class Object
	{

	};

	typedef int8_t Int8;
	typedef int16_t Int16;
	typedef int32_t Int32;
	typedef int64_t Int64;

	typedef uint8_t UInt8;
	typedef uint16_t UInt16;
	typedef uint32_t UInt32;
	typedef uint64_t UInt64;

	typedef char8_t Char8;
	typedef char16_t Char16;
	typedef char32_t Char32;

	typedef Char16 Char;

	typedef int8_t Byte;

	typedef bool Bool;

	typedef float Float32;
	typedef double Float64;
	typedef long double Float128;

	class MetaObject
	{
	public:
		MetaObject& Add (const MetaObject& rhs) const;
		MetaObject& Subtract (const MetaObject& rhs) const;
		MetaObject& Multiply (const MetaObject& rhs) const;
		MetaObject& Divide (const MetaObject& rhs) const;
		MetaObject& Modulus (const MetaObject& rhs) const;

		MetaObject& operator+ (const MetaObject& rhs) const;
		MetaObject& operator- (const MetaObject& rhs) const;
		MetaObject& operator* (const MetaObject& rhs) const;
		MetaObject& operator/ (const MetaObject& rhs) const;
		MetaObject& operator% (const MetaObject& rhs) const;

		MetaObject& AddTo (const MetaObject& rhs);
		MetaObject& SubtractTo (const MetaObject& rhs);
		MetaObject& MultiplyTo (const MetaObject& rhs);
		MetaObject& DivideTo (const MetaObject& rhs);
		MetaObject& ModulusTo (const MetaObject& rhs);

		MetaObject& BitsShiftLeft (int rhs) const;
		MetaObject& BitsShiftRight (int rhs) const;
		MetaObject& BitsAnd (const MetaObject& rhs) const;
		MetaObject& BitsOr (const MetaObject& rhs) const;
		MetaObject& BitsXor (const MetaObject& rhs) const;
		MetaObject& BitsNot (const MetaObject& rhs) const;

		MetaObject& BitsShiftLeftTo (int rhs);
		MetaObject& BitsShiftRightTo (int rhs);
		MetaObject& BitsAndTo (const MetaObject& rhs);
		MetaObject& BitsOrTo (const MetaObject& rhs);
		MetaObject& BitsXorTo (const MetaObject& rhs);
		MetaObject& BitsNotTo (const MetaObject& rhs);

		MetaObject& PreIncrement ();
		MetaObject PostIncrement ();
		MetaObject& PreDecrement ();
		MetaObject PostDecrement ();

		Bool Equality (const MetaObject& rhs);
		Bool Inequality (const MetaObject& rhs);
		Bool GreaterThan (const MetaObject& rhs);
		Bool GreaterThanEqual (const MetaObject& rhs);
		Bool LessThan (const MetaObject& rhs);
		Bool LessThanEqual (const MetaObject& rhs);

		MetaObject* Reference ();
		MetaObject& Dereference ();

		MetaObject& MemberDereference ();

		MetaObject& SubScript (const int rhs);
	};

#undef FALSE
#ifdef FALSE
	class Int128
	{
	private:
		Int64 _Low;
		Int64 _High;

	public:
		inline Int128 ()
		{}
		inline constexpr Int128 (Int64 Low) noexcept : _Low (Low), _High (0)
		{}
		inline constexpr Int128 (Int64 Low, Int64 High) noexcept : _Low (Low), _High (High)
		{}

		inline Int128 operator+(const Int128 rhs)
		{
			Int128 Result;
			Result._Low = _Low + rhs._Low;
			Result._High = _High + rhs._High + ((Result._Low < _Low) || (Result._Low < rhs._Low));
			return Result;
		}

		inline Int128& operator+=(const Int128 rhs)
		{
			_Low += rhs._Low;
			_High += rhs._High + (_Low < rhs._Low);
			return *this;
		}

		inline Int128& operator++()
		{
			_Low += 1;
			_High += (_Low < 1);
			return *this;
		}

		inline Int128 operator++(int)
		{
			Int128 Result (*this);
			Result._Low += 1;
			Result._High += (Result._Low < 1);
			return Result;
		}

		inline Int128 operator-(const Int128 rhs)
		{
			Int128 Result;
			Result._Low = _Low - rhs._Low;
			Result._High = _High - rhs._High - ((Result._Low > _Low) || (Result._Low > rhs._Low));
			return Result;
		}

		inline Int128& operator+=(const Int128 rhs)
		{
			_Low += rhs._Low;
			_High += rhs._High + (_Low < rhs._Low);
			return *this;
		}

		inline Int128& operator--()
		{
			_Low -= 1;
			_High -= (_Low > 1);
			return *this;
		}

		inline Int128 operator--(int)
		{
			Int128 Result (*this);
			Result._Low -= 1;
			Result._High -= (Result._Low > 1);
			return Result;
		}

	};
#endif // FALSE

}