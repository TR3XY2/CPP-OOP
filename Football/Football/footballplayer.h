#pragma once
#include <iostream>
#include <string>

class FootballPlayer
{
private:
	std::string player_name;
	std::string player_surname;
	int player_goals_per_year;
	double player_reward_coefficient = 1;
public:
	FootballPlayer();
	FootballPlayer(const std::string& name, const std::string& surname, int goals);
	FootballPlayer(const std::string& name, const std::string& surname, int goals, double coefficient);
	FootballPlayer(const FootballPlayer& F);
	~FootballPlayer();

	int getGoals() const;
	void setCoefficient(double coefficient);
	double calculateReward() const;
	void print() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, FootballPlayer& P);
std::ostream& operator<<(std::ostream& out, const FootballPlayer& P);