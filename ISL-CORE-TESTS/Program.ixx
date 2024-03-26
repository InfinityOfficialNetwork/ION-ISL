export module ION.Tests.Program;

import ION.Core.Compiler.Introspection.Traits.Capabilities.Constructor.CopyConstructor;
import ION.Core.Compiler.Introspection.Traits.Capabilities.Arithmetic.Addition;


import ION.Core.Compiler.Introspection.TraitSets.Capabilities.Constructor;

import std;
import ION.Tests.TestRunner;

class Test1
{
public:
	Test1 (const Test1& rhs);
	Test1 ();
	Test1 (const Test1&& rhs);
};

export namespace ION::Tests
{
	static class Program
	{
	public:
		static const int Main ()
		{
			std::cout << "Int is Constructable " << ION::Core::Compiler::Introspection::TraitSets::Capabilities::Constructors<int>{}.Value () << std::endl;
			std::cout << "Int is DefaultConstructable " << ION::Core::Compiler::Introspection::Traits::Capabilities::Constructor::DefaultConstructor<int>{}.Value () << std::endl;
			std::cout << "Int is CopyConstructable " << ION::Core::Compiler::Introspection::Traits::Capabilities::Constructor::CopyConstructor<int>{}.Value () << std::endl;
			std::cout << "Int is MoveConstructable " << ION::Core::Compiler::Introspection::Traits::Capabilities::Constructor::MoveConstructor<int>{}.Value () << std::endl;

			std::cout << "MetaObject is Addable " << ION::Core::Compiler::Introspection::Traits::Capabilities::Arithmetic::Addition<Core::MetaObject>{}.Value () << std::endl;

			std::cout << "int is Addable " << ION::Core::Compiler::Introspection::Traits::Capabilities::Arithmetic::Addition<int>{}.Value () << std::endl;


			std::is_nothrow_copy_constructible<int>;

			//TestRunner* runner = new TestRunner ();
			//runner->RunTests ();

			return 0;
		}
		static struct Environment
		{

		};
	};
}