#pragma once
#include <iostream>
#include <string>

class WeatherForecast
{
private:
	std::string day_of_week;
	int day_of_month;
	int month;
	double temperature;
	double precipitation;
public:
	WeatherForecast(): day_of_week(""), day_of_month(0), month(0), temperature(0.0), precipitation(0.0) {}
	WeatherForecast(std::string day_week, int day_month, int m, double temp, double precip):
		day_of_week(day_week), day_of_month(day_month), month(m), temperature(temp), precipitation(precip){}
	WeatherForecast(const WeatherForecast& W)
		: day_of_week(W.day_of_week), day_of_month(W.day_of_month), month(W.month),
		temperature(W.temperature), precipitation(W.precipitation) {}
	~WeatherForecast(){}

	std::string getDayOfWeek() const
	{
		return day_of_week;
	}
	int getDayOfMonth() const
	{
		return day_of_month;
	}
	int getMonth() const
	{
		return month;
	}
	double getTemperature() const
	{
		return temperature;
	}
	double getPrecipitation() const
	{
		return precipitation;
	}

	void setTemperature(double newTemperature)
	{
		temperature = newTemperature;
	}
	void setPrecipitation(double newPrecipitation)
	{
		precipitation = newPrecipitation;
	}

	bool operator<(const WeatherForecast& other) const
	{
		if (month != other.month)
		{
			return month < other.month;
		}
		return day_of_month < other.day_of_month;
	}

	friend std::istream& operator>>(std::istream& in, WeatherForecast& W)
	{
		in >> W.day_of_week >> W.day_of_month >> W.month >> W.temperature >> W.precipitation;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const WeatherForecast& W)
	{
		out << W.day_of_week << ' ' << W.day_of_month << ' ' << W.month 
			<< ' ' << W.temperature << ' ' << W.precipitation;
		return out;
	}
};