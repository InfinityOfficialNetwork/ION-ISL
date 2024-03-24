export module ION.Core.Memory.AllocationException;

export import ION.Core.Object;
export import ION.Core.Exception;
export import ION.Core.Compiler.Source.Location;
import std;

export namespace ION::Core::Memory
{
	class AllocationException : public Exception
	{
	public:
		const constexpr AllocationException (Compiler::Source::Location loc) : Exception (std::string ("MEMORT_ALLOCATION"), loc)
		{}
	};
}