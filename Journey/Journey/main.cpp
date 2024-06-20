#include <iostream>
#include "carjourney.h"
#include "familyseavacation.h"
#include "transport.h"
#include "journeycollection.h"
#include "fstream"

int main()
{
	std::ifstream fin("data.txt");
	size_t n;
	fin >> n;
	JourneyCollection journeys;
	journeys.readFrom(fin, n);
	fin.close();
	journeys.print();

	std::cout << std::endl;

	std::cout << "MOST EXPENSIVE CAR JOURNEY: " << std::endl;
	Journey* mostExpensiveCarJourney = journeys.mostExpensiveCarJourney();
	mostExpensiveCarJourney->print();
	std::cout << "MOST EXPENSIVE FAMILY SEA VACATION: " << std::endl;
	Journey* mostExpensiveSeaVacation = journeys.mostExpensiveFamilySeaVacation();
	mostExpensiveSeaVacation->print();

	JourneyCollection* carsOnly = journeys.carsOnly();
	JourneyCollection* planesOnly = journeys.planesOnly();
	std::cout << "CAR JOURNEYS ONLY:" << std::endl;
	carsOnly->print();
	std::cout << "FAMILY SEA VACATIONS ONLY:" << std::endl;
	planesOnly->print();

	std::cout << std::endl;
	
	Car* mostExpensiveCar = carsOnly->findMostExpensiveCar();
	int minFamilyMembers = planesOnly->findCheapestSeaVacationFamilyMembers();
	std::cout << "HIGHEST CONSUMPTION CAR: " << *mostExpensiveCar << std::endl;
	std::cout << "FAMILY MEMBERS IN CHEAPEST SEA VACATION: " << minFamilyMembers << std::endl;

	delete mostExpensiveCar;
	delete carsOnly;
	delete planesOnly;

	return 0;
}