#include <string>
#include "magala.h"
#include "enemy.h"


using namespace std;

// Generally speaking, enemies (to the player) will have more health than the player.
magala::magala(string n){
	my_name = n;
	my_health = 450;
	defense_up = false;
	evaded_ = false;
}
string magala::getName() const{
	return my_name;
}

// The attacks will have values that reflect the player's health (which, at max will be 150), so not TOO much damage will be given.
void magala::strongAttack(enemy * monster){
	defense_up = false;
	evaded_ = false;
	monster->getHit(25);
}
string magala::strongString() const{
	return "Frenzy Ball";
}
void magala::simpleAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(10);
}
string magala::simpleString() const{
	return "Charge";
}
void magala::specialAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(50); // We want this one to be REALLY devistating (while fair).
}
string magala::specialString() const{
	return "Frenzy Explosion";
}
void magala::evasiveManouver(){
	defense_up = false;
	evaded_ = true;
}
string magala::evasiveString() const{
	return "Evasion";
}
void magala::defensiveAct(){
	evaded_ = false;
	defense_up = true;
}
string magala::defensiveString() const{
	return "Defense Curl";
}
int magala::getHealth() const{
	return my_health;
}

// Evasion was added to make battles a little more interesting. Chances of evasion will be small...
void magala::getHit(int damage){
	if(defense_up){
		my_health = my_health - (damage / 2);
	} else if(evaded_){
		my_health = my_health;
	} else{
		my_health = my_health - damage;
	}
}
void magala::resetHealth(){
	my_health = 450;
}
