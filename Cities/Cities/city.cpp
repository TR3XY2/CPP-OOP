#include "city.h"

City::City()
	: city_country(""), city_name(""), city_population(0)
{}

City::City(std::string country, std::string name, int population)
	: city_country(country), city_name(name), city_population(population)
{}

City::City(const City& C)
	: city_country(C.city_country), city_name(C.city_name), city_population(C.city_population)
{}

City::~City()
{}

bool City::operator<(const City & C) const
{
	return getPopulation() < C.getPopulation();
}

std::string City::getCountry() const
{
	return city_country;
}

std::string City::getCity() const
{
	return city_name;
}

int City::getPopulation() const
{
	return city_population;
}

void City::readFrom(std::istream& in)
{
	in >> city_country >> city_name >> city_population;
}

void City::writeTo(std::ostream& out) const
{
	out << city_country << ' ' << city_name << ' ' << city_population;
}

std::istream& operator>>(std::istream& in, City& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const City& C)
{
	C.writeTo(out);
	return out;
}
