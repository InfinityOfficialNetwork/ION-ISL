export module ION.Core.Memory.SharedPointer;

export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;

export namespace ION::Core::Memory {
	template <typename T>
	class SharedPointer : public Object, BasicPointer<T> {
	public:
		const constexpr inline SharedPointer(T* instance, Allocator<T>* deAllocator) : BasicPointer<T>(instance), DeAllocator(deAllocator)
		{
			Control.ReferenceCount = 0;
			ControlRef = &Control;
		}
		const constexpr inline SharedPointer(BasicPointer<T> ptr, Allocator<T>* deAllocator) : BasicPointer<T>(&(*ptr)), DeAllocator(deAllocator)
		{
			Control.ReferenceCount = 0;
			ControlRef = &Control;
		}
		~SharedPointer() {
			if (Control->ReferenceCount == 0) {
				DeAllocator->DeAllocate(this->Instance);
			}
		}

		//inline T& operator*() {
		//	return *this->Instance;
		//}

	protected:
		Allocator<T>* DeAllocator;

		struct ControlBlock : public Object {
			int ReferenceCount = 0;
		};

		ControlBlock* ControlRef;

		ControlBlock Control;

	private:
		SharedPointer(const SharedPointer& o);
	};
}