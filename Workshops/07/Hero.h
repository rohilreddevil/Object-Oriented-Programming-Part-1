#ifndef SICT_Hero_h
#define SICT_Hero_h

#include<iostream>
using namespace std;
namespace sict {

	const int max_rounds = 100;

	class Hero {

		char name[41];
		int health;
		int attack_strength;
	public:
		Hero();
		Hero(char *NAME, int HEALTH, int STRENGTH);
		void operator -=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream & operator<<(std::ostream& os, const Hero&);

	};
	const Hero& operator*(const Hero&, const Hero&);


}

#endif // !sict_Hero_h

