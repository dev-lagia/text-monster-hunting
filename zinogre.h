#ifndef _ZINOGRE_
#define _ZINOGRE_

#include <string>
#include "enemy.h"

using namespace std;

class zinogre : public enemy{
	private:
		
		int my_health;
		string my_name;
		bool defense_up;
		bool evaded_;
		
	public:
		
		zinogre(string n = "Name Me");
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
