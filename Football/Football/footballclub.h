#pragma once
#include "footballplayer.h"

class FootballClub
{
private:
	std::string club_name;
	double club_coefficient = 50;
	FootballPlayer* club_players;
	static const size_t max_size = 21;
	size_t used = 0;
public:
	FootballClub();
	FootballClub(const std::string& name);
	FootballClub(const std::string& name, double coefficient);
	FootballClub(const std::string& name, FootballPlayer* players);
	FootballClub(const std::string& name, double coefficient, FootballPlayer* players);
	FootballClub(const FootballClub& C);
	~FootballClub();

	void printClub() const;
	std::string getName() const;
	void addPlayer(const FootballPlayer& P);
	void sortPlayersByGoals();
	int totalGoals() const;
	double totalReward() const;
	void setCoefficient(double c);

	void operator=(const FootballClub& C);
};

bool findClub(FootballClub* clubs, size_t n, const std::string& name);
FootballClub* readPlayers(std::istream& in, size_t& n);
void printClubs(FootballClub* clubs, size_t n);
FootballClub* getMaxGoalsClub(FootballClub* clubs, size_t n);
FootballClub* getMaxRewardClub(FootballClub* clubs, size_t n);
