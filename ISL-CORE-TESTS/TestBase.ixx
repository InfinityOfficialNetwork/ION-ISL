export module ION.Tests.TestBase;

import ION.Core.Exception;
import std;

export namespace ION::Tests {
	class TestBase {
	public:
		void Invoke() {
			for (const auto& Test : Tests) {
				Results.push_back(Test->Invoke());
			}
		}

		std::string Name;

		size_t SuccessCount() {
			size_t count = 0;
			for (const auto& Result : Results) {
				if (Result.Code == Result::ResultCode::SUCCESS) {
					count++;
				}
			}
			return count;
		}
		size_t FailCount() {
			size_t count = 0;
			for (const auto& Result : Results) {
				if (Result.Code == Result::ResultCode::FAIL) {
					count++;
				}
			}
			return count;
		}
		size_t TotalCount() {
			size_t count = 0;
			for (const auto& Result : Results) {
				count++;
			}
			return count;
		}

	public:
		struct Result {
			enum class ResultCode {
				SUCCESS,
				FAIL
			} Code;
			const ION::Core::Exception Exception;

			Result(ResultCode c, const ION::Core::Exception e) : Code(c), Exception(e) {}
		};
		struct Test {
			virtual Result Invoke() = 0;
		};

	protected:
		std::vector<Test*> Tests = {};
		std::vector<Result> Results = {};

		TestBase() {}

		void AddTest(Test* t) {
			Tests.push_back(t);
		}

	public:
		const std::vector<Result>& GetResults() {
			return Results;
		}
	};
}