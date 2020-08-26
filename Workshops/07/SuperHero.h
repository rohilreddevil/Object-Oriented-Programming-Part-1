#ifndef SICT_SuperHero_h
#define SICT_SuperHero_h

#include<iostream>
#include"Hero.h"

namespace sict {

	class SuperHero : public Hero{

		//the name, health and attack strength will be inherited from the Hero class
		int bonus_attack; //unique feature of superheroes
		int defend_strength;
	public:
		SuperHero();
		SuperHero(char* NAME, int HEALTH, int STRENGTH, int BONUS, int DEFEND);
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);




}








#endif
