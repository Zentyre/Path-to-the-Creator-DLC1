#include "Character.h"
#include "Player.h"
#include "Enemy.h"

Character::Character() {
	name = name;
	health = 25;
	attackPower = 1;
	lives = 1;
	maxhealth = 50;
	kills = 0;
	level = 0;
	defense = 0;
	baselevel = 0;
}
int Character::getclass() {
	return classtype;
}
int Character::getbaselevel() {
	return baselevel;
}
int Character::getattackPower() {
	return attackPower;
}
int Character::getdefense() {
	return defense;
}
int Character::gethealth() {
	return health;
}
int Character::getlevel() {
	return level + baselevel;
}
int Character::getkills() {
	return kills;
}
int Character::getlives() {
	return lives;
}
int Character::getmaxhealth() {
	return maxhealth;
}
string Character::getname() {
	return name;
}
int Character::incrementbaselevel(int amount) {
	baselevel = baselevel + amount;
	if (baselevel > 100 && incrementamount == 0) {
		incrementamount = 1;
		return baselevel = 100;
	}
	else if (baselevel > 200 && incrementamount == 1) {
		incrementamount = 2;
		return baselevel = 200;
	}
	else {
		return baselevel;
	}
}
int Character::incrementkills() {
	return kills++;
}
int Character::setkillplayer() {
	return killplayer = true;
}
void Character::itemuseinvispotion(Character* Target) {
	Target->takeDmg(Target->getmaxhealth());
	invisibilitypotion -= 1;
}
void Character::addlives(int extralives) {
	lives += extralives;
}
void Character::itemusemolotov(Character* Target) {
	int molotovdmg;
	molotovdmg = floor(Target->gethealth() * .6);
	Target->takeDmg(molotovdmg);
	cout << "You dealt " << molotovdmg << " damage using the molotov." << endl;
	cout << "The enemy has " << Target->gethealth() << " health remaining." << endl;
	cout << "------------------------------------------------" << endl;
	molotov -= 1;
}
void Character::takeDmg(int dmg) {
	dmg = ceil(dmg - defense);
	if (dmg < 0) {
		dmg = 0;
	}
	health -= dmg;
	if (health <= 0) {
		lives -= 1;
		if (lives > 0) {
			health = maxhealth - floor(baselevel * .8);
		}
	}
}
bool Character::isAlive() {
	if (lives <= 0 || killplayer == true) {
		return false;
	}
	else {
		return true;
	}
}