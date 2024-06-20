#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
void print(const std::vector<T>& v, const char* delim = " ")
{
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<T>(std::cout, delim));
	std::cout << std::endl;
}

template <typename T>
void read(std::vector<T>& v, std::string fileName)
{
	std::ifstream fin(fileName);
	std::copy(std::istream_iterator<T>(fin), std::istream_iterator<T>(), std::back_inserter(v));
	fin.close();
}