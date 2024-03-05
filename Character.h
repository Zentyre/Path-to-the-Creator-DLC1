#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <random>
#include <map>
using namespace std;
static random_device r;
class Character {
public:
	Character();
	string factionchoice = "";
	string name = "";
	string enemydefenseReduction = "";
	string getname();
	int level;
	int health;
	int attackPower;
	int defense;
	int maxhealth;
	int baselevel;
	int kills;
	int factionchoiceint = 0;
	int lives;
	int Goldloom = 0;
	int storetracker = 0;
	int elapsedTime = 0;
	int getclass();
	int setkillplayer();
	int getbaselevel();
	int getlives();
	int gethealth();
	int getdefense();
	int getattackPower();
	int getlevel();
	int incrementbaselevel(int amount);
	int incrementkills();
	int getkills();
	int getmaxhealth();
	int maxhealthtracker = 0;
	int classtype = 1;
	int invisibilitypotion = 0;
	int molotov = 0;
	int incrementamount = 0;
	bool trickstermovebool = false;
	bool warforgedmovebool = false;
	bool isAlive();
	bool killplayer = false;
	bool usinginvispotion = false;
	bool endlessmode = false;
	bool storymode = false;
	bool bossSpawned = false;
	void itemuseinvispotion(Character* Target);
	void itemusemolotov(Character* Target);
	void addlives(int extralives);
	virtual void attack(Character* Target) = 0;
	virtual void takeDmg(int d);
	void delay(int x) {
		this_thread::sleep_for(chrono::seconds(x));
	}
	string newName = "";
	int newHealth = 0;
	int newAttack = 0;
	int newDefense = 0;
	int newLives = 0;
	int newLevel = 0;
	int newMaxhealth = 0;
};