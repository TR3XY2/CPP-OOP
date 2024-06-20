#pragma once
#include "transport.h"

class Plane : public Transport
{
protected:
    std::string company_name;
    double ticket_price;
public:
    Plane();
    Plane(const std::string& company, double cost);
    Plane(const Plane& P);
    virtual ~Plane();

    void print() const override;
    double calculateCost() const override;
    Plane* clone() const override;

    void readFrom(std::istream& in) override;
    void writeTo(std::ostream& out) const override;
};