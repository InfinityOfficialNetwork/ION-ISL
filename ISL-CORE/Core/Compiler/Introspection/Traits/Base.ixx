export module ION.Core.Compiler.Introspection.Traits.Base;

import ION.Core.Object;

export namespace ION::Core::Compiler::Introspection::Traits
{
	template <typename T>
	class Base : public Object
	{
	public:
		const inline virtual consteval bool Value () const noexcept = 0;
	};

	template <typename T>
	class True : public Base<T>
	{
	public:
		const inline virtual consteval bool Value () const noexcept
		{
			return true;
		}
	};

	template <typename T>
	class False : public Base<T>
	{
	public:
		const inline virtual consteval bool Value () const noexcept
		{
			return false;
		}
	};
}