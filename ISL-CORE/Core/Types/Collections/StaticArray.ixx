export module ION.Core.Types.Collections.StaticArray;

#include <cassert>

export import ION.Core.Object;
export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;

export namespace ION::Core::Types::Collections {
	template <
		typename T,
		int size
	>
	class StaticArray : public Object {
	public:
		constexpr inline StaticArray() {}

		constexpr inline ~StaticArray() {}

		inline virtual constexpr T& operator[](int Index) {
			assert(Index >= 0 && Index < size);
			return Elements[Index];
		}

		const constexpr inline int Size() {
			return size;
		}

	protected:
		T Elements[size];
	};
}
