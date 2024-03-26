module;

export module ION.Core.Compiler.Introspection.Traits.Capabilities.Constructor.DefaultConstructor;

import std;
export import ION.Core.Object;
export import ION.Core.Compiler.Introspection.Traits.Base;

export namespace ION::Core::Compiler::Introspection::Traits::Capabilities::Constructor
{
    template <typename T>
    class DefaultConstructor : public Base<T>
    {
    private:
        template<typename U>
        struct DefaultConstructorImpl
        {
        private:
            template<typename V>
            constexpr static auto Test () -> decltype(V (), True<T>{});

            template<typename V>
            constexpr static False<T> Test (...);

        public:
            static bool inline constexpr Value = decltype(Test<U> ()){}.Value ();
        };


    public:
        const inline virtual consteval bool Value () const noexcept override
        {
            return DefaultConstructorImpl<T>::Value;
        }
    };
}