#pragma once
#include "journey.h"
#include "plane.h"

class FamilySeaVacation : public Journey
{
private:
	int nof_family_members;
public:
    FamilySeaVacation();
    FamilySeaVacation(Plane* plane, const std::string& destination, int members);
    FamilySeaVacation(const FamilySeaVacation& F);
    virtual ~FamilySeaVacation();

    int getFamilyMembers() const;
    FamilySeaVacation* clone() const override;
    void print() const override;
    double calculateCost() const override;
    void readFrom(std::istream& in) override;
};