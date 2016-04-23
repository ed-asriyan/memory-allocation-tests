#include <iostream>
#include "tests.h"

int main(int argc, char* argv[]){
	std::cout << test(1, 1000000);

	testToFileForExcel("kek.txt", 0, 1000000, 1000, 10);


	return 0;
}