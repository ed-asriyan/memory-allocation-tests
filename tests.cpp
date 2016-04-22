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
	result.FreeTest.Empty   = empty.FreeTest();

	result.AllocTest.EmptyC  = emptyC.AllocateTest(count);
	result.FreeTest.EmptyC  = emptyC.FreeTest();

	result.AllocTest.EmptyD  = emptyD.AllocateTest(count);
	result.FreeTest.EmptyD  = emptyD.FreeTest();

	result.AllocTest.EmptyCD = emptyCD.AllocateTest(count);
	result.FreeTest.EmptyCD = emptyCD.FreeTest();


	result.AllocTest.Filled   = filled.AllocateTest(count);
	result.FreeTest.Filled   = filled.FreeTest();

	result.AllocTest.FilledC  = filledC.AllocateTest(count);
	result.FreeTest.FilledC  = filledC.FreeTest();

	result.AllocTest.FilledD  = filledD.AllocateTest(count);
	result.FreeTest.FilledD  = filledD.FreeTest();

	result.AllocTest.FilledCD = filledCD.AllocateTest(count);
	result.FreeTest.FilledCD = filledCD.FreeTest();

	result.count = count;

	return result;
}

// --- Drawing table -----------------------------------------------

const int COL1_WIDTH = 13;
const int COL2_WIDTH = 15;
const int COL3_WIDTH = 15;

const int WIDTH = COL1_WIDTH + COL2_WIDTH + COL3_WIDTH;

const char H = '-';
const char V = '|';
const char N = '+';

#include <iomanip>
template<typename T> void print(std::ostream& stream, const T& t, int width)
{
	stream << std::setw(width - 1) << t << ' ';
}

template<typename T> void repeatPrint(std::ostream& stream, const T& t, int count)
{
	for (int i = 0; i < count; i++){
		stream << t;
	}
}

void printHead(std::ostream& stream){
	stream << N;
	repeatPrint(stream, H, WIDTH + 2);
	stream << N << '\n';
}

void printSep(std::ostream& stream){
	stream << N;
	repeatPrint(stream, H, COL1_WIDTH);

	stream << N;
	repeatPrint(stream, H, COL2_WIDTH);

	stream << N;
	repeatPrint(stream, H, COL3_WIDTH);

	stream << N << '\n';
}

template<typename T1, typename T2, typename T3> void printRow(std::ostream& stream, const T1& t1, const T2& t2, const T3& t3){
	stream << V;
	print(stream, t1, COL1_WIDTH);

	stream << V;
	print(stream, t2, COL2_WIDTH);
	
	stream << V;
	print(stream, t3, COL3_WIDTH);

	stream << V << '\n';
	printSep(stream);
}

std::ostream& operator<<(std::ostream& stream, const TestResult& test){
	printHead(stream);
	stream << V << std::setw(WIDTH / 2 + 2) << test.count << std::setw(WIDTH / 2 + 2) << V << '\n';
	printHead(stream);
	printRow(stream, "Class", "Allocate", "Free");
	printRow(stream, "Empty", test.AllocTest.Empty, test.FreeTest.Empty);
	printRow(stream, "EmptyC", test.AllocTest.EmptyC, test.FreeTest.EmptyC);
	printRow(stream, "EmptyD", test.AllocTest.EmptyD, test.FreeTest.EmptyD);
	printRow(stream, "EmptyCD", test.AllocTest.EmptyCD, test.FreeTest.EmptyCD);
	printRow(stream, "Filled", test.AllocTest.Filled, test.FreeTest.Filled);
	printRow(stream, "FillesC", test.AllocTest.FilledC, test.FreeTest.FilledC);
	printRow(stream, "FilledD", test.AllocTest.FilledD, test.FreeTest.FilledD);
	printRow(stream, "FilledCD", test.AllocTest.FilledCD, test.FreeTest.FilledCD);

	return stream;
}
