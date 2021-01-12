#define _CRT_SECURE_NO_WARNINGS

#include "Hero.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {
	Hero::Hero() 
	{
		_heroName[0] = '\0';
		_heroHealth = 0;
		_heroStr = 0;
	}

	Hero::Hero(const char* name, const int& health, const int& str) 
	{
		if (name != nullptr) {
			strncpy(_heroName, name, MAX_CHAR);
			_heroName[MAX_CHAR] = '\0';
		}
		else {
			_heroName[0] = '\0';
		}

		if (health > 0) {
			_heroHealth = health;
		}
		else {
			_heroHealth = 0;
		}

		if (str > 0) {
			_heroStr = str;
		}
		else {
			_heroStr = 0;
		}

	}

	void Hero::operator-=(int attack) 
	{
		if (0 < attack) {
			_heroHealth = _heroHealth - attack;

			if (_heroHealth <= 0) {
				_heroHealth = 0;
			}
		}
	}


	bool Hero::isAlive() const
	{
		return _heroHealth > 0;
	}

	int Hero::attackStrength() const
	{
		int str = 0;

		if (_heroStr > 0) {
			str = _heroStr;
		}

		return str;
	}


	const char* Hero::getHeroName() const {
		return _heroName;
	}


	ostream& operator<<(ostream& ostr, const Hero& hero)
	{
		if (hero._heroName[0] == '\0') {
			ostr << "No hero";
		}
		else {
			ostr << hero._heroName;
		}
		return ostr;
	}


	const Hero& operator*(const Hero& first, const Hero& second) 
	{

		Hero pHero1 = first, pHero2 = second;
		const Hero* winner = &first;

		int rouds = 0;

		//this probably should be its own function
		while (pHero1.isAlive() && pHero2.isAlive() && rouds < MAX_ROUND) {
			pHero1 -= pHero2.attackStrength();
			pHero2 -= pHero1.attackStrength();
			++rouds;
		}

		if (!pHero1.isAlive()) {
			winner = &second;
		}
		cout << "Ancient Battle! " << first << " vs " << second
		    << " : Winner is " << winner->getHeroName() << " in " << rouds << " rounds." << endl;
		return *winner;
	}

}
