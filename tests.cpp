#include "tests.h"
#include <iomanip>
#include <fstream>

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

TestResult test(int count, int testsCount){
	TestResult result;

	result.AllocTest.Empty    = 0;
	result.AllocTest.EmptyC   = 0;
	result.AllocTest.EmptyD   = 0;
	result.AllocTest.EmptyCD  = 0;
	result.AllocTest.Filled   = 0;
	result.AllocTest.FilledC  = 0;
	result.AllocTest.FilledD  = 0;
	result.AllocTest.FilledCD = 0;

	result.FreeTest.Empty    = 0;
	result.FreeTest.EmptyC   = 0;
	result.FreeTest.EmptyD   = 0;
	result.FreeTest.EmptyCD  = 0;
	result.FreeTest.Filled   = 0;
	result.FreeTest.FilledC  = 0;
	result.FreeTest.FilledD  = 0;
	result.FreeTest.FilledCD = 0;

	for (int i = 0; i < testsCount; i++){
		auto t = test(count);

		result.AllocTest.Empty    += t.AllocTest.Empty;
		result.AllocTest.EmptyC   += t.AllocTest.EmptyC;
		result.AllocTest.EmptyD   += t.AllocTest.EmptyD;
		result.AllocTest.EmptyCD  += t.AllocTest.EmptyCD;
		result.AllocTest.Filled   += t.AllocTest.Filled;
		result.AllocTest.FilledC  += t.AllocTest.FilledC;
		result.AllocTest.FilledD  += t.AllocTest.FilledD;
		result.AllocTest.FilledCD += t.AllocTest.FilledCD;

		result.FreeTest.Empty    += t.FreeTest.Empty;
		result.FreeTest.EmptyC   += t.FreeTest.EmptyC;
		result.FreeTest.EmptyD   += t.FreeTest.EmptyD;
		result.FreeTest.EmptyCD  += t.FreeTest.EmptyCD;
		result.FreeTest.Filled   += t.FreeTest.Filled;
		result.FreeTest.FilledC  += t.FreeTest.FilledC;
		result.FreeTest.FilledD  += t.FreeTest.FilledD;
		result.FreeTest.FilledCD += t.FreeTest.FilledCD;
	}

	result.AllocTest.Empty    /= testsCount;
	result.AllocTest.EmptyC   /= testsCount;
	result.AllocTest.EmptyD   /= testsCount;
	result.AllocTest.EmptyCD  /= testsCount;
	result.AllocTest.Filled   /= testsCount;
	result.AllocTest.FilledC  /= testsCount;
	result.AllocTest.FilledD  /= testsCount;
	result.AllocTest.FilledCD /= testsCount;

	result.FreeTest.Empty    /= testsCount;
	result.FreeTest.EmptyC   /= testsCount;
	result.FreeTest.EmptyD   /= testsCount;
	result.FreeTest.EmptyCD  /= testsCount;
	result.FreeTest.Filled   /= testsCount;
	result.FreeTest.FilledC  /= testsCount;
	result.FreeTest.FilledD  /= testsCount;
	result.FreeTest.FilledCD /= testsCount;

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

// --- To file for excel -------------------------------------------

void testToFileForExcel(std::ostream& stream, int lowerCountBorder, int hightCountBorder, int step = 1, int testsCount = 1){
	const char SEP = '|';

	int count = (hightCountBorder - lowerCountBorder + 1) / step;

	TestResult* results = new TestResult[count];

	stream << "Name" << SEP;
	for (int i = lowerCountBorder, k = 0; i <= hightCountBorder; i += step, k++){
		results[k] = test(i, testsCount);
		stream << i << SEP;
	}

	// Allocation
	stream << "\nEmpty Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.Empty << SEP;
	}
	stream << "\nEmptyC Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.EmptyC << SEP;
	}
	stream << "\nEmptyD Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.EmptyD << SEP;
	}
	stream << "\nEmptyCD Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.EmptyCD << SEP;
	}
	stream << "\nFilled Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.Filled << SEP;
	}
	stream << "\nFilledC Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.FilledC << SEP;
	}
	stream << "\nFilledD Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.FilledD << SEP;
	}
	stream << "\nFilledCD Allocation" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].AllocTest.FilledCD << SEP;
	}


	// Free
	stream << "\nEmpty Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.Empty << SEP;
	}
	stream << "\nEmptyC Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.EmptyC << SEP;
	}
	stream << "\nEmptyD Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.EmptyD << SEP;
	}
	stream << "\nEmptyCD Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.EmptyCD << SEP;
	}
	stream << "\nFilled Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.Filled << SEP;
	}
	stream << "\nFilledC Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.FilledC << SEP;
	}
	stream << "\nFilledD Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.FilledD << SEP;
	}
	stream << "\nFilledCD Free" << SEP;
	for (int i = 0; i < count; i++){
		stream << results[i].FreeTest.FilledCD << SEP;
	}

	delete[] results;
}

void testToFileForExcel(const char* fileName, int lowerCountBorder, int hightCountBorder, int elemCount, int testsCount = 1){
	std::ofstream fStream(fileName);
	if (fStream.fail()){
		return;
	}
	testToFileForExcel(fStream, lowerCountBorder, hightCountBorder, elemCount, testsCount);
	fStream.close();
}