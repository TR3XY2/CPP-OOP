#include "car.h"

Car::Car(): brand(""), consumption_per_100km(10){}

Car::Car(const std::string& brand, double consumption): brand(brand), consumption_per_100km(consumption){}

Car::Car(const Car& C): brand(C.brand), consumption_per_100km(C.consumption_per_100km){}

Car::~Car(){}

std::string Car::getBrand() const
{
	return brand;
}

void Car::print() const
{
	std::cout << "Car brand: " << brand << ", Consumption: " << consumption_per_100km << std::endl;
}

double Car::calculateCost() const
{
	return consumption_per_100km * 40;
}

Car* Car::clone() const
{
	return new Car(*this);
}

void Car::readFrom(std::istream& in)
{
	in >> brand >> consumption_per_100km;
}

void Car::writeTo(std::ostream& out) const
{
	out << brand << ' ' << consumption_per_100km;
}
