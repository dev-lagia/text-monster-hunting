/******************************************
* Program by: Alex White
* Date Created: March 13, 2016
* Last Modified: March 16, 2016
*
* This is the main part of the "Hunter's
* Game" so to speak, where all essential
* game code will take place, such as user
* input and output to the console.
*
* This code is Creative Commons.
******************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <locale>
#include "enemy.h"
#include "lagiacrus.h"
#include "rathalos.h"
#include "zinogre.h"
#include "glavenus.h"
#include "magala.h"
#include "hunter.h"

using namespace std;

enemy* monster_hunt(enemy* monster, hunter* player);
//void print_result(enemy* attacker, enemy* defender, string attack, int health);

int main(void){
	string name;
	vector<enemy*> monsters(5);
	monsters[0] = new lagiacrus("Lagiacrus");
	monsters[1] = new rathalos("Rathalos");
	monsters[2] = new zinogre("Zinogre");
	monsters[3] = new glavenus("Glavenus");
	monsters[4] = new magala("Gore Magala");
	cout << "Enter a name for your hunter (no more than 1 word please)" << endl;
	cin >> name;
	hunter* player = new hunter(name);
	enemy* winner;
	//Debug code below. For testing purposes only.
/*	cout << "Who do you want to fight?" << endl;
	int fight;
	cin >> fight;
	if(fight == 1){
		winner = monster_hunt(monsters[0], player);
	}else if(fight == 2){
		winner = monster_hunt(monsters[1], player);
	}else if(fight == 3){
		winner = monster_hunt(monsters[2], player);
	}else if(fight == 4){
		winner = monster_hunt(monsters[3], player);
	}else if(fight == 5){
		winner = monster_hunt(monsters[4], player);
	}
	if(winner->getName() == player->getName()){
		cout << "SUCCESS!" << endl;
 	} else if(winner == NULL){
 		cout << "Huh?" << endl;
	} else{
		cout << "You Fainted..." << endl;
	}
*/	for(int x = 0; x <= int(monsters.size()) - 1; x++){
		winner = monster_hunt(monsters[x], player);
		if(winner->getName() != name){
			cout << monsters[x]->getName() << " has won the battle. You Fainted!" << endl << endl;
		} else if(winner = NULL){
			break;
		} else{
			cout << "Quest Complete, next hunt starts soon!" << endl << endl;
		}
	}
	cout << "Thank you for playing. Come again soon." << endl;
	return 0;
}
enemy* monster_hunt(enemy* monster, hunter* player){
	string input;
	int fireball = 10, potion = 6;
	monster->resetHealth();
	player->resetHealth();
	
	// So that potions and fireballs are automatically restocked.
	player->setPotions(potion);
	player->setFireball(fireball);
	
	cout << "Get ready to hunt a " << monster->getName() << endl;
	cout << "You go first." << endl;
	cout << "You have " << player->getHealth() << " health remaining." << endl;
	cout << monster->getName() << " has " << monster->getHealth() << " health remaining." << endl;
	while(player->getHealth() >= 1 && monster->getHealth() >= 1){
		try{
			player->getFireball();
			player->getPotions();
			cout << "You can do one of the following (lower case please): " << endl << "SWORD | FIREBALL | HEAL | SHIELD | EXIT" << endl << endl;
			cin >> input;
			//Player attacks first
			if(input == "sword"){
				player->simpleAttack(monster);
				cout << player->simpleString() << endl;
				cout << monster->getName() << " now has " << monster->getHealth() << " remaining" << endl << endl;	
			} else if(input == "fireball"){
				player->strongAttack(monster);
				cout << player->strongString() << endl << endl;
				fireball = fireball - 1;
				player->setFireball(fireball);
				cout << monster->getName() << " now has " << monster->getHealth() << " remaining" << endl << endl;
			} else if(input == "heal"){
				player->heal(potion, player);
				player->healString();
				if(potion != 0)
					potion = potion - 1;
				player->setPotions(potion);
				cout << "You now have " << player->getHealth() << " remaining" << endl << endl;
			} else if(input == "shield"){
				player->defensiveAct();
				cout << player->defensiveString() << endl << endl;
			} else if(input == "exit"){
				throw "Thank's for playing!";
			}
		}
		catch(...){
			//Exits program without a hitch.
			cerr << "Thank's for playing!" << endl;
			exit(0);
		}
			// So that a monster can't get an extra hit in post-mortem.
		if(monster->getHealth() >= 1){
			int monAtk = rand() % 100 + 1;
			if(monAtk >= 1 && monAtk <= 50){
				// 50% chance of a simple attack.
				monster->simpleAttack(player);
				cout << monster->getName() << " used " << monster->simpleString() << "!" << endl;
				cout << player->getName() << " has " << player->getHealth() << " remaining." << endl << endl;
			} else if(monAtk >= 51 && monAtk <= 70){
				// 20% chance of a strong attack
				monster->strongAttack(player);
				cout << monster->getName() << " used " << monster->strongString() << "!" << endl;
				cout << player->getName() << " has " << player->getHealth() << " remaining." << endl << endl;
			} else if(monAtk >= 71 && monAtk <= 90){
				// 20% chance of defending
				monster->defensiveAct();
				cout << monster->getName() << " used " << monster->defensiveString() << "! Defense raised!" << endl << endl;
			} else if(monAtk >= 91){
				// 10& chance of evading
				monster->evasiveManouver();
				cout << monster->getName() << " used " << monster->evasiveString() << "! Your attack WILL miss!" << endl << endl;
			}
		}
	}
	if(player->getHealth() >= 1 && monster->getHealth() < 1){
		enemy* winner = new hunter(player->getName());
		return winner;
	} else if(monster->getHealth() >= 1 && player->getHealth() < 1){
		return monster;
	}
}
