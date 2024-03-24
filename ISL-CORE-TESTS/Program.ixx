export module ION.Tests.Program;

import std;
import ION.Tests.TestRunner;

export namespace ION::Tests
{
	static class Program
	{
	public:
		static const int Main ()
		{
			TestRunner* runner = new TestRunner ();
			runner->RunTests ();

			return 0;
		}
		static struct Environment
		{

		};
	};
}