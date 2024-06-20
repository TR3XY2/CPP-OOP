#pragma once
#include <iostream>

class Transport
{
public:
	virtual ~Transport();

	virtual void print() const abstract;
	virtual double calculateCost() const abstract;
	virtual Transport* clone() const abstract;
	virtual void readFrom(std::istream& in) abstract;
	virtual void writeTo(std::ostream& out) const abstract;
};

std::istream& operator>>(std::istream& in, Transport& T);
std::ostream& operator<<(std::ostream& out, const Transport& T);
