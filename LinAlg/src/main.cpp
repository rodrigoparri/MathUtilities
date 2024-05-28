#include "Matrix.h"
#include <iostream>

int main() {
	Matrix mymatrix(3, 3);
	mymatrix.set(2, 1, 9.7);

	std::cout << mymatrix << std::endl;
	std::cin.get();

	return 0;
}