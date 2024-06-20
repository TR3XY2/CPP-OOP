#include "familyinsurance.h"

FamilyInsurance::FamilyInsurance(): Insurance(), number_of_family_members(0) {}

FamilyInsurance::FamilyInsurance(const FamilyInsurance& F)
   : Insurance(F.price), number_of_family_members(F.number_of_family_members) {}

FamilyInsurance::FamilyInsurance(size_t nof_family_members, double price)
   : Insurance(price), number_of_family_members(nof_family_members) {}

void FamilyInsurance::print() const
{
	std::cout << "Family Insurance. Family members: " << number_of_family_members << ", Price: " << calculatePrice() << std::endl;
}

double FamilyInsurance::calculatePrice() const
{
	return price*number_of_family_members;
}

void FamilyInsurance::readFrom(std::istream& in)
{
	in >> price >> number_of_family_members;
}

void FamilyInsurance::writeTo(std::ostream& out) const
{
	out << price << ' ' << number_of_family_members;
}
