#include <vector>
#include <string>

class Player
{
	public:
		Player();
		Player(std::string n);

		std::string getName() const;
		std::string getChampion() const;
		float getKDR() const;
		int getKills() const;
		int getDeaths() const;
		float getWinRate() const;
		int getWins() const;
		int getLosses() const;
		int getMinionDeaths() const;
		std::string getChampions();
		int getAssists() const {return assists;};
		int getKillingSpree() const {return killingSpree;};
		int getDeathsSpree() const {return deathSpree;};
		float getSpree() const {return (float)killingSpree/deathSpree;};

		void setName(std::string n);
		void setKills(int k);
		void setDeaths(int d);
		void setChampion(std::string c); 
		void setWins(int w);
		void setLosses(int l);
		void setMinionDeaths(int m);
		void addToChampions(std::string c);
		void setAssists(int a) {assists=a;};
		void setKillingSpree() {killingSpree= kills - killingSpree;};
		void setDeathSpree() {deathSpree= deaths - deathSpree;};
		void setKilling(int k) {killingSpree=k;};
		void setDeath(int d) {deathSpree=d;};
	private:
		int kills;
		int deaths;
		int wins;
		int losses;
		int minionDeaths;
		int assists;
		int killingSpree;
		int deathSpree;
		float spree;
		float kdr;
		std::string name;
		std::string champion;
		std::vector<std::string> champions;
};

bool isWorseThan(const Player& p1, const Player& p2);
bool isBetterThan(const Player& p1, const Player& p2);