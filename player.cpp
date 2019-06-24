#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "player.h"

Player::Player()
{
	kills=0;
	deaths=0;
	wins=0;
	losses=0;
	minionDeaths=0;
	killingSpree=0;
	deathSpree=0;
}
Player::Player(std::string n)
{
	name=n;
	kills=0;
	deaths=0;
	wins=0;
	losses=0;
}
std::string Player::getName() const
{
	return name;
}
std::string Player::getChampion() const
{
	return champion;
}
float Player::getKDR() const
{
	if(kills==0)
		return 0;
	if(deaths==0)
		return kills;
	return (float)kills/(float)deaths;
}
//sorts players
bool isWorseThan(const Player& p1, const Player& p2)
{
	if(p1.getKDR() > p2.getKDR())
		return true;
	else if(p1.getKills() > p2.getKills() && p1.getKDR() == p2.getKDR())
		return true;
	else if(p1.getDeaths() < p2.getDeaths() && p1.getKDR() == p2.getKDR() && p1.getKills() == p2.getKills())
		return true;
	else if(p1.getName() < p2.getName() && p1.getKDR() == p2.getKDR() && p1.getDeaths() == p2.getDeaths() && p1.getKills() == p2.getKills() )
		return true;
	else 
		return false;
}
//sorts champions
bool isBetterThan(const Player& p1, const Player& p2)
{
	if(p1.getWinRate() > p2.getWinRate())
		return true;
	else if(p1.getWins() > p2.getWins() && p1.getWinRate() == p2.getWinRate())
		return true;
	else if(p1.getLosses() < p2.getLosses() && p1.getWins() == p2.getWins() && p1.getWinRate() == p2.getWinRate())
		return true;
	else if(p1.getChampion() < p2.getChampion() && p1.getLosses() == p2.getLosses() && p1.getWins() == p2.getWins() && p1.getWinRate() == p2.getWinRate())
		return true;
	else
		return false;
}
int Player::getKills() const
{
	return kills;
}
int Player::getDeaths() const
{
	return deaths;
}
int Player::getWins() const
{
	return wins;
}
int Player::getLosses() const
{
	return losses;
}
float Player::getWinRate() const
{
	return (float)wins/(float)(wins+losses);
}
int Player::getMinionDeaths() const
{
	return minionDeaths;
}
//returns print version of champions
std::string Player::getChampions()
{
	sort(champions.begin(), champions.end());

	std::string c;
	for(unsigned int x=0; x < champions.size(); x++)
	{
		if(x < champions.size()-1)
			c+=champions[x]+", ";
		else
			c+=champions[x];
	}
	return c;
}
void Player::addToChampions(std::string c)
{
	champions.push_back(c);
}
void Player::setMinionDeaths(int m)
{
	minionDeaths=m;
}
void Player::setWins(int w)
{
	wins=w;
}
void Player::setLosses(int l)
{
	losses=l;
}
void Player::setName(std::string n)
{
	name=n;
}
void Player::setKills(int k)
{
	kills=k;
}
void Player::setDeaths(int d)
{
	deaths=d;
}
void Player::setChampion(std::string c)
{
	champion=c;
}
