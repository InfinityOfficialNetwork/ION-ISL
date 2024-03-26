export module ION.Core.Compiler.Introspection.TraitSets.Capabilities.Constructor;

import std;
export import ION.Core.Object;
export import ION.Core.Compiler.Introspection.Traits.Base;
export import ION.Core.Compiler.Introspection.Traits.Capabilities.Constructor.CopyConstructor;
export import ION.Core.Compiler.Introspection.Traits.Capabilities.Constructor.DefaultConstructor;
export import ION.Core.Compiler.Introspection.Traits.Capabilities.Constructor.MoveConstructor;


export namespace ION::Core::Compiler::Introspection::TraitSets::Capabilities
{
    template <typename T>
    class Constructors : public Traits::Base<T>
    {
    private:
        template<typename U>
        struct ConstructorsImpl
        {
        private:
            static constexpr bool _CopyConstructor = Traits::Capabilities::Constructor::CopyConstructor<U> ().Value ();
            static constexpr bool _DefaultConstructor = Traits::Capabilities::Constructor::DefaultConstructor<U> ().Value ();
            static constexpr bool _MoveConstructor = Traits::Capabilities::Constructor::MoveConstructor<U> ().Value ();

        public:
            static bool inline constexpr Value = _CopyConstructor && _DefaultConstructor && _MoveConstructor;
        };

    public:
        const inline virtual consteval bool Value () const noexcept override
        {
            return ConstructorsImpl<T>::Value;
        }
    };
}