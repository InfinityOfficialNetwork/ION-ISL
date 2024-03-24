export module ION.Core.Types.Collections.AdvancedLinkedList;

export import ION.Core.Object;
export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;
export import ION.Core.Types.Collections.Array;

export namespace ION::Core::Types::Collections
{
	template <
		typename T,
		template <typename> typename Alloc = ION::Core::Memory::Allocator,
		int KiloNodeSize = 16
	>
	class AdvancedLinkedList : public Object
	{
		class Node : public Object, public Array<T, Alloc>
		{

		};

		class KiloNode : public Object, public Array<T, Alloc>
		{

		};
	};
}