export module ION.Core.Memory.Allocator;

import std;
export import ION.Core.Object;
export import ION.Core.Memory.AllocationException;
export import ION.Core.Compiler.Source.Location;
export import ION.Core.Memory.BasicPointer;

export namespace ION::Core::Memory {
	template <typename T>
	class Allocator : public Object {
	public:
		Allocator() {}
		~Allocator() {}

		virtual constexpr T* Allocate() const {
			T* ptr;
			try
			{
				ptr = new T;
			}
			catch (const std::exception&)
			{
				throw AllocationException(Compiler::Source::Location(__FUNCSIG__, __FILE__, __LINE__));
			}
			if (!ptr) 
			{
				throw AllocationException(Compiler::Source::Location(__FUNCSIG__, __FILE__, __LINE__));
			}
			return ptr;
		}

		virtual constexpr T* Allocate(int Size) const {
			T* ptr;
			try
			{
				ptr = new T[Size];
			}
			catch (const std::bad_alloc&)
			{
				throw AllocationException(Compiler::Source::Location(__FUNCSIG__, __FILE__, __LINE__));
			}
			if (!ptr) 
			{
				throw AllocationException(Compiler::Source::Location(__FUNCSIG__, __FILE__, __LINE__));
			}
			return ptr;
		}

		inline virtual const constexpr void DeAllocate(T* ptr) const {
			delete ptr;
		}

		inline virtual const constexpr void DeAllocate(T* ptr, int size) const {
			delete[] ptr;
		}

		inline virtual const constexpr void DeAllocate(BasicPointer<T>& ptr) const {
			delete &(*ptr);
			ptr = nullptr;
		}

		inline virtual const constexpr void DeAllocate(BasicPointer<T>& ptr, int size) const {
			delete[] &(*ptr);
		}
	};
}