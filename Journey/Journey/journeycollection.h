#pragma once
#include "journey.h"
#include "car.h"
#include "plane.h"
#include "carjourney.h"
#include "familyseavacation.h"

class JourneyCollection
{
private:
	size_t capacity;
	size_t size;
	Journey** journeys;
	
	void checkMem();
	void clear();
public:
	JourneyCollection();
	JourneyCollection(const JourneyCollection& J);
	virtual ~JourneyCollection();

	void print();
	void add(Journey* journey);
	void readFrom(std::istream& in, size_t n);
	double calculateTotalCost() const;

	Journey* mostExpensiveCarJourney() const;
	Journey* mostExpensiveFamilySeaVacation() const;

	Car* findMostExpensiveCar() const;
	int findCheapestSeaVacationFamilyMembers() const;

	JourneyCollection* carsOnly() const;
	JourneyCollection* planesOnly() const;
};