module;

export module ION.Core.Compiler.Introspection.Traits.Capabilities.Constructor.MoveConstructor;

import std;
export import ION.Core.Object;
export import ION.Core.Compiler.Introspection.Traits.Base;

export namespace ION::Core::Compiler::Introspection::Traits::Capabilities::Constructor
{
    template <typename T>
    class MoveConstructor : public Base<T>
    {
    private:
        template<typename U>
        struct MoveConstructorImpl
        {
        private:
            template<typename V>
            constexpr static auto Test (const T&& v) -> decltype(V (v), True<T>{});

            template<typename V>
            constexpr static False<T> Test (...);

        public:
            static bool inline constexpr Value = decltype(Test<U> (std::declval<U> ())){}.Value ();
        };


    public:
        const inline virtual consteval bool Value () const noexcept override
        {
            return MoveConstructorImpl<T>::Value;
        }
    };
}