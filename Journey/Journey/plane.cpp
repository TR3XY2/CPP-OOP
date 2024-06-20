#include "plane.h"

Plane::Plane(): company_name(""), ticket_price(0){}

Plane::Plane(const std::string& company, double price): company_name(company), ticket_price(price){}

Plane::Plane(const Plane& P): company_name(P.company_name), ticket_price(P.ticket_price){}

Plane::~Plane(){}

void Plane::print() const
{
	std::cout << "Plane company: " << company_name << std::endl;
}

double Plane::calculateCost() const
{
	return ticket_price;
}

Plane* Plane::clone() const
{
	return new Plane(*this);
}

void Plane::readFrom(std::istream& in)
{
	in >> company_name >> ticket_price;
}

void Plane::writeTo(std::ostream& out) const
{
	out << company_name << ' ' <<  ticket_price;
}
