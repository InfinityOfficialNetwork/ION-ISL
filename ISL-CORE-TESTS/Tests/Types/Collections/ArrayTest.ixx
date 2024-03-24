export module ION.Tests.Types.Collections.ArrayTest;

import std;
export import ION.Tests.TestBase;
export import ION.Core.Types.Collections.Array;

export namespace ION::Tests::Types::Collections {
	class ArrayTest : public TestBase {
	public:
		ArrayTest() : TestBase()
		{
			this->Name = "ION.Core.Types.Collections.ArrayTest";
			this->AddTest(new SmallSet1());
			this->AddTest(new SmallSet2());
			this->AddTest(new LargeSet1());
		}

		class SmallSet1 : public TestBase::Test {
			virtual Result Invoke() override try {
				ION::Core::Types::Collections::Array<int> a(100);
				for (size_t i = 0; i < 100; i++) {
					a[i] = i;
				}
				for (size_t i = 0; i < 100; i++) {
					if (a[i] != i) {
						throw ION::Core::Exception("VALIDATION_FAILURE");
					}
				}
				return Result(Result::ResultCode::SUCCESS, ION::Core::Exception("NO_ERROR"));
			}
			catch (const ION::Core::Exception& e) {
				return Result(Result::ResultCode::FAIL, e);
			}
			catch (const std::exception& e) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception(e.what()));
			}
			catch (const char* e) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception(std::string(e)));
			}
			catch (...) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception("UNKNOWN_ERROR"));
			}
		};

		class SmallSet2 : public TestBase::Test {
			virtual Result Invoke() override try {
				ION::Core::Types::Collections::Array<int> a(100);
				for (size_t i = 0; i < 100; i++) {
					a[i] = i*541;
				}
				for (size_t i = 0; i < 100; i++) {
					if (a[i] != i*541) {
						throw ION::Core::Exception("VALIDATION_FAILURE");
					}
				}
				return Result(Result::ResultCode::SUCCESS, ION::Core::Exception("NO_ERROR"));
			}
			catch (const ION::Core::Exception& e) {
				return Result(Result::ResultCode::FAIL, e);
			}
			catch (const std::exception& e) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception(e.what()));
			}
			catch (const char* e) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception(std::string(e)));
			}
			catch (...) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception("UNKNOWN_ERROR"));
			}
		};

		class LargeSet1 : public TestBase::Test {
			virtual Result Invoke() override try {
				ION::Core::Types::Collections::Array<int> a(1000000);
				for (size_t i = 0; i < 1000000; i++) {
					a[i] = i;
				}
				for (size_t i = 0; i < 1000000; i++) {
					if (a[i] != i) {
						throw ION::Core::Exception("VALIDATION_FAILURE");
					}
				}
				return Result(Result::ResultCode::SUCCESS, ION::Core::Exception("NO_ERROR"));
			}
			catch (const ION::Core::Exception& e) {
				return Result(Result::ResultCode::FAIL, e);
			}
			catch (const std::exception& e) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception(e.what()));
			}
			catch (const char* e) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception(std::string(e)));
			}
			catch (...) {
				return Result(Result::ResultCode::FAIL, ION::Core::Exception("UNKNOWN_ERROR"));
			}
		};
	};
}