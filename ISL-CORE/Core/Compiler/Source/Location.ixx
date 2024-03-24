export module ION.Core.Compiler.Source.Location;


export import ION.Core.Object;
import std;

export namespace ION::Core::Compiler::Source {
	class Location : public Object {
	public:
		const int Line = 0;
		const std::string File = "";
		const std::string Function = "";
		const constexpr Location(std::string func, std::string file, int line) : Function(func), File(file), Line(line) {}
		const constexpr Location(std::string file, int line) : File(file), Line(line), Function() {}
		const constexpr Location() : Line(), File(), Function() {}
		const constexpr std::string Where() const {
			return std::string(File + std::string(":") + std::to_string(Line) + std::string(":") + Function);
		}
	};
}