#include "journey.h"

Journey::Journey(Transport* transport, const std::string& destination): transport(transport), destination(destination){}

Journey::Journey(const Journey& J): transport(J.transport), destination(J.destination){}

Journey::~Journey()
{
}

std::string Journey::getDestination() const
{
	return destination;
}

double Journey::calculateCost() const
{
	return transport->calculateCost();
}

void Journey::print() const
{
	transport->print();
	std::cout << "Destination: " << destination << std::endl;
}

Transport* Journey::getTransport() const
{
	return transport;
}

void Journey::readFrom(std::istream& in)
{
	transport->readFrom(in);
	in >> destination;
}

void Journey::writeTo(std::ostream& out) const
{
	transport->writeTo(out);
	out << destination;
}
