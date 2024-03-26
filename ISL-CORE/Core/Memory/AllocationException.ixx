export module ION.Core.Memory.AllocationException;

export import ION.Core.Object;
export import ION.Core.LegacyException;
export import ION.Core.Compiler.Source.Location;
import std;

export namespace ION::Core::Memory
{
	class AllocationException : public LegacyException
	{
	public:
		const constexpr AllocationException (Compiler::Source::Location loc) : LegacyException (std::string ("MEMORT_ALLOCATION"), loc)
		{}
	};
}