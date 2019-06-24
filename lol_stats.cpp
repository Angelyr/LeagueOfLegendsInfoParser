#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "player.h"
#include <stdio.h>  //to use strcmp
#include <string.h> //to use strcmp

//prints table of players after getting rid of duplicates and sorting them
void printPlayers(std::vector<Player>& p, char* argv[])
{
	unsigned int x,y,z;
	std::ofstream out_str(argv[2]);
	if (!out_str.good())
	{
    	std::cerr << "Can't open " << argv[2] << " to read.\n";
    	exit(1);
 	}
	//gets rid of duplicates with .erase and combines relvent data
	for(y=0; y < p.size(); y++)
	{
		for(z=y+1; z < p.size(); z++)
			if(p[y].getName()==p[z].getName())
			{
				p[y].setKills(p[y].getKills()+p[z].getKills());
				p[y].setDeaths(p[y].getDeaths()+p[z].getDeaths());
				if(p[y].getChampion()!=p[z].getChampion())
					p[y].addToChampions(p[z].getChampion());
				p.erase(p.begin()+z);
				z--;
			}
	}
	std::sort(p.begin(), p.end(), isWorseThan);

	//sets header
	out_str << std::setw(21) << std::left << "PLAYER NAME" << std::setw(10) << std::left;
	out_str << "KILLS" << std::setw(10) << std::left; 
	out_str << "DEATHS" << std::setw(10) << std::left;
	out_str << "KDR" << std::setw(15) << std::left;
	out_str << "PLAYED WITH CHAMPION(S)"<< std::endl;

	//prints stats
	for(x=0; x < p.size(); x++)
	{
		out_str << std::setw(21) << std::left << p[x].getName() << std::setw(10) << std::left;
		out_str << p[x].getKills() << std::setw(10) << std::left;
		out_str << p[x].getDeaths() << std::setw(10) << std::left;
		out_str << std::setprecision(2) << std::fixed << p[x].getKDR() << std::setw(21) << std::left;
		out_str << p[x].getChampions();
		if(x!=p.size()-1)
			out_str << std::endl;
	}
}
//sort array and output it to the text file
void printChampions(std::vector<Player>& p, char* argv[])
{
	unsigned int x,y,z;
	std::ofstream out_str(argv[2]);
	if (!out_str.good())
	{
    	std::cerr << "Can't open " << argv[2] << " to read.\n";
    	exit(1);
 	}
	
	//gets rid of duplicates with .erase and combines relvent data
	for(y=0; y < p.size(); y++)
	{
		for(z=y+1; z < p.size(); z++)
			if(p[y].getChampion()==p[z].getChampion())
			{
				p[y].setWins(p[y].getWins()+p[z].getWins());
				p[y].setLosses(p[y].getLosses()+p[z].getLosses());
				p[y].setMinionDeaths(p[y].getMinionDeaths()+p[z].getMinionDeaths());
				p.erase(p.begin()+z);
				z--;
			}
	}
	std::sort(p.begin(), p.end(), isBetterThan);

	//sets header
	out_str << std::setw(21) << std::left << "CHAMPION NAME" << std::setw(10) << std::left;
	out_str << "WINS" << std::setw(10) << std::left; 
	out_str << "LOSSES" << std::setw(10) << std::left;
	out_str << "WIN%" << std::setw(15) << std::left;
	out_str << "MINION DEATHS"<< std::endl;

	//prints stats
	for(x=0; x < p.size(); x++)
	{
		out_str << std::setw(21) << std::left << p[x].getChampion() << std::setw(10) << std::left;
		out_str << p[x].getWins() << std::setw(10) << std::left;
		out_str << p[x].getLosses() << std::setw(10) << std::left;
		out_str << std::setprecision(2) << std::fixed << p[x].getWinRate() << std::setw(21) << std::left;
		out_str << p[x].getMinionDeaths();
		if(x!=p.size()-1)
			out_str << std::endl;
	}
}
//sort the array and outputs it to the text file
void printCustom(std::vector<Player>& p, char* argv[])
{
	unsigned int x,y,z;
	std::ofstream out_str(argv[2]);
	if (!out_str.good())
	{
    	std::cerr << "Can't open " << argv[2] << " to read.\n";
    	exit(1);
 	}

	//gets rid of duplicates with .erase and combines relvent data
	for(y=0; y < p.size(); y++)
	{
		for(z=y+1; z < p.size(); z++)
			if(p[y].getChampion()==p[z].getChampion())
			{
				p[y].setKills(p[y].getKills()+p[z].getKills());
				p[y].setDeaths(p[y].getDeaths()+p[z].getDeaths());
				p[y].setAssists(p[y].getAssists()+p[z].getAssists());
				if(p[y].getKillingSpree() < p[z].getKillingSpree())
					p[y].setKilling(p[z].getKillingSpree());
				if(p[y].getDeathsSpree() < p[z].getDeathsSpree())
					p[y].setDeath(p[z].getDeathsSpree());
				p.erase(p.begin()+z);
				z--;
			}
	}
	std::sort(p.begin(), p.end(), isBetterThan);

	//sets header
	out_str << std::setw(21) << std::left << "CHAMPION NAME" << std::setw(10) << std::left;
	out_str << "KILLS" << std::setw(10) << std::left; 
	out_str << "DEATHS" << std::setw(10) << std::left;
	out_str << "ASSISTS" << std::setw(18) << std::left; 
	out_str << "KILLING SPREE" << std::setw(15) << std::left;
	out_str << "DEATH SPREE" << std::setw(13) << std::left << std::endl;

	//prints stats
	for(x=0; x < p.size(); x++)
	{
		out_str << std::setw(21) << std::left << p[x].getChampion() << std::setw(10) << std::left;
		out_str << p[x].getKills() << std::setw(10) << std::left;
		out_str << p[x].getDeaths() << std::setw(10) << std::left;
		out_str << p[x].getAssists() << std::setw(18) << std::left;
		out_str << p[x].getKillingSpree() << std::setw(15) << std::left;
		out_str << p[x].getDeathsSpree() << std::setw(21) << std::left;
		if(x!=p.size()-1)
			out_str << std::endl;
	}
}

//inputs information in text file into a vector of Player objects. Takes 20-30 seconds for input of 1000.
int main( int argc, char* argv[])
{
	std::ifstream in_str(argv[1]);
	if (!in_str.good())
	{
    	std::cerr << "Can't open " << argv[1] << " to read.\n";
    	exit(1);
 	}
	std::string temp;
	std::vector<Player> players;
	Player p;
	int spot=0;
	int x=0;
	unsigned int y=0;
	bool minion=false;

	while(in_str >> temp)
	{
		//sets username,champion, and losses for the losing team
		if(temp=="LOSING")
		{
			in_str >> temp;
			for(x=spot; x < spot+5; x++)
			{
				in_str >> temp;
				p.setName(temp);
				players.push_back(p);
				in_str >> temp;
				in_str >> temp;
				in_str >> temp;
				players[x].setChampion(temp);
				players[x].addToChampions(temp);
				players[x].setLosses(players[x].getLosses()+1);
			}
			spot+=5;
		}
		//sets username,champion, and wins for the winning team
		if(temp=="WINNING")
		{
			in_str >> temp;
			for(x=spot; x < spot+5; x++)
			{
				in_str >> temp;
				p.setName(temp);
				players.push_back(p);
				in_str >> temp;
				in_str >> temp;
				in_str >> temp;
				players[x].setChampion(temp);
				players[x].addToChampions(temp);
				players[x].setWins(players[x].getWins()+1);
			}
			spot+=5;
		}
		//goes through all the events and puts information into proper player.
		if(temp=="EVENTS")
		{
			in_str >> temp;
			while(temp!="END")
			{
				//sets kills and minion deaths and deathspree.
				in_str >> temp;
				in_str >> temp;
				if(temp != "minion")
				{
					for(y=0; y < players.size(); y++)
					{
						if(players[y].getName()==temp)
						{
							players[y].setKills(players[y].getKills()+1);
							players[y].setDeathSpree();
							break;
						}
					}
				}
				else
				{
					//to set the death to be a minion death
					minion=true;
				}

				//sets assists
				in_str >> temp;
				if(temp == "[")
					while(temp != "]")
					{
						in_str >> temp;
						for(y=0; y < players.size(); y++)
							if(players[y].getName() == temp)
							{
								players[y].setAssists(players[y].getAssists()+1);
								break;
							}
					}	
				in_str >> temp;
				if(temp == "killed")
					in_str >> temp;

				//sets deaths, minion deaths and killing spree;
				for(y=0; y < players.size(); y++)
				{
					if(players[y].getName() == temp)
					{
						if(minion)
							players[y].setMinionDeaths(players[y].getMinionDeaths()+1);
						minion=false;
						players[y].setDeaths(players[y].getDeaths()+1);
						players[y].setKillingSpree();
						break;
					}
				}
				in_str >> temp;
			}
		}
	}

	//calls different methods to print the information
	if(strcmp(argv[3],"players")==0)
		printPlayers(players, argv);
	else if(strcmp(argv[3],"champions")==0)
		printChampions(players, argv);
	else if(strcmp(argv[3],"custom")==0)
		printCustom(players, argv);
	else
	{
		std::cerr << "Invalid function " << argv[3] << " to read.\n";
    	exit(1);
	}
	return 0;
}