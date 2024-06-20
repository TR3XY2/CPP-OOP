#include "footballplayer.h"

FootballPlayer::FootballPlayer()
	: player_name(""), player_surname(""), player_goals_per_year(0) {}

FootballPlayer::FootballPlayer(const std::string& name, const std::string& surname, int goals)
	: player_name(name), player_surname(surname), player_goals_per_year(goals) {}

FootballPlayer::FootballPlayer(const std::string& name, const std::string& surname, int goals, double coefficient)
	: player_name(name), player_surname(surname), player_goals_per_year(goals), player_reward_coefficient(coefficient) {}

FootballPlayer::FootballPlayer(const FootballPlayer& F)
	: player_name(F.player_name), player_surname(F.player_surname)
	, player_goals_per_year(F.player_goals_per_year), player_reward_coefficient(F.player_reward_coefficient) {}

FootballPlayer::~FootballPlayer() {}

int FootballPlayer::getGoals() const
{
	return player_goals_per_year;
}

void FootballPlayer::setCoefficient(double coefficient)
{
	player_reward_coefficient = coefficient;
}

double FootballPlayer::calculateReward() const
{
	return player_goals_per_year * player_reward_coefficient;
}

void FootballPlayer::print() const
{
	std::cout << "Player: " << player_name << ' ' << player_surname
		<< ". Goals: " << player_goals_per_year << ". " << std::endl;
}

void FootballPlayer::readFrom(std::istream& in)
{
	in >> player_name >> player_surname >> player_goals_per_year;
}

void FootballPlayer::writeTo(std::ostream& out) const
{
	out << player_name << ' ' << player_surname << ' ' << player_goals_per_year;
}

std::istream& operator>>(std::istream& in, FootballPlayer& P)
{
	P.readFrom(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const FootballPlayer& P)
{
	P.writeTo(out);
	return out;
}
