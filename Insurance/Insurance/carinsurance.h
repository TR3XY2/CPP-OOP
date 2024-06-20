#pragma once
#include "insurance.h"

class CarInsurance : public Insurance
{
private:
	double engine_capacity;
public:
	CarInsurance();
	CarInsurance(const CarInsurance& F);
	CarInsurance(double engine_capacity, double price);

	virtual void print() const override;
	virtual double calculatePrice() const override;
	virtual void readFrom(std::istream& in) override;
	virtual void writeTo(std::ostream& out) const override;
};

