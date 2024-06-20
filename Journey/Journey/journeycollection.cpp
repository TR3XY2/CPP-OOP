#include "journeycollection.h"
#include <fstream>
#include <string>

JourneyCollection::JourneyCollection(): capacity(10), journeys(new Journey*[capacity]), size(0) {}

JourneyCollection::JourneyCollection(const JourneyCollection& J): capacity(J.capacity), size(J.size), journeys(new Journey*[capacity])
{
	for (size_t i = 0; i < size; ++i)
	{
		journeys[i] = J.journeys[i]->clone();
	}
}

JourneyCollection::~JourneyCollection()
{
	clear();
	delete journeys;
}

void JourneyCollection::checkMem()
{
	if (size < capacity)
	{
		return;
	}
	size_t newCapacity = capacity * 2;
	Journey** newJourneys = new Journey * [newCapacity];
	for (size_t i = 0; i < size; ++i)
	{
		newJourneys[i] = journeys[i];
	}
	delete[] journeys;
	journeys = newJourneys;
}

void JourneyCollection::clear()
{
	for (size_t i = 0; i < size; ++i)
	{
		delete journeys[i];
	}
	size = 0;
}

void JourneyCollection::print()
{
	std::cout << "JOURNEYS:" << std::endl;
	for (size_t i = 0; i < size; ++i)
	{
		journeys[i]->print();
	}
}

void JourneyCollection::add(Journey* journey)
{
	checkMem();
	journeys[size] = journey->clone();
	++size;
}

void JourneyCollection::readFrom(std::istream& in, size_t n)
{
	clear();
	for (size_t i = 0; i < n; ++i)
	{
		char type;
		in >> type;
		Journey* newJourney;
		if (type == 'C')
		{
			newJourney = new CarJourney();
			newJourney->readFrom(in);
		}
		else if (type == 'F')
		{
			newJourney = new FamilySeaVacation();
			newJourney->readFrom(in);
		}
		else
		{
			std::cout << "INVALID DATA!" << std::endl;
			std::string line;
			std::getline(in, line);
			continue;
		}
		add(newJourney);
	}
}

double JourneyCollection::calculateTotalCost() const
{
	double total = 0;
	for (size_t i = 0; i < size; ++i)
	{
		total += journeys[i]->calculateCost();
	}
	return total;
}

Journey* JourneyCollection::mostExpensiveCarJourney() const
{
	double maxCost = 0;
	Journey* maxJourney = nullptr;
	for (size_t i = 0; i < size; ++i)
	{
		CarJourney* carJourney = dynamic_cast<CarJourney*>(journeys[i]);
		if (carJourney && carJourney->calculateCost() > maxCost)
		{
			maxCost = carJourney->calculateCost();
			maxJourney = carJourney;
		}
	}
	return maxJourney;
}

Journey* JourneyCollection::mostExpensiveFamilySeaVacation() const
{
	double maxCost = 0;
	Journey* mostExpensiveFamilySeaVacation = nullptr;
	for (size_t i = 0; i < size; ++i)
	{
		FamilySeaVacation* seaJourney = dynamic_cast<FamilySeaVacation*>(journeys[i]);
		if (seaJourney && seaJourney->calculateCost() > maxCost)
		{
			maxCost = seaJourney->calculateCost();
			mostExpensiveFamilySeaVacation = seaJourney;
		}
	}
	return mostExpensiveFamilySeaVacation;
}

Car* JourneyCollection::findMostExpensiveCar() const
{
	double maxCost = 0;
	Car* mostExpensiveCar = nullptr;
	for (size_t i = 0; i < size; ++i)
	{
		CarJourney* carJourney = dynamic_cast<CarJourney*>(journeys[i]);
		if (carJourney && carJourney->getTransport()->calculateCost() > maxCost)
		{
			maxCost = carJourney->getTransport()->calculateCost();
			mostExpensiveCar = dynamic_cast<Car*>(carJourney->getTransport()->clone());
		}
	}
	return mostExpensiveCar;
}

int JourneyCollection::findCheapestSeaVacationFamilyMembers() const
{
	double minCost = std::numeric_limits<double>::max();
	int minFamilyMembers = 0;
	for (size_t i = 0; i < size; ++i)
	{
		FamilySeaVacation* seaJourney = dynamic_cast<FamilySeaVacation*>(journeys[i]);
		if (seaJourney && seaJourney->calculateCost() < minCost)
		{
			minCost = seaJourney->calculateCost();
			minFamilyMembers = seaJourney->getFamilyMembers();
		}
	}
	return minFamilyMembers;
}

JourneyCollection* JourneyCollection::carsOnly() const
{
	JourneyCollection* cars = new JourneyCollection();
	for (size_t i = 0; i < size; ++i)
	{
		if (dynamic_cast<CarJourney*>(journeys[i]))
		{
			cars->add(journeys[i]);
		}
	}
	return cars;
}

JourneyCollection* JourneyCollection::planesOnly() const
{
	JourneyCollection* planes = new JourneyCollection();
	for (size_t i = 0; i < size; ++i)
	{
		if (dynamic_cast<FamilySeaVacation*>(journeys[i]))
		{
			planes->add(journeys[i]);
		}
	}
	return planes;
}
