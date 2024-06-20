#pragma once
#include "insurance.h"

class FamilyInsurance : public Insurance
{
private:
	size_t number_of_family_members;
public:
	FamilyInsurance();
	FamilyInsurance(const FamilyInsurance& F);
	FamilyInsurance(size_t nof_family_members, double price);

	virtual void print() const override;
	virtual double calculatePrice() const override;
	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};