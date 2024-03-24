export module ION.Core.Types.Collections.LinkedList;

export import ION.Core.Object;
export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;
export import ION.Core.Types.Collections.Array;

export namespace ION::Core::Types::Collections
{
	template <
		typename T,
		template <typename> typename Alloc = ION::Core::Memory::Allocator,
		int NodeSize = 16
	>
	class LinkedList : public Object
	{
		class Node : public Object, public Array<T, Alloc>
		{

		};

		class MegaNode : public Object, public Array<T, Alloc>
		{

		};
	};
}