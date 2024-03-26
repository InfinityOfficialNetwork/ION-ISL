export module LowPrecisionTimestamp;

import ION.Core.Object;

export namespace ION::Core::Clock
{
	struct LowPrecisionTimestamp : public Object
	{
	public:
		const Int64 Seconds;

	public:
		const inline constexpr LowPrecisionTimestamp () noexcept : Seconds (0)
		{}
	};
}