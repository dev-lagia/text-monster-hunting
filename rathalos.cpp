#include <string>
#include "rathalos.h"
#include "enemy.h"


using namespace std;

// Generally speaking, enemies (to the player) will have more health than the player.
rathalos::rathalos(string n){
	my_name = n;
	my_health = 425;
	defense_up = false;
	evaded_ = false;
}
string rathalos::getName() const{
	return my_name;
}

// The attacks will have values that reflect the player's health (which, at max will be 150), so not TOO much damage will be given.
void rathalos::strongAttack(enemy * monster){
	defense_up = false;
	evaded_ = false;
	monster->getHit(20);
}
string rathalos::strongString() const{
	return "Fireball";
}
void rathalos::simpleAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(15);
}
string rathalos::simpleString() const{
	return "Tail Whip";
}
void rathalos::specialAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(40); // We want this one to be REALLY devistating (while fair).
}
string rathalos::specialString() const{
	return "Poison Talons";
}
void rathalos::evasiveManouver(){
	defense_up = false;
	evaded_ = true;
}
string rathalos::evasiveString() const{
	return "Evasion";
}
void rathalos::defensiveAct(){
	evaded_ = false;
	defense_up = true;
}
string rathalos::defensiveString() const{
	return "Defense Curl";
}
int rathalos::getHealth() const{
	return my_health;
}

// Evasion was added to make battles a little more interesting. Chances of evasion will be small...
void rathalos::getHit(int damage){
	if(defense_up){
		my_health = my_health - (damage / 2);
	} else if(evaded_){
		my_health = my_health;
	} else{
		my_health = my_health - damage;
	}
}
void rathalos::resetHealth(){
	my_health = 425;
}
