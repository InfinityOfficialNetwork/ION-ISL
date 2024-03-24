export module ION.Tests.Types.Collections.LinkedListTest;

import std;
export import ION.Tests.TestBase;
export import ION.Core.Types.Collections.LinkedList;

export namespace ION::Tests::Types::Collections
{
	class LinkedListTest : public TestBase
	{
	public:
		LinkedListTest () : TestBase ()
		{
			this->Name = "ION.Core.Types.Collections.ArrayTest";
			this->AddTest (new SmallSet1 ());
			this->AddTest (new SmallSet2 ());
			//this->AddTest (new LargeSet1 ());
		}

		class SmallSet1 : public TestBase::Test
		{
			virtual Result Invoke () override try
			{
				{
					//BEGIN TEST

					ION::Core::Types::Collections::LinkedList<int> TestItem;

					for (size_t i = 0; i < 100; i++)
					{
						TestItem += i;
					}

					for (size_t i = 0; i < 100; i++)
					{
						if (TestItem[i] != i)
						{
							throw ION::Core::Exception ("VALIDATION_FAILURE", ION::Core::Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
						}
					}

					//END TEST
				}
				return Result (Result::ResultCode::SUCCESS, ION::Core::Exception ("NO_ERROR"));
			}
			catch (const ION::Core::Exception& e)
			{
				return Result (Result::ResultCode::FAIL, e);
			}
			catch (const std::exception& e)
			{
				return Result (Result::ResultCode::FAIL, ION::Core::Exception (e.what ()));
			}
			catch (const char* e)
			{
				return Result (Result::ResultCode::FAIL, ION::Core::Exception (std::string (e)));
			}
			catch (...)
			{
				return Result (Result::ResultCode::FAIL, ION::Core::Exception ("UNKNOWN_ERROR"));
			}
		};

		class SmallSet2 : public TestBase::Test
		{
			virtual Result Invoke () override try
			{
				{
					//BEGIN TEST

					ION::Core::Types::Collections::LinkedList<int> TestItem;

					for (size_t i = 0; i < 100; i++)
					{
						TestItem += i * 945;
					}

					for (size_t i = 0; i < 100; i++)
					{
						if (TestItem[i] != i * 945)
						{
							throw ION::Core::Exception ("VALIDATION_FAILURE", ION::Core::Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
						}
					}

					//END TEST
				}
				return Result (Result::ResultCode::SUCCESS, ION::Core::Exception ("NO_ERROR"));
			}
			catch (const ION::Core::Exception& e)
			{
				return Result (Result::ResultCode::FAIL, e);
			}
			catch (const std::exception& e)
			{
				return Result (Result::ResultCode::FAIL, ION::Core::Exception (e.what ()));
			}
			catch (const char* e)
			{
				return Result (Result::ResultCode::FAIL, ION::Core::Exception (std::string (e)));
			}
			catch (...)
			{
				return Result (Result::ResultCode::FAIL, ION::Core::Exception ("UNKNOWN_ERROR"));
			}
		};

		//class LargeSet1 : public TestBase::Test
		//{
		//	virtual Result Invoke () override try
		//	{
		//		{
		//			//BEGIN TEST

		//			const int KiloNodeSize = 1024 * 16;
		//			const int MaxSize = 1'000'000;
		//			ION::Core::Types::Collections::LinkedList<int, Core::Memory::Allocator, KiloNodeSize> TestItem;

		//			for (size_t i = 0; i < MaxSize; i++)
		//			{
		//				TestItem += i;
		//			}

		//			for (size_t i = 0; i < MaxSize; i++)
		//			{
		//				if (TestItem[i] != i)
		//				{
		//					throw ION::Core::Exception ("VALIDATION_FAILURE", ION::Core::Compiler::Source::Location (__FUNCSIG__, __FILE__, __LINE__));
		//				}
		//			}

		//			//TestItem.~BasicLinkedList();

		//			int i;

		//			//END TEST
		//		}
		//		return Result (Result::ResultCode::SUCCESS, ION::Core::Exception ("NO_ERROR"));
		//	}
		//	catch (const ION::Core::Exception& e)
		//	{
		//		return Result (Result::ResultCode::FAIL, e);
		//	}
		//	catch (const std::exception& e)
		//	{
		//		return Result (Result::ResultCode::FAIL, ION::Core::Exception (e.what ()));
		//	}
		//	catch (const char* e)
		//	{
		//		return Result (Result::ResultCode::FAIL, ION::Core::Exception (std::string (e)));
		//	}
		//	catch (...)
		//	{
		//		return Result (Result::ResultCode::FAIL, ION::Core::Exception ("UNKNOWN_ERROR"));
		//	}
		//};

	};
}