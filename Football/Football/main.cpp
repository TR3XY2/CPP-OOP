#include <iostream>
#include "footballplayer.h"
#include "footballclub.h"
#include <fstream>

int main()
{
	size_t n = 3;
	std::ifstream fin("data.txt");
	FootballClub* clubs = readPlayers(fin, n);
	fin.close();
	printClubs(clubs, n);

	FootballClub* maxGoalClub = getMaxGoalsClub(clubs, n);
	std::cout << "Max goals club: " << maxGoalClub->getName() << " " << maxGoalClub->totalGoals() << std::endl;

	FootballClub* maxRewardlClub = getMaxRewardClub(clubs, n);
	std::cout << "Max reward: " << maxRewardlClub->getName() << " " << maxRewardlClub->totalReward() << std::endl;
	delete[] clubs;
	return 0;
}