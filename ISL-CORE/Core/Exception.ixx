module;


export module ION.Core.Exception;

import std;
import ION.Core.Object;
import ION.Core.Compiler.Source.Location;
import ION.Core.Runtime.Reflection.TypeInfo;
import ION.Core.Runtime.Reflection.Address;
import ION.Core.Clock.HighPrecisionTimestamp;

export namespace ION::Core
{
	class Exception : public Object
	{
	public:
		enum struct Level
		{
			FATAL,
			CRITICAL,
			ERROR,
			ERROR_WARN,
			WARN,
			WARN_INFO,
			INFO,
			DEBUG,
			TRACE,
			NONE
		};

		enum struct Kind
		{
			LOGIC,
			RESOURCE,
			DEBUG_ASSERTION,
			CONCURRENCY,
			TIMEOUT,
			SECURITY,
			ENVIROMENTAL,
			INTEROP,
			CONFIGURATION,
			VALIDATION,
			OTHER
		};

		
	protected:
		const Level _Level;
		const Kind _Kind;

		const Compiler::Source::Location _Location;
		const Runtime::Reflection::Address _Address;

		const Clock::HighPrecisionTimestamp _Timestamp;

		const Exception* _InnerException;

		const std::wstring _Message;

	public:
		const inline constexpr Exception ();
		const inline constexpr Exception (const Level Level);
		const inline constexpr Exception (const Kind Kind);
		const inline constexpr Exception (const Level Level, const Kind Kind);
		const inline constexpr Exception (const Compiler::Source::Location& Location);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location);
		const inline constexpr Exception (const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Level Level, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Kind Kind, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address);
		const inline constexpr Exception (const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp);
		const inline constexpr Exception (const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Exception* InnerException);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Exception* InnerException);
		const inline constexpr Exception (const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException);
		const inline constexpr Exception (const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);
		const inline constexpr Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException);


	};
}

inline constexpr ION::Core::Exception::Exception () : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind) : _Level (Level), _Kind (Kind), _Location (), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location) : _Level (Level), _Kind (Kind), _Location (Location), _Address (), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Runtime::Reflection::Address& Address) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Runtime::Reflection::Address& Address) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Runtime::Reflection::Address& Address) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address) : _Level (Level), _Kind (Kind), _Location (), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address) : _Level (Level), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp) : _Level (Level), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (nullptr)
{}
inline constexpr ION::Core::Exception::Exception (const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (Location), _Address (), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (Location), _Address (), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind::OTHER), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level::FATAL), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}
inline constexpr ION::Core::Exception::Exception (const Level Level, const Kind Kind, const Compiler::Source::Location& Location, const Runtime::Reflection::Address& Address, const Clock::HighPrecisionTimestamp& Timestamp, const Exception* InnerException) : _Level (Level), _Kind (Kind), _Location (Location), _Address (Address), _Timestamp (Timestamp), _InnerException (InnerException)
{}