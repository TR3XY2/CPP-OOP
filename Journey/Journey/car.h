#pragma once
#include "transport.h"
#include <string>

class Car : public Transport
{
private:
	std::string brand;
	double consumption_per_100km;

public:
	Car();
	Car(const std::string& brand, double fuelConsumption);
	Car(const Car& C);
	virtual ~Car();

	std::string getBrand() const;
	void print() const override;
	double calculateCost() const override;
	Car* clone() const override;
	void readFrom(std::istream& in) override;
	void writeTo(std::ostream& out) const override;

};