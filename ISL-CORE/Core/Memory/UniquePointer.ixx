export module ION.Core.Memory.UniquePointer;

export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;

export namespace ION::Core::Memory {
	template <typename T>
	class UniquePointer : public Object, BasicPointer<T> {
	public:
		const constexpr inline UniquePointer(T* instance, Allocator<T>* allocator) : BasicPointer(instance), DeAllocator(allocator) {}
		const constexpr inline UniquePointer(BasicPointer<T> instance, Allocator<T>* allocator) : BasicPointer(&(*instance)), DeAllocator(allocator) {}
		~UniquePointer() {
			DeAllocator->DeAllocate(this->Instance);
		}

		//inline T& operator*() {
		//	return *this->Instance;
		//}

	protected:
		Allocator<T>* DeAllocator;

	private:
		UniquePointer(const UniquePointer& o);
	};
}