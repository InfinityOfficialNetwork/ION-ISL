export module ION.Core.Compiler.Introspection.Traits.Capabilities.Arithmetic.Division;

import std;
export import ION.Core.Object;
export import ION.Core.Compiler.Introspection.Traits.Base;

export namespace ION::Core::Compiler::Introspection::Traits::Capabilities::Division
{
    template <typename T>
    class Division : public Base<T>
    {
    private:
        template<typename U>
        struct DivisionImpl
        {
        private:
            template<typename V>
            constexpr static auto Test (const V& v) -> decltype(v.Subtract (v), v / v, True<T>{});

            template<typename V>
            constexpr static False<T> Test (...);

        public:
            static bool inline constexpr Value = decltype(Test<U> (std::declval<U> ())){}.Value ();
        };


    public:
        const inline virtual consteval bool Value () const noexcept override
        {
            return DivisionImpl<T>::Value;
        }
    };
}