#include <iostream>
#include <vector>
#include <stdexcept>
#include "functions.h"
#include "city.h"

// 1.1
int scalar(const std::vector<int>& v1, const std::vector<int>& v2)
{
	if (v1.size() != v2.size())
	{
		throw std::invalid_argument("Vectors sizes are not equal!");
	}

	int result = 0;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		result += v1[i] * v2[i];
	}

	return result;
}

// 1.2
std::vector<int> multVectorByMatrix(const std::vector<int>& v, const std::vector<std::vector<int>>& m)
{
	if (v.size() != m.size())
	{
		throw std::invalid_argument("Vector's size is not equal to number of rows in matrix!");
	}

	size_t rows = m.size();
	size_t cols = m[0].size();

	std::vector<int> result(cols);

	for (size_t i = 0; i < cols; ++i)
	{
		int sum = 0;
		for (size_t j = 0; j < rows; ++j)
		{
			sum += v[j] * m[j][i];
		}
		result[i] = sum;
	}

	return result;
}

int totalPopulation(const std::vector<City>& cities)
{
	int total = 0;
	for (const auto& city : cities)
	{
		total += city.getPopulation();
	}
	return total;
}

int main()
{
	// 1.1
	std::vector<int> v11 = { 1, 2, 3 };
	std::vector<int> v12 = { 2, 2, 2 };
	
	try
	{
		int result1 = scalar(v11, v12);
		std::cout << "Scaral of vectors (1,2,3) and (2,2,2) is " << result1 << std::endl;
	}
	catch (const std::invalid_argument& error)
	{
		std::cerr << error.what() << std::endl;
	}
	// 1.2
	std::vector<int> v21 = { 2, 2, 2 };
	std::vector<std::vector<int>> m21 = {{ 1, 4 },
										 { 2, 5 },
										 { 3, 6 }};
	try
	{
		std::vector<int> result2 = multVectorByMatrix(v21, m21);
		std::cout << "Result of multiplication of vector v21 by matrix m21 is: ";
		for (size_t i = 0; i < result2.size(); ++i)
		{
			std::cout << result2[i] << ' ';
		}
		std::cout << std::endl << std::endl;
	}
	catch (const std::invalid_argument& error)
	{
		std::cerr << error.what() << std::endl;
	}

	// 2
	std::vector<City> cities1, cities2, cities3;
	read(cities1, "cities1.txt");
	read(cities2, "cities2.txt");
	read(cities3, "cities3.txt");

	std::cout << "Cities 1: " << std::endl;
	print(cities1, "\n");
	std::cout << "Cities 2: " << std::endl;
	print(cities2, "\n");
	std::cout << "Cities 3: " << std::endl;
	print(cities3, "\n");

	cities1.insert(cities1.begin(), cities2.begin(), cities2.end());
	cities1.insert(cities1.end(), cities3.begin(), cities3.end());
	std::cout << "Cities 1 after adding cities 2 and cities 3 before sorting: " << std::endl;
	print(cities1, "\n");
	std::sort(cities1.begin(), cities1.end());
	std::cout << "After sorting: " << std::endl;
	print(cities1, "\n");

	std::vector<std::pair<std::string, std::vector<City>>> countries;
	for (size_t i = 0; i < cities1.size(); ++i)
	{
		std::string country = cities1[i].getCountry();

		bool added = false;
		for (size_t j = 0; j < countries.size(); ++j)
		{
			if (countries[j].first == country)
			{
				countries[j].second.push_back(cities1[i]);
				added = true;
				break;
			}
		}

		if (!added)
		{
			countries.push_back(std::make_pair(country, std::vector<City>({ cities1[i] })));
		}
	}

	std::cout << "CITIES FROM DIFFERENT COUNTRIES:" << std::endl;
	for (size_t i = 0; i < countries.size(); ++i)
	{
		std::cout << "Cities from " << countries[i].first << ":\n";
		std::cout << "Total Population is " << totalPopulation(countries[i].second) << std::endl;
		print(countries[i].second, "\n");
	}
	return 0;
}