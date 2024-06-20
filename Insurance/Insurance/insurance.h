#pragma once
#include <iostream>

class Insurance
{
protected:
	double price;
public:
	Insurance();
	Insurance(double price);
	virtual ~Insurance();

	virtual void print() const abstract;
	virtual double calculatePrice() const abstract;
	virtual void readFrom(std::istream& in) abstract;
	virtual void writeTo(std::ostream& out) const abstract;

	bool operator<(const Insurance& I) const;
	bool operator>(const Insurance& I) const;
};

std::istream& operator>>(std::istream& in, Insurance& I);
std::ostream& operator<<(std::ostream& out, Insurance& I);

Insurance** readInsurances(std::istream& in, size_t n);
void printInsurances(Insurance** arr, size_t n);
double totalPrice(Insurance** arr, size_t n);
Insurance* findMinPrice(Insurance** arr, size_t n);
Insurance* findMaxPrice(Insurance** arr, size_t n);
