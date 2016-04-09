/*********************************************
* Program By: Alex White
* Date Created: March 13, 2016
*
* This is the parent class for any and all
* monsters in the adventure fighter game.
* This class will provide all the basic
* information necessary for enemy interactions
* and parameters, including health, recieving
* damage, attacking, and console output.
*
* If you want to copy this code, go ahead.
* I am not stopping you, as I am against
* copyright for this kind of thing, and prefer
* the open source approach to coding.
**********************************************/

#ifndef _ENEMY_
#define _ENEMY_

#include <string>

using namespace std;

class enemy{
	public:
		enemy();
		
		// Gets the enemy name for battle reference.
		virtual string getName() const = 0;
		
		// There are 5 things an enemy can do overall, simple attacks, strong attacks, special attacks,
		// an evasive manouver, and a defensive move. Each will have different effects and provide different 
		// effects to the player, either directly or indirectly.
		
		virtual void simpleAttack(enemy * monster) = 0;
		virtual string simpleString() const = 0;
		
		virtual void strongAttack(enemy * monster) = 0;
		virtual string strongString() const = 0;
		
		virtual void evasiveManouver() = 0;
		virtual string evasiveString() const = 0;
		
		virtual void defensiveAct() = 0;
		virtual string defensiveString() const = 0;
		
		virtual void specialAttack(enemy * monster) = 0;
		virtual string specialString() const = 0;
		
		// Returns the health value for the enemy.
		virtual int getHealth() const = 0;
		
		// Has the ability to do damage, or recieve damage.
		virtual void getHit(int damage) = 0;
		
		// Resets health for the next battle.
		virtual void resetHealth() = 0;
};

#endif
