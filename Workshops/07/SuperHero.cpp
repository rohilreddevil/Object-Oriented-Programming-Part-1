#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include"SuperHero.h"


using namespace std;

namespace sict {

	SuperHero::SuperHero() {

		//the derived class inherits the entire structure and instance variables of the base class
		//this includes the data members used in that particular class
		//new members introduced in DERIVED CLASS IN ADDITION TO THE INHERITED ONES
		bonus_attack = 0; 
		defend_strength = 0; 

	}

	SuperHero::SuperHero(char* NAME, int HEALTH, int STRENGTH, int BONUS, int DEFEND) : Hero(NAME, HEALTH, STRENGTH){ //passing superhero parameters to the base class from the derived class so that it can be updated
			//the base class will use these values to create the base class part of the object based on these parameters
		if (bonus_attack != 0 || defend_strength !=0 ) {

			bonus_attack = BONUS;
			defend_strength = STRENGTH;
		}
		else
		{
			SuperHero();
		}

	}

	int SuperHero::attackStrength() const {

		return (bonus_attack + Hero::attackStrength()); // superhero's strength + hero's attack strength
	}

	int SuperHero::defend() const {

		return defend_strength;
	}

	const  SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int ROUNDS = 0;
		const SuperHero *winner = &first; //winner is given an unmodifiable rank of first
		SuperHero one = first;
		SuperHero two = second; //creating 2 objects of the same type to represent two Superheroes
		bool draw = false;

		cout << "Super Fight! " << first << " vs " << second << " : ";

		while (ROUNDS <= 100 && first.isAlive() && second.isAlive()) {

			one -= two.attackStrength() - one.defend(); //attackStrength function consists of attack strength + bonus 
			two -= one.attackStrength() - two.defend(); //defend function has the defend strength value
			ROUNDS++;
		}
			if (one.isAlive()) { winner = &first; }
			
			else if (two.isAlive()) { winner = &second; }

			if (draw) { winner = &first; }
		
			cout << "Winner is " << *winner << " in " << ROUNDS << " rounds." << endl;
			return *winner;
		}
	
	}



}

