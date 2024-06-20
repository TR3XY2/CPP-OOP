#include "insurance.h"
#include <string>
#include "familyinsurance.h"
#include "carinsurance.h"

Insurance::Insurance(): price(0) {}

Insurance::Insurance(double price): price(price) {}

Insurance::~Insurance() {}

bool Insurance::operator<(const Insurance& I) const
{
	return calculatePrice() < I.calculatePrice();
}

bool Insurance::operator>(const Insurance& I) const
{
	return calculatePrice() > I.calculatePrice();
}

std::istream& operator>>(std::istream& in, Insurance& I)
{
	I.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, Insurance& I)
{
	I.writeTo(out);
	return out;
}

Insurance** readInsurances(std::istream& in, size_t n)
{
	Insurance** arr = new Insurance * [n];
	char type;
	for (size_t i = 0; i < n; ++i)
	{
		in >> type;
		switch (type)
		{
		case 'F':
			arr[i] = new FamilyInsurance();
			in >> *arr[i];
			break;
		case 'C':
			arr[i] = new CarInsurance();
			in >> *arr[i];
			break;
		}
		// можна тут добавити виняток , якщо не знайшло тип
	}
	return arr;
}

void printInsurances(Insurance** arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		arr[i]->print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

double totalPrice(Insurance** arr, size_t n)
{
	double total = 0;
	for (size_t i = 0; i < n; ++i)
	{
		total += arr[i]->calculatePrice();
	}
	return total;
}

Insurance* findMinPrice(Insurance** arr, size_t n)
{
	Insurance* min = arr[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (*arr[i] < *min)
		{
			min = arr[i];
		}
	}
	return min;
}

Insurance* findMaxPrice(Insurance** arr, size_t n)
{
	Insurance* max = arr[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (*arr[i] > *max)
		{
			max = arr[i];
		}
	}
	return max;
}