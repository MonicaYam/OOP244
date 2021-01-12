#ifndef SICT_HERO_H
#define SICT_HERO_H

#include<iostream>

namespace sict {

	const int MAX_CHAR = 40;
	const int MAX_ROUND = 100;

	class Hero {
	private:
		char _heroName[MAX_CHAR + 1];
		int _heroHealth;
		int _heroStr;

	public:
		const char* getHeroName() const;

		Hero();
		Hero(const char* name, const int& health, const int& str);
		bool isAlive() const;
		int attackStrength() const;
		void operator-=(int attack);

		friend std::ostream& operator<<(std::ostream& ostr, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // ! SICT_HERO_H


