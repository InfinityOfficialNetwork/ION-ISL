export module ION.Core.Types.Collections.Array;

#include <cassert>

export import ION.Core.Object;
export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;

export namespace ION::Core::Types::Collections {
	template <
		typename T,
		typename ArrayAllocator = ION::Core::Memory::Allocator<T*>,
		typename ElementAllocator = ION::Core::Memory::Allocator<T>
	>
	class Array : public Object {
	public:
		constexpr inline Array(int size) : Size(size) {
			ArrayAlloc = ArrayAllocator();
			ElementAlloc = ElementAllocator();
			try
			{
				Elements = ArrayAlloc.Allocate(Size);
			}
			catch (const Memory::AllocationException& e)
			{
				throw e;
			}

			int AllocCnt = 0;
			for (size_t i = 0; i < Size; i++) try
			{
				Elements[i] = ElementAlloc.Allocate();
				AllocCnt++;
			}
			catch (const Memory::AllocationException& e)
			{
				for (size_t i = 0; i < AllocCnt; i++)
				{
					ElementAlloc.DeAllocate(Elements[i]);
				}
				ArrayAlloc.DeAllocate(Elements);
				throw e;
			}
		}

		constexpr inline ~Array() {
			for (size_t i = 0; i < Size; i++)
			{
				ElementAlloc.DeAllocate(Elements[i]);
			}
			ArrayAlloc.DeAllocate(Elements);
		}

		inline virtual constexpr T& operator[](int Index) {
			return *(Elements[Index]);
		}

	protected:
		int Size;
		ArrayAllocator ArrayAlloc;
		ElementAllocator ElementAlloc;
		T** Elements;

	};
}