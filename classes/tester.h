#ifndef TEST_H
#define TEST_H

#include <time.h>

template<class T> class Tester
{
private:
	T* items;
	int itemCount;

public:
	// Constructors & Destructors
	Tester(){
		items     = nullptr;
		itemCount = 0;
	}

	~Tester(){
		FreeTest();
	}

	// Public Methods
	bool IsFilled(){
		return items;
	}

	// Tester Methods
	clock_t AllocateTest(int count){
		if (count <= 0) return 0;

		if (items){
			delete[] items;
		}

		clock_t begin = clock();
		items = new T[count];
		clock_t end = clock();

		return end - begin;
	}

	clock_t FreeTest(){
		if (!items) return 0;

		clock_t begin = clock();
		delete[] items;
		clock_t end = clock();

		items = nullptr;

		return end - begin;
	}
};

#endif