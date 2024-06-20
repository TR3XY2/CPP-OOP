#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <set>
#include "weatherforecast.h"

using ReadForecast = std::istream_iterator<WeatherForecast>;
using WriteForecast = std::ostream_iterator<WeatherForecast>;

int main()
{
	WriteForecast forecast_printer(std::cout, "\n");

	std::ifstream fin("data.txt");
	std::vector<WeatherForecast> forecast;
	std::copy(ReadForecast(fin), ReadForecast(), std::back_inserter(forecast));
	fin.close();
	std::sort(forecast.begin(), forecast.end());
	std::copy(forecast.cbegin(), forecast.cend(), forecast_printer);
	std::cout << std::endl;


	int month = 7;
	double total_precipitation_in_july = 0;
	int days_without_precipitation = 0;
	std::for_each(forecast.cbegin(), forecast.cend(), 
		[&total_precipitation_in_july, &days_without_precipitation, month](const WeatherForecast& W) {
		if (W.getMonth() == month)
		{
			total_precipitation_in_july += W.getPrecipitation();
			if (W.getPrecipitation() == 0)
			{
				++days_without_precipitation;
			}
		}
		});
	std::cout << "Total precipitation in July: " << total_precipitation_in_july << std::endl;
	std::cout << "Number of days without precipitation in July: " << days_without_precipitation << std::endl << std::endl;


	std::vector<WeatherForecast> without_precipitation;
	std::copy_if(forecast.cbegin(), forecast.cend(), std::back_inserter(without_precipitation), 
		[](const WeatherForecast& W) { return W.getPrecipitation() == 0.0; });
	std::sort(without_precipitation.begin(), without_precipitation.end(), 
		[](const WeatherForecast& W1, const WeatherForecast& W2) {return W1.getTemperature() < W2.getTemperature(); });
	std::copy(without_precipitation.cbegin(), without_precipitation.cend(), forecast_printer);
	if (!without_precipitation.empty())
	{
		std::cout << "Coldest day: " << without_precipitation.front() << std::endl;
		std::cout << "Hottest day: " << without_precipitation.back() << std::endl << std::endl;
	}
	else
	{
		std::cout << "There are no days without precipitation!" << std::endl << std::endl;
	}

	std::set<double> temperatures;
	std::string day = "Monday";
	std::for_each(forecast.cbegin(), forecast.cend(), [&day, &temperatures](const WeatherForecast& W) { 
		if (W.getDayOfWeek() == day)
		{
			temperatures.insert(W.getTemperature());
		}
		});
	std::cout << "Temperatures on " << day << "s: ";
	std::copy(temperatures.cbegin(), temperatures.cend(), std::ostream_iterator<double>(std::cout, " "));
	return 0;
}