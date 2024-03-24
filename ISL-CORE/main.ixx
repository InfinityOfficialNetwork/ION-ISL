export module main;

// ISL-CORE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>

import std;
export import ION.Core.Object;
export import ION.Core.Exception;
export import ION.Core.Compiler.Source.Location;
export import ION.Core.Memory.AllocationException;
export import ION.Core.Memory.Allocator;
export import ION.Core.Memory.BasicPointer;
export import ION.Core.Memory.Mallocator;
export import ION.Core.Memory.SharedPointer;
export import ION.Core.Memory.SharedPointer;
export import ION.Core.Memory.UniquePointer;
export import ION.Core.Types.Functor;
export import ION.Core.Types.Collections.Array;
export import ION.Core.Types.Collections.BasicLinkedList;
export import ION.Core.Types.Collections.StaticArray;

export int main ()
{
	ION::Core::Types::Collections::BasicLinkedList<int> list;

	for (int i = 0; i < 10000; i++)
	{
		//list.AddItem(i);
		list.AddItem (i);
	}

	for (int i = 0; i < 10000; i++)
	{
		assert (list[i] == i);
	}

	std::cout << "Hello World!\n";

	//std::shared_ptr<int> a;
}

ION::Core::Types::Functor Main (main);