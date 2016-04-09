#include <string>
#include "glavenus.h"
#include "enemy.h"


using namespace std;

// Generally speaking, enemies (to the player) will have more health than the player.
glavenus::glavenus(string n){
	my_name = n;
	my_health = 600;
	defense_up = false;
	evaded_ = false;
}
string glavenus::getName() const{
	return my_name;
}

// The attacks will have values that reflect the player's health (which, at max will be 150), so not TOO much damage will be given.
void glavenus::strongAttack(enemy * monster){
	defense_up = false;
	evaded_ = false;
	monster->getHit(35);
}
string glavenus::strongString() const{
	return "Explosive Fireball";
}
void glavenus::simpleAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(25);
}
string glavenus::simpleString() const{
	return "Tail Slam";
}
void glavenus::specialAttack(enemy * monster){
	evaded_ = false;
	defense_up = false;
	monster->getHit(50); // We want this one to be REALLY devistating (while fair).
}
string glavenus::specialString() const{
	return "Tail Spin";
}
void glavenus::evasiveManouver(){
	defense_up = false;
	evaded_ = true;
}
string glavenus::evasiveString() const{
	return "Evasion";
}
void glavenus::defensiveAct(){
	evaded_ = false;
	defense_up = true;
}
string glavenus::defensiveString() const{
	return "Guard";
}
int glavenus::getHealth() const{
	return my_health;
}

// Evasion was added to make battles a little more interesting. Chances of evasion will be small...
void glavenus::getHit(int damage){
	if(defense_up){
		my_health = my_health - (damage / 2);
	} else if(evaded_){
		my_health = my_health;
	} else{
		my_health = my_health - damage;
	}
}
void glavenus::resetHealth(){
	my_health = 600;
}
