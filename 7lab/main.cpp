#include<iostream>
#include"TMatrix.h" 
#include<time.h>
#include"FractionalNumber.h"

int main() {
	srand(time(NULL));
	TMatrix<FractionalNumber> matr;
	FractionalNumber a(1, 2);
	FractionalNumber b(14, 6);
//	matr.generateRandomValues(2, 6, a, b);
	std::cin >> matr;
	std::cout << matr;
	std::cout << matr.getAverageLeftHalf() << std::endl;

	std::cout << matr.getSumBelowAverageLeftHalf() << std::endl;
	std::cout << matr.getMaxInMin() << std::endl;
//	std::cout << matr[7][0];	



	return 0;
}