export module ION.Core.Memory.Mallocator;

//import <memory.h>;
import std;
export import ION.Core.Object;
export import ION.Core.Memory.AllocationException;
export import ION.Core.Compiler.Source.Location;
export import ION.Core.Memory.BasicPointer;
export import ION.Core.Memory.Allocator;

export namespace ION::Core::Memory
{
	template <typename T>
	class Mallocator : public Object, Allocator<T>
	{
	public:
		Mallocator ()
		{}
		~Mallocator ()
		{}

		virtual constexpr T* Allocate () const override
		{
			T* ptr;
			try
			{
				ptr = (T*) std::malloc (sizeof (T));
			}
			catch (const std::exception&)
			{
				throw AllocationException (Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
			}
			if (!ptr)
			{
				throw AllocationException (Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
			}
			return ptr;
		}

		virtual constexpr T* Allocate (int Size) const override
		{
			T* ptr;
			try
			{
				ptr = (T*) std::malloc (sizeof (T) * Size);
			}
			catch (const std::bad_alloc&)
			{
				throw AllocationException (Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
			}
			if (!ptr)
			{
				throw AllocationException (Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
			}
			return ptr;
		}

		inline virtual const constexpr void DeAllocate (T* ptr) const override
		{
			std::free ((void*) ptr);
		}

		inline virtual const constexpr void DeAllocate (T* ptr, int size) const override
		{
			std::free ((void*) ptr);
		}

		inline virtual const constexpr void DeAllocate (BasicPointer<T>& ptr) const override
		{
			std::free ((void*) &(*ptr));
		}

		inline virtual const constexpr void DeAllocate (BasicPointer<T>& ptr, int size) const override
		{
			std::free ((void*) &(*ptr));
		}
	};
}