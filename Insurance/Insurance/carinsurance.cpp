#include "carinsurance.h"

CarInsurance::CarInsurance(): Insurance(), engine_capacity(0) {}

CarInsurance::CarInsurance(const CarInsurance& F)
   : Insurance(F.price), engine_capacity(F.engine_capacity) {}

CarInsurance::CarInsurance(double engine_capacity, double price)
   : Insurance(price), engine_capacity(engine_capacity) {}

void CarInsurance::print() const
{
	std::cout << "Car Insurance. Engine capacity: " << engine_capacity << ", Price: " << calculatePrice() << std::endl;
}

double CarInsurance::calculatePrice() const
{
	if (engine_capacity > 3.0)
	{
		return price * 1.25;
	}
	else if (engine_capacity > 2.0)
	{
		return price * 1.15;
	}
	return price;
}

void CarInsurance::readFrom(std::istream& in)
{
	in >> price >> engine_capacity;
}

void CarInsurance::writeTo(std::ostream& out) const
{
	out << price << ' ' << engine_capacity;
}

