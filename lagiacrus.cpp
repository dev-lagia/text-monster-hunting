#include <string>
#include "lagiacrus.h"
#include "enemy.h"

using namespace std;

// Generally speaking, enemies (to the player) will have more health than the player.
lagiacrus::lagiacrus(string n){
	my_name = n;
	my_health = 500;
	defense_up = false;
	evaded_ = false;
}
string lagiacrus::getName() const{
	return my_name;
}

// The attacks will have values that reflect the player's health (which, at max will be 150), so not TOO much damage will be given.
void lagiacrus::strongAttack(enemy * monster){
	defense_up = false;
	evaded_ = false;
	monster->getHit(25);
}
string lagiacrus::strongString() const{
	return "Hip Check";
}
void lagiacrus::simpleAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(15);
}
string lagiacrus::simpleString() const{
	return "Charge";
}
void lagiacrus::specialAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(35); // We want this one to be REALLY devistating (while fair).
}
string lagiacrus::specialString() const{
	return "Lightning Discharge";
}
void lagiacrus::evasiveManouver(){
	defense_up = false;
	evaded_ = true;
}
string lagiacrus::evasiveString() const{
	return "Evasion";
}
void lagiacrus::defensiveAct(){
	evaded_ = false;
	defense_up = true;
}
string lagiacrus::defensiveString() const{
	return "Defense Curl";
}
int lagiacrus::getHealth() const{
	return my_health;
}

// Evasion was added to make battles a little more interesting. Chances of evasion will be small...
void lagiacrus::getHit(int damage){
	if(defense_up){
		my_health = my_health - (damage / 2);
	} else if(evaded_){
		my_health = my_health;
	} else{
		my_health = my_health - damage;
	}
}
void lagiacrus::resetHealth(){
	my_health = 500;
}
