#include <string>
#include "zinogre.h"
#include "enemy.h"


using namespace std;

// Generally speaking, enemies (to the player) will have more health than the player.
zinogre::zinogre(string n){
	my_name = n;
	my_health = 525;
	defense_up = false;
	evaded_ = false;
}
string zinogre::getName() const{
	return my_name;
}

// The attacks will have values that reflect the player's health (which, at max will be 150), so not TOO much damage will be given.
void zinogre::strongAttack(enemy * monster){
	defense_up = false;
	evaded_ = false;
	monster->getHit(30);
}
string zinogre::strongString() const{
	return "Lightning Balls";
}
void zinogre::simpleAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(20);
}
string zinogre::simpleString() const{
	return "Hip Check";
}
void zinogre::specialAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(35); // We want this one to be REALLY devistating (while fair).
}
string zinogre::specialString() const{
	return "Breakdance Swipe";
}
void zinogre::evasiveManouver(){
	defense_up = false;
	evaded_ = true;
}
string zinogre::evasiveString() const{
	return "Evasion";
}
void zinogre::defensiveAct(){
	evaded_ = false;
	defense_up = true;
}
string zinogre::defensiveString() const{
	return "Defense Curl";
}
int zinogre::getHealth() const{
	return my_health;
}

// Evasion was added to make battles a little more interesting. Chances of evasion will be small...
void zinogre::getHit(int damage){
	if(defense_up){
		my_health = my_health - (damage / 2);
	} else if(evaded_){
		my_health = my_health;
	} else{
		my_health = my_health - damage;
	}
}
void zinogre::resetHealth(){
	my_health = 525;
}
