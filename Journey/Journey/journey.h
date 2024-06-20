#pragma once
#include "transport.h"
#include <string>

class Journey
{
protected:
	Transport* transport;
	std::string destination;
public:
	Journey() = delete;
	Journey(Transport* transport, const std::string& destination);
	Journey(const Journey& J);
	virtual ~Journey();

	std::string getDestination() const;
	virtual double calculateCost() const;
	virtual void print() const;
	virtual Journey* clone() const abstract;

	Transport* getTransport() const;

	virtual void readFrom(std::istream& in);
	virtual void writeTo(std::ostream& out) const;
};

