#pragma once
#include <iostream>
#include <string>

class City
{
private:
	std::string city_name;
	std::string city_country;
	int city_population;

public:
	City();
	City(std::string name, std::string country, int population);
	City(const City& C);
	~City();

	bool operator<(const City& C) const;
	std::string getCountry() const;
	std::string getCity() const;
	int getPopulation() const;
	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, City& C);
std::ostream& operator<<(std::ostream& out, const City& C);