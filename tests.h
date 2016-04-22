#ifndef TESTS_H
#define TESTS_H

#include <time.h>
#include <iostream>
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

#endif