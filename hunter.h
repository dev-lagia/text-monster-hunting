#ifndef _HUNTER_
#define _HUNTER_

#include <string>
#include "enemy.h"

using namespace std;

class hunter : public enemy{
	private:
		string my_name;
		int my_health;
		int my_potions;
		int my_fireballs;
		bool defense_up;
		
	public:
		hunter(string n = "Name Me");
		string getName() const;
		
		void setFireball(int fireball);
		int getFireball() const;
		void strongAttack(enemy * monster);
		string strongString() const;
		void simpleAttack(enemy * monster);
		string simpleString() const;
		void setPotions(int potions);
		int getPotions() const;
		void heal(int potions, enemy * monster);
		string healString() const;
		void specialAttack(enemy * monster);
		string specialString() const;
		void evasiveManouver();
		string evasiveString() const;
		void defensiveAct();
		string defensiveString() const;
		
		int getHealth() const;
		void getHit(int damage);
		void resetHealth();
};
#endif
