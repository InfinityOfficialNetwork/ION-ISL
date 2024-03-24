export module ION.Tests.TestRunner;

import ION.Tests.Types.Collections.StaticArrayTest;
import ION.Tests.Types.Collections.ArrayTest;
import ION.Tests.Types.Collections.BasicLinkedListTest;
import ION.Tests.Types.Collections.LinkedListTest;
import ION.Tests.TestBase;
import std;

export namespace ION::Tests
{
	class TestRunner
	{
		std::vector<TestBase*> Tests;

	public:
		void AddTest (TestBase* Test)
		{
			Tests.push_back (Test);
		}

		void RunTests ()
		{
			for (auto Test : Tests)
			{
				Test->Invoke ();
				std::cout << "TEST " << Test->Name << std::endl
					<< "	RESULTS: " << Test->SuccessCount () << " SUCCEDDED OF " << Test->TotalCount () << " TOTAL" << std::endl
					<< "	TEST DETAILS:" << std::endl;
				auto Results = Test->GetResults ();
				for (size_t i = 0; i < Results.size (); i++)
				{
					std::cout << "		SUBTEST " << i + 1 << ": " << ((Results[i].Code == TestBase::Result::ResultCode::SUCCESS) ? "SUCCESS" : "FAILURE") << std::endl;
					if (Results[i].Code == TestBase::Result::ResultCode::FAIL)
					{
						std::cout << "			SUBTEST DETAILS:" << std::endl
							<< "				" << Results[i].Exception.What () << std::endl
							<< "				" << Results[i].Exception.Where () << std::endl;
					}
				}
			}
		}

		TestRunner ()
		{
			//AddTest();
			AddTest (new ION::Tests::Types::Collections::StaticArrayTest ());
			AddTest (new ION::Tests::Types::Collections::ArrayTest ());
			AddTest (new ION::Tests::Types::Collections::BasicLinkedListTest ());
			AddTest (new ION::Tests::Types::Collections::LinkedListTest ());
		}
	};
}