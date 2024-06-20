#include "familyseavacation.h"

FamilySeaVacation::FamilySeaVacation(): Journey(new Plane(), ""), nof_family_members(0) {}

FamilySeaVacation::FamilySeaVacation(Plane* plane, const std::string& destination, int members): Journey(plane,destination), nof_family_members(members){}

FamilySeaVacation::FamilySeaVacation(const FamilySeaVacation& F): Journey(F.transport->clone(), F.destination), nof_family_members(F.nof_family_members) {}

FamilySeaVacation::~FamilySeaVacation()
{
	delete transport;
}

int FamilySeaVacation::getFamilyMembers() const
{
	return nof_family_members;
}

FamilySeaVacation* FamilySeaVacation::clone() const
{
	return new FamilySeaVacation(*this);
}

void FamilySeaVacation::print() const
{
	std::cout << "Sea Vacation:" << std::endl;
	Journey::print();
	std::cout << "Cost: " << calculateCost() << std::endl;
}

double FamilySeaVacation::calculateCost() const
{
	return nof_family_members*getTransport()->calculateCost();
}

void FamilySeaVacation::readFrom(std::istream& in)
{
	if (transport == nullptr)
	{
		transport = new Plane();
	}
	transport->readFrom(in);
	in >> destination >> nof_family_members;
}
