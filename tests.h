#ifndef TESTS_H
#define TESTS_H

#include <time.h>
#include <iomanip>
#include <fstream>

#include "classes/tester.h"
#include "classes/core.h"

struct MemoryTestResult{
	clock_t Empty;
	clock_t EmptyC;
	clock_t EmptyD;
	clock_t EmptyCD;

	clock_t Filled;
	clock_t FilledC;
	clock_t FilledD;
	clock_t FilledCD;
};

struct TestResult{
	MemoryTestResult AllocTest;
	MemoryTestResult FreeTest;

	int count;
};

TestResult test(int count);
TestResult test(int count, int testCount);

void testToFileForExcel(const char* fileName, int lowerCountBorder, int hightCountBorder, int step = 1, int testsCount = 1);
void testToFileForExcel(std::ostream& stream, int lowerCountBorder, int hightCountBorder, int step = 1, int testsCount = 1);

std::ostream& operator<<(std::ostream&, const TestResult&);

#endif