#include "Matrix.h"
#include <iostream>

int main() {
	Matrix mymatrix(3, 3);

	mymatrix.set(2, 1, 9.7);
	std::cout << mymatrix << std::endl;

	mymatrix.value(2, 1) = 3.8;
	std::cout << mymatrix << std::endl;

	double value = mymatrix.value(2, 1);
	std::cout << value << std::endl;
	
	std::cin.get();

	return 0;
}