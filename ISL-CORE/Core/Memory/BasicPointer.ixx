export module ION.Core.Memory.BasicPointer;

#include <cassert>

export namespace ION::Core::Memory {
	template <typename T>
	class BasicPointer {
	protected:
		T* Instance;
	public:
		constexpr inline BasicPointer(std::nullptr_t instance) : Instance((T*)instance) {}
		constexpr inline BasicPointer(void* instance) : Instance((T*)instance) {}
		constexpr inline BasicPointer(T* instance) : Instance(instance) {}
		constexpr inline BasicPointer(const BasicPointer& o) : Instance(o.Instance) {}
		constexpr inline BasicPointer() : Instance(nullptr) {}

		// Obtain the refrenced object
		// Dereference operator could expose raw pointer, USE WITH CAUTION
		constexpr virtual inline T& operator*() {
			assert(Instance);
			return *Instance;
		}

		constexpr virtual inline T* operator->() const {
			assert(Instance);
			return Instance;
		}

		constexpr virtual inline void operator=(const BasicPointer& rhs) {
			Instance = rhs.Instance;
		}

		constexpr virtual inline void operator=(const void* rhs) {
			Instance = (T*)rhs;
		}

		constexpr const virtual inline bool Null() {
			return (!Instance);
		}
	};
}