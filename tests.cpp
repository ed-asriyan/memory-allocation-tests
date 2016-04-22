#include "tests.h"

TestResult test(int count){
	Tester<Empty>   empty;
	Tester<EmptyC>  emptyC;
	Tester<EmptyD>  emptyD;
	Tester<EmptyCD> emptyCD;

	Tester<Filled>   filled;
	Tester<FilledC>  filledC;
	Tester<FilledD>  filledD;
	Tester<FilledCD> filledCD;

	TestResult result;
	
	result.AllocTest.Empty   = empty.AllocateTest(count);
	result.AllocTest.EmptyC  = emptyC.AllocateTest(count);
	result.AllocTest.EmptyD  = emptyD.AllocateTest(count);
	result.AllocTest.EmptyCD = emptyCD.AllocateTest(count);

	result.FreeTest.Empty   = empty.FreeTest();
	result.FreeTest.EmptyC  = emptyC.FreeTest();
	result.FreeTest.EmptyD  = emptyD.FreeTest();
	result.FreeTest.EmptyCD = emptyCD.FreeTest();

	result.count = count;

	return result;
}
