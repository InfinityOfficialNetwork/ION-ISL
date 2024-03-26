export module ION.Core.Types.Functor;

export import ION.Core.Object;

export namespace ION::Core::Types
{
	template<typename T, typename... Args>
	class Functor : public Object
	{
	public:
		inline constexpr Functor (T (*Function)(Args...)) noexcept : _Function (Function)
		{}

		inline constexpr Functor () noexcept : _Function (nullptr)
		{}

		inline constexpr Functor (const Functor& rhs) noexcept : _Function(rhs._Function)
		{}

		inline constexpr T Invoke (Args... args) const
		{
			return _Function (args...);
		}

		inline constexpr T operator()(Args... args) const
		{
			return Invoke(args...);
		}

	private:
		T (*_Function)(Args...);
	};
}