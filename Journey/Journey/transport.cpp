#include "transport.h"

Transport::~Transport() {}

std::istream& operator>>(std::istream& in, Transport& T)
{
	T.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Transport& T)
{
	T.writeTo(out);
	return out;
}
