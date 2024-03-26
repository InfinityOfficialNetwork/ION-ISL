export module ION.Core.Compiler.Source.Location;


export import ION.Core.Object;
import std;

export namespace ION::Core::Compiler::Source
{
	struct Location : public Object
	{
	public:
		const int Line;
		const std::wstring File;
		const constexpr Location (std::wstring file, int line) : File (file), Line (line)
		{}
		const constexpr Location () : Line (0), File (L"")
		{}
	};
}