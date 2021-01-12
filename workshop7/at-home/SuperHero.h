#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {
	private:
		int _superHeroBonus;
		int _superHeroDefend;

	public:
		SuperHero();
		SuperHero(const char* name, const int& health, const int& str, const int& bonus, const int& defend);
		int attackStrength() const;
		int defend() const;

	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif
