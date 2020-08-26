#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include"Hero.h"

using namespace std;

namespace sict {

	Hero::Hero() {
		name[0] = { '\0' };
		health = 0;
		attack_strength = 0;

	}

	Hero::Hero(char *NAME, int HEALTH, int STRENGTH) {

		if (NAME[0] != 0 || strcmp(NAME, "") != 0) {
			strncpy(name, NAME, 41);
			health = HEALTH;
			attack_strength = STRENGTH;
		}
		else {
			Hero(); 
		}
	}

	void Hero::operator-=(int attack) {

		if (attack > 0) {
			health -= attack;
		}
		if (this->health < 0) {
			health = 0;
		}
	}

	bool Hero::isAlive() const {

		bool flag = false;
		if (health >0) {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;
	}

	int Hero::attackStrength() const {
		
		return attack_strength;
	}

	ostream& operator<<(ostream& os, const Hero& hero) {

		if (hero.name[0] == '\0') { //if there isn't any hero, it means that no name is present
			os << "No hero";
		}
		else {
			return os << hero.name;
		}
	}

	const Hero& operator*(const Hero& first, const Hero& second) {

		int rounds = 0;
		Hero one = first; //creating 1st object
		Hero two = second; //creating 2nd object
		bool tie = false;
		const Hero*victorious = new Hero;//the unmodifiable rank for the winner

		while (one.isAlive() && two.isAlive() && rounds<=max_rounds)
		{
			one -= second.attackStrength();
			two -= first.attackStrength(); //attack strength eventually decreases with attacks
			rounds++;
		}
		if (one.isAlive()) {
			victorious = &first;
		}
		else if (two.isAlive()) {
			victorious = &second;
		}
		if (tie) {
			victorious = &first;
		}

		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		cout << "Winner is " << *victorious << " in " << rounds << " rounds." << endl;
	
		return *victorious; // reference to whosover has won (first or second)
	}

}