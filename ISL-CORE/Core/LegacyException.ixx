export module ION.Core.LegacyException;

import std;
import ION.Core.Object;
import ION.Core.Compiler.Source.Location;

export namespace ION::Core
{
	class LegacyException : public Object
	{
	public:
		constexpr const virtual std::string What () const
		{
			return Error;
		}
		constexpr const virtual std::string Where () const
		{
			return "";// Location.Where ();
		}
		const constexpr LegacyException () : Location (), Error (), Address (nullptr), InnerException (nullptr), ObjectType (nullptr)
		{}
		const constexpr LegacyException (std::string error) : Error (error), Location (), Address (nullptr), InnerException (nullptr), ObjectType (nullptr)
		{}
		const constexpr LegacyException (std::string error, Compiler::Source::Location location) : Location (location), Error (error)
		{}
		const constexpr LegacyException (std::string error, Compiler::Source::Location location, void* address) : Error (error), Location (location), Address (address)
		{}
		const constexpr LegacyException (std::string error, Compiler::Source::Location location, const void* address, const LegacyException& innerException) : Error (error), Location (location), Address (address), InnerException (&innerException)
		{}

		void test ()
		{

		}
	protected:
		const Compiler::Source::Location Location;
		const std::string Error = "";
		const void* Address = nullptr;
		const LegacyException* InnerException = nullptr;
		const std::type_info* ObjectType = nullptr;
	};
}