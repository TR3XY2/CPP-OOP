#include "footballclub.h"

FootballClub::FootballClub()
	: club_name(""), club_players(new FootballPlayer[max_size]) {
}

FootballClub::FootballClub(const std::string& name)
	: club_name(name), club_players(new FootballPlayer[max_size]) {}

FootballClub::FootballClub(const std::string& name, double coefficient)
	: club_name(name), club_coefficient(coefficient), club_players(new FootballPlayer[max_size]) {}

FootballClub::FootballClub(const std::string& name, FootballPlayer* players)
	: club_name(name), club_players(new FootballPlayer[max_size])
{
	for (size_t i = 0; i < max_size; ++i)
	{
		club_players[i] = players[i];
	}
}

FootballClub::FootballClub(const std::string& name, double coefficient, FootballPlayer* players)
	: club_name(name), club_coefficient(coefficient), club_players(new FootballPlayer[max_size])
{
	for (size_t i = 0; i < max_size; ++i)
	{
		club_players[i] = players[i];
	}
}

FootballClub::FootballClub(const FootballClub& C)
	: club_name(C.club_name), club_coefficient(C.club_coefficient), club_players(new FootballPlayer[max_size])
{
	for (size_t i = 0; i < max_size; ++i)
	{
		club_players[i] = C.club_players[i];
	}
}

FootballClub::~FootballClub()
{
	delete[] club_players;
}

void FootballClub::setCoefficient(double c) {
	club_coefficient = c;
}

void FootballClub::printClub() const
{
	std::cout << "Club name: " << club_name << std::endl;
	std::cout << "Players: " << std::endl;
	for (size_t i = 0; i < used; ++i)
	{
		club_players[i].print();
	}
	std::cout << "Total goals: " << totalGoals() << std::endl;
	std::cout << "Total reward: " << totalReward() << std::endl;
}

std::string FootballClub::getName() const
{
	return club_name;
}

void FootballClub::addPlayer(const FootballPlayer& P)
{
	if (used == max_size)
	{
		std::cout << "CLUB IS FULL!" << std::endl;
	}
	club_players[used] = P;
	club_players[used].setCoefficient(club_coefficient);
	++used;
}

void FootballClub::sortPlayersByGoals()
{
	size_t i, j;
	bool swapped;
	for (i = 0; i < used - 1; ++i)
	{
		swapped = false;
		for (j = 0; j < used - i - 1; ++j)
		{
			if (club_players[j].getGoals() < club_players[j + 1].getGoals())
			{
				FootballPlayer temp = club_players[j];
				club_players[j] = club_players[j + 1];
				club_players[j + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false)
		{
			break;
		}
	}
}

int FootballClub::totalGoals() const
{
	int total = 0;
	for (size_t i = 0; i < used; ++i)
	{
		total += club_players[i].getGoals();
	}
	return total;
}

double FootballClub::totalReward() const
{
	double total = 0;
	for (size_t i = 0; i < used; ++i)
	{
		total += club_players[i].calculateReward();
	}
	return total;
}
void FootballClub::operator=(const FootballClub& C)
{
	if (this == &C)
	{
		return;
	}
	club_name = C.club_name;
	club_coefficient = C.club_coefficient;

	for (size_t i = 0; i < C.used; ++i)
	{
		club_players[i] = C.club_players[i];
	}

	used = C.used;
}


bool findClub(FootballClub* clubs, size_t n, const std::string& name)
{
	for (size_t i = 0; i < n; ++i)
	{
		if (clubs[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}

FootballClub* readPlayers(std::istream& in, size_t& n)
{
	n = 3;
	size_t number_of_players;
	in >> number_of_players;
	FootballClub* clubs = new FootballClub[n];
	clubs[0] = FootballClub("Barcelona", 70);
	clubs[1] = FootballClub("Real");
	clubs[1].setCoefficient(40);
	clubs[2] = FootballClub("Liverpool");
	/* оск≥льки в нас ф≥ксований розм≥р - 3 ,
	   то зробив простим способом. якщо ж ми хочемо
	   дов≥льну к≥льк≥сть клуб≥в, то робимо масив назв клуб≥в,
	   €кщо клуб вже Ї то добавл€Їмо до нього гравц€,
	   €кщо ж н≥ то добавл€Їмо клуб ≥ тод≥ добавл€Їмо до нього гравц€*/
	for (size_t i = 0; i < number_of_players; ++i)
	{
		std::string name;
		std::string player_name;
		std::string player_surname;
		int goals;
		in >> name >> player_name >> player_surname >> goals;
		if (name == "Barcelona")
		{
			clubs[0].addPlayer(FootballPlayer(player_name, player_surname, goals));
		}
		else if (name == "Real")
		{
			clubs[1].addPlayer(FootballPlayer(player_name, player_surname, goals));
		}
		else if (name == "Liverpool")
		{
			clubs[2].addPlayer(FootballPlayer(player_name, player_surname, goals));
		}
		else
		{
			std::cout << "INVALID CLUB NAME!" << std::endl;
		}
	}
	return clubs;
}

void printClubs(FootballClub* clubs, size_t n)
{
	std::cout << "FOOTBALL CLUBS:" << std::endl;
	for (size_t i = 0; i < n; ++i)
	{
		clubs[i].sortPlayersByGoals();
		clubs[i].printClub();
	}
	std::cout << std::endl;
}

FootballClub* getMaxGoalsClub(FootballClub* clubs, size_t n)
{
	FootballClub* max = &clubs[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (clubs[i].totalGoals() > max->totalGoals())
		{
			max = &clubs[i];
		}
	}
	return max;
}

FootballClub* getMaxRewardClub(FootballClub* clubs, size_t n)
{
	FootballClub* max = &clubs[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (clubs[i].totalReward() > max->totalReward())
		{
			max = &clubs[i];
		}
	}
	return max;
}