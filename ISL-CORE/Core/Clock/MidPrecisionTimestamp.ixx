export module MidPrecisionTimestamp;

import ION.Core.Object;

export namespace ION::Core::Clock
{
	struct MidPrecisionTimestamp : public Object
	{
	public:
		const Int64 Seconds;
		const Int16 Miliseconds;

	public:
		const inline constexpr MidPrecisionTimestamp () noexcept : Seconds (0), Miliseconds (0)
		{}
		const inline constexpr MidPrecisionTimestamp (Int64 seconds) noexcept : Seconds (seconds), Miliseconds (0)
		{}
		const inline constexpr MidPrecisionTimestamp (Int64 seconds, Int16 miliseconds) noexcept : Seconds (seconds), Miliseconds (miliseconds)
		{}
	};
}