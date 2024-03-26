export module ION.Core.Clock.HighPrecisionTimestamp;

import ION.Core.Object;

export namespace ION::Core::Clock
{
	struct HighPrecisionTimestamp : public Object
	{
	public:
		const Int64 Seconds;
		const Int32 Nanoseconds;

	public:
		const inline constexpr HighPrecisionTimestamp () noexcept : Seconds (0), Nanoseconds (0)
		{}
		const inline constexpr HighPrecisionTimestamp (Int64 seconds) noexcept : Seconds (seconds), Nanoseconds (0)
		{}
		const inline constexpr HighPrecisionTimestamp (Int64 seconds, Int32 nanoseconds) noexcept : Seconds (seconds), Nanoseconds (nanoseconds)
		{}
	};
}