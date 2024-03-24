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
		int NodeSize = 256,
		int KiloNodeSize = 256
	>
	class LinkedList : public Object
	{
	protected:
		class Node : public Object, public Array<T, Alloc>
		{
		public:
			Node () : Array<T, Alloc> (NodeSize)
			{}

			inline virtual constexpr T& operator[](int Index) override
			{
				return *(this->Elements[Index]);
			}
		};

		class KiloNode : public Object, public Array<Node, Alloc>
		{
		public:
			KiloNode () : Array<Node, Alloc> (KiloNodeSize), LastKiloNode (nullptr), NextKiloNode (nullptr), Index (-1)
			{

			}

			KiloNode* LastKiloNode;
			KiloNode* NextKiloNode;

			size_t Index;

			inline virtual constexpr Node& operator[](int Index) override
			{
				return *(this->Elements[Index]);
			}
		};

		KiloNode* StartKiloNode;
		KiloNode* FinalKiloNode;

		Node* StartNode;
		Node* FinalNode;

		size_t CurrentItems;
		size_t CurrentNodes;
		size_t CurrentKiloNodes;

		Alloc<Node> NodeAllocator;
		Alloc<KiloNode> KiloNodeAllocator;

		size_t INodeSize = NodeSize;
		size_t IKiloNodeSize = KiloNodeSize;

		KiloNode* AddKiloNode ()
		{
			FinalKiloNode->NextKiloNode = KiloNodeAllocator.Allocate ();
			FinalKiloNode->NextKiloNode->LastKiloNode = FinalKiloNode;
			FinalKiloNode = FinalKiloNode->NextKiloNode;
			FinalKiloNode->Index = CurrentKiloNodes;
			CurrentKiloNodes++;
			return FinalKiloNode;
		}

		Node* AddNode ()
		{
			if (CurrentNodes % IKiloNodeSize == 0)
			{
				AddKiloNode ();
			}
			Node* NewNode = &(*FinalKiloNode)[CurrentNodes % IKiloNodeSize];
			NewNode = NodeAllocator.Allocate ();
			FinalNode = NewNode;
			CurrentNodes++;
			return NewNode;
		}

	public:
		LinkedList () :
			StartKiloNode (nullptr),
			FinalKiloNode (nullptr),
			CurrentItems (0),
			CurrentNodes (0),
			CurrentKiloNodes (0),
			NodeAllocator (),
			KiloNodeAllocator ()
		{
			StartKiloNode = KiloNodeAllocator.Allocate ();
			FinalKiloNode = StartKiloNode;
			AddNode ();
		}

		T& GetItem (const size_t Index)
		{
			int KiloNodeIndex = Index / (INodeSize * IKiloNodeSize);
			int NodeIndex = Index / IKiloNodeSize;

			KiloNode* CurrentKiloNode = StartKiloNode;
			
			for (size_t i = 0; i < KiloNodeIndex; i++)
			{
				CurrentKiloNode = StartKiloNode->NextKiloNode;
			}

			Node* CurrentNode = &(*CurrentKiloNode)[NodeIndex % IKiloNodeSize];
			return (*CurrentNode)[Index % INodeSize];
		}

		LinkedList& AddItem (const T& Item)
		{
			Node* CurrentNode;
			if (CurrentItems % INodeSize == 0)
			{
				CurrentNode = AddNode ();
			}
			else
			{
				CurrentNode = FinalNode;
			}
			(*CurrentNode)[CurrentItems % INodeSize] = Item;
			return *this;
		}

		virtual inline constexpr LinkedList& operator+=(const T& Item)
		{
			return AddItem (Item);
		}

		virtual inline constexpr T& operator[](size_t Index)
		{
			return GetItem (Index);
		}
	};
}