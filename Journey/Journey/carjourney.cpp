#include "carjourney.h"

CarJourney::CarJourney(): Journey(new Car(), ""), journey_distance(0) {}

CarJourney::CarJourney(Car* car, const std::string& destination, double distance): Journey(car, destination), journey_distance(distance){}

CarJourney::CarJourney(const CarJourney& C): Journey(C.transport->clone(), C.destination), journey_distance(C.journey_distance){}

CarJourney::~CarJourney()
{
	delete transport;
}

CarJourney* CarJourney::clone() const
{
	return new CarJourney(*this);
}

double CarJourney::calculateCost() const
{
	return transport->calculateCost()*getDistance()/100;
}

void CarJourney::print() const
{
	std::cout << "Car Journey:" << std::endl;
	Journey::print();
	std::cout << "Cost: " << calculateCost() << std::endl;
}

double CarJourney::getDistance() const
{
	return journey_distance;
}

void CarJourney::readFrom(std::istream& in)
{
	if (transport == nullptr)
	{
		transport = new Car();
	}
	transport->readFrom(in);
	in >> destination >> journey_distance;
}
