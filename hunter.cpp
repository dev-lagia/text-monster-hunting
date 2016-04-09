#include <iostream>
#include <string>
#include "hunter.h"
#include "enemy.h"


using namespace std;

hunter::hunter(string n){
	my_name = n;
	my_health = 150;
	defense_up = false;
	//evaded_ = false;
}
string hunter::getName() const{
	return my_name;
}
void hunter::setFireball(int fireball){
	my_fireballs = fireball;
}
int hunter::getFireball() const{
	cout << "You have " << my_fireballs << " fireballs left." << endl;
	return my_fireballs;
}
void hunter::strongAttack(enemy * monster){
	defense_up = false;
	if(my_fireballs <= 0){
		cout << "Sorry, you are out of fireballs." << endl;
	}else{
		monster->getHit(25); // At 10 fireballs per monster, this damage should be fine.
	}
}
string hunter::strongString() const{
	return "You used a fireball!";
}
void hunter::simpleAttack(enemy * monster){
	defense_up = false;
	monster->getHit(45); // Also fair, given the monster's health pool.
}
string hunter::simpleString() const{
	return "You swung you sword at the monster!";
}
void hunter::setPotions(int potions){
	my_potions = potions;
}
int hunter::getPotions() const{
	cout << "You have " << my_potions << " potions left." << endl;
	return my_potions;
}
void hunter::heal(int potions, enemy * monster){
	defense_up = false;
	if(potions <= 0){
		cout << "You don't have any potions left!" << endl;
	}else{
		monster->getHit(-25); // I hope this works.
	}
}
string hunter::healString() const{
	return "After consuming the potion, you flexed your arms with your newly rejuvinated stregnth.";
}
void hunter::specialAttack(enemy * monster){
	monster->getHit(0);
	cout << "Get out of here! How'd you even find this" << endl;
	// I need the hunter class to be fully compatible with the enemy class, else it won't work.
}
string hunter::specialString() const{
	return "I don't even know how you accessed this.";
}
void hunter::evasiveManouver(){
	cout << "No" << endl;
}
string hunter::evasiveString() const{
	return "No.";
}
void hunter::defensiveAct(){
	defense_up = true;
}
string hunter::defensiveString() const{
	return "You hold up your shield in anticipation.";
}
int hunter::getHealth() const{
	return my_health;
}

void hunter::getHit(int damage){
	if(defense_up){
		my_health = my_health - (damage / 2);
	} else{
		my_health = my_health - damage;
	}
}
void hunter::resetHealth(){
	my_health = 150;
}
