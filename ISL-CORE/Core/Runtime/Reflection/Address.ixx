export module ION.Core.Runtime.Reflection.Address;

import ION.Core.Runtime.Reflection.TypeInfo;

export namespace ION::Core::Runtime::Reflection
{
	struct Address
	{
		enum struct Kind
		{
			CLASS,
			FUNCTION,
			EXTERNAL,
			OTHER,
			UNKNOWN
		} const OriginatorKind;
		const void* OriginatorAddress;
		const Runtime::Reflection::TypeInfo Type;
		constexpr inline const Address () : OriginatorKind (Kind::UNKNOWN), OriginatorAddress (nullptr), Type ()
		{}
		constexpr inline const Address (const Kind originator) : OriginatorKind (originator), OriginatorAddress (nullptr), Type ()
		{}
		constexpr inline const Address (const void* address) : OriginatorKind (Kind::UNKNOWN), OriginatorAddress (address), Type ()
		{}
		constexpr inline const Address (const Kind originator, const void* address) : OriginatorKind (originator), OriginatorAddress (address), Type ()
		{}
		constexpr inline const Address (const void* address, const Runtime::Reflection::TypeInfo Type) : OriginatorKind (Kind::UNKNOWN), OriginatorAddress (address), Type (Type)
		{}
		constexpr inline const Address (const Kind originator, const void* address, const Runtime::Reflection::TypeInfo Type) : OriginatorKind (originator), OriginatorAddress (address), Type (Type)
		{}
	};
}