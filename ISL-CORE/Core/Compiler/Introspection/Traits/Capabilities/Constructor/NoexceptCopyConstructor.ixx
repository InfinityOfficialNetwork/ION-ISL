module;

export module ION.Core.Compiler.Introspection.Traits.Constructor.NoexceptCopyConstructor;

import std;
export import ION.Core.Object;
export import ION.Core.Compiler.Introspection.Traits.Base;

export namespace ION::Core::Compiler::Introspection::Traits::Constructor
{
    template <typename T>
    class NoexceptCopyConstructor : public Base<T>
    {
    private:
        // Primary template for checking the existence of a copy constructor
        template<typename U>
        struct NoexceptCopyConstructorImpl
        {
        private:
            // SFINAE test for the existence of a copy constructor
            template<typename V>
            constexpr static auto Test (const V& v) -> decltype(V (v), noexcept(V (std::declval<const V&>())) ? True<T>{} : False<T>{});

            template<typename V>
            constexpr static False<T> Test (...);

        public:
            // Define a constexpr boolean value
            static bool inline constexpr Value = decltype(Test<U> (std::declval<U> ())){}.Value ();
        };


    public:
        // Public function to check if a copy constructor is visible
        const inline virtual consteval bool Value () const noexcept override
        {
            return NoexceptCopyConstructorImpl<T>::Value;
        }
    };
}