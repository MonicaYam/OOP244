#define _CRT_SECURE_NO_WARNINGS

#include "SuperHero.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {
	SuperHero::SuperHero() {
		_heroName[0] = '\0';
		_heroHealth = 0;
		_heroStr = 0;
		_superHeroBonus = 0;
		_superHeroDefend = 0;
	}


	SuperHero::SuperHero(const char* name, const int& health, const int& str, const int& bonus, const int& defend) {
		_heroName[0] = '\0';
		_heroHealth = 0;
		_heroStr = 0;
		_superHeroBonus = 0;
		_superHeroDefend = 0;


		if (name != nullptr) {
			strncpy(_heroName, name, MAX_CHAR);
			_heroName[MAX_CHAR] = '\0';
		}

		if (health > 0) {
			_heroHealth = health;
		}

		if (str > 0) {
			_heroStr = str;
		}

		if (bonus > 0) {
			_superHeroBonus = bonus;
		}

		if (defend > 0) {
			_superHeroDefend = defend;
		}
	}


	int SuperHero::attackStrength() const {
		int str = 0;

		if (_heroStr > 0) {
			str = _heroStr + _superHeroBonus;
		}

		return str;
	}

	int SuperHero::defend() const {
		return _superHeroDefend;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

		SuperHero pHero1 = first, pHero2 = second;
		const SuperHero* winner = &first;

		int rouds = 0;

		//this probably should be its own function
		while (pHero1.isAlive() && pHero2.isAlive() && rouds < MAX_ROUND) {
			pHero1 -= pHero2.attackStrength() - pHero1.defend();
			pHero2 -= pHero1.attackStrength() - pHero2.defend();
			++rouds;
		}

		if (!pHero1.isAlive()) {
			winner = &second;
		}


		cout << "Super Fight! " << first << " vs " << second
			 << " : Winner is " << winner->getHeroName() << " in " << rouds << " rounds." << endl;
		return *winner;
	}

}
