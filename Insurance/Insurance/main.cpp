#include <iostream>
#include <fstream>
#include "insurance.h"
int main()
{
	size_t n;
	std::ifstream fin("data.txt");
	fin >> n;
	Insurance** arr = readInsurances(fin, n);
	printInsurances(arr, n);
	std::cout << "Total price: " << totalPrice(arr, n) << std::endl;
	std::cout << "Lowest price: " << std::endl;
	findMinPrice(arr, n)->print();
	std::cout << "Highest price: " << std::endl;
	findMaxPrice(arr, n)->print();
	
	
	return 0;
}