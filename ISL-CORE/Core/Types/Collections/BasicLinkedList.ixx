export module ION.Core.Types.Collections.BasicLinkedList;

export import ION.Core.Object;
export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;
export import ION.Core.Types.Collections.StaticArray;

export namespace ION::Core::Types::Collections
{
	template <
		typename T,
		template <typename> typename Allocator = ION::Core::Memory::Allocator,
		int NodeSize = 16
	>
	class BasicLinkedList : public Object
	{
		class Node : public Object, public StaticArray<T, NodeSize>
		{
		public:
			size_t Index;
			Memory::BasicPointer<Node> PreviousNode = nullptr;
			Memory::BasicPointer<Node> NextNode = nullptr;

			inline constexpr Node ()
			{
				StaticArray<T, NodeSize> ();
			}
		};

		const int nodeSize = NodeSize;

		Memory::BasicPointer<Node> StartNode;

		//optimization for AddNode
		Memory::BasicPointer<Node> LastNode;
		Memory::BasicPointer<Node> QuickNode;

		Memory::Allocator<Node> NodeAllocator;
		size_t CurrentLength = 0;

		virtual constexpr void AddNode ()
		{
			Memory::BasicPointer<Node> CurrentNode;
			CurrentNode = LastNode;
			while (!CurrentNode->NextNode.Null ())
			{
				CurrentNode = CurrentNode->NextNode;
			}
			CurrentNode->NextNode = NodeAllocator.Allocate ();
			CurrentNode->PreviousNode = LastNode;
			CurrentNode->Index = CurrentLength / nodeSize;
			LastNode = CurrentNode;
		}

	public:
		inline constexpr BasicLinkedList ()
		{
			NodeAllocator = Memory::Allocator<Node> ();
			StartNode = NodeAllocator.Allocate ();
			*StartNode = Node ();
			LastNode = StartNode;
			QuickNode = StartNode;
		}

		~BasicLinkedList ()
		{
			Memory::BasicPointer<Node> CurrentNode = LastNode;
			while (CurrentNode->Index > 0)
			{
				CurrentNode = CurrentNode->PreviousNode;
				NodeAllocator.DeAllocate (CurrentNode->NextNode);
			}
			NodeAllocator.DeAllocate (StartNode);
		}

		virtual const int inline constexpr Length ()
		{
			return CurrentLength;
		}

		virtual inline constexpr BasicLinkedList& operator+=(const T& Item)
		{
			if (CurrentLength % nodeSize == 0)
			{
				AddNode ();
			}
			Memory::BasicPointer<Node> CurrentNode = LastNode;

			(*CurrentNode)[CurrentLength % nodeSize] = Item;
			CurrentLength++;
			return *this;
		}

		virtual inline constexpr T& operator[](size_t Index)
		{
			Memory::BasicPointer<Node> CurrentNode;
			if (QuickNode->Index == (Index / nodeSize))
			{
				CurrentNode = QuickNode;
			}
			else
			{
				CurrentNode = StartNode;
				for (size_t i = 0; i + nodeSize <= Index; i += nodeSize)
				{
					CurrentNode = CurrentNode->NextNode;
				}
			}
			QuickNode = CurrentNode;
			return (*CurrentNode)[Index % nodeSize];
		}

		virtual inline const constexpr void AddItem (const T& Item)
		{
			(*this) += Item;
		}



		virtual inline constexpr T& Index (size_t index)
		{
			return (*this)[index];
		}
	};
}