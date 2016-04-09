/***************************************
* Program By: Alex White
* Date Created: March 13, 2016
*
* NOTE: This will be the universal
* Heading comment for all 5 monsters
*
* This is where the individual enemies
* will be created. Each enemy will have
* different stats and different attacks.
****************************************/

#ifndef _LAGIA_
#define _LAGIA_

#include <string>
#include "enemy.h"

using namespace std;

class lagiacrus : public enemy{
	private:
		
		int my_health;
		string my_name;
		bool defense_up;
		bool evaded_;
		
	public:
		
		lagiacrus(string n = "Name Me");
		string getName() const;
		
		void strongAttack(enemy * monster);
		string strongString() const;
		void simpleAttack(enemy * monster);
		string simpleString() const;
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
