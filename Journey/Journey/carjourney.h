#pragma once
#include "journey.h"
#include "car.h"

class CarJourney : public Journey
{
private:
    double journey_distance;
public:
    CarJourney();
    CarJourney(Car* car, const std::string& destination, double distance);
    CarJourney(const CarJourney& C);
    virtual ~CarJourney();

    CarJourney* clone() const override;
    double calculateCost() const override;
    void print() const override;
    double getDistance() const;
    void readFrom(std::istream& in) override;
};