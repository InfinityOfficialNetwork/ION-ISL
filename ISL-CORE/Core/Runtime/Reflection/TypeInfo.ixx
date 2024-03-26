export module ION.Core.Runtime.Reflection.TypeInfo;

import std;
import ION.Core.Object;

export namespace ION::Core::Runtime::Reflection
{
	class TypeInfo : public Object
	{
	private:
		const std::type_info* _TypeInfo;

	public:
		const constexpr inline TypeInfo ()
		{
			_TypeInfo = &typeid(std::nullptr_t);
		}

		const constexpr inline TypeInfo (const std::type_info& typeInfo) noexcept : _TypeInfo (&typeInfo)
		{}

		const constexpr inline TypeInfo (const TypeInfo& rhs) : _TypeInfo (rhs._TypeInfo)
		{}

		constexpr inline ~TypeInfo ()
		{
			return;
		}

		const inline constexpr Bool IsNull () const
		{
			return (_TypeInfo == &typeid(std::nullptr_t));
		}

		const inline Int64 HashCode () const
		{
			return _TypeInfo->hash_code ();
		}

		const inline Bool IsBefore (const TypeInfo& rhs) const
		{
			return _TypeInfo->before (*rhs._TypeInfo);
		}

		static const inline Bool IsBefore (const TypeInfo& lhs, const TypeInfo& rhs)
		{
			return lhs._TypeInfo->before(*rhs._TypeInfo);
		}

		const inline Bool IsAfter (const TypeInfo& rhs) const
		{
			return !_TypeInfo->before (*rhs._TypeInfo);
		}

		static const inline Bool IsAfter (const TypeInfo& lhs, const TypeInfo& rhs)
		{
			return !lhs._TypeInfo->before (*rhs._TypeInfo);
		}

		// TO BE REPLACED WITH ION::Core::String
		const inline std::string Name () const
		{
			return _TypeInfo->name ();
		}

		const inline Bool IsEqual (const TypeInfo& rhs) const
		{
			return (_TypeInfo == rhs._TypeInfo);
		}

		static const inline Bool IsEqual (const TypeInfo& lhs, const TypeInfo& rhs)
		{
			return *lhs._TypeInfo == *rhs._TypeInfo;
		}

		const inline Bool IsNotEqual (const TypeInfo& rhs) const
		{
			return !(_TypeInfo == rhs._TypeInfo);
		}

		static const inline Bool IsNotEqual (const TypeInfo& lhs, const TypeInfo& rhs)
		{
			return !(*lhs._TypeInfo == *rhs._TypeInfo);
		}

		const inline Bool operator<(const TypeInfo& rhs) const
		{
			return IsBefore (rhs);
		}

		const inline Bool operator>(const TypeInfo& rhs) const
		{
			return IsAfter (rhs);
		}

		const inline Bool operator==(const TypeInfo& rhs) const
		{
			return IsEqual (rhs);
		}

		const inline Bool operator!=(const TypeInfo& rhs) const
		{
			return IsNotEqual (rhs);
		}
	};
}