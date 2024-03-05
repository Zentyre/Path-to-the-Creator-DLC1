#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "..//Steam/steam_api.h"
Player Knight("Player", 50, 25, 4, 0, 0, 1);
int endlessSpawn = 1, randomevent = 0, villagetracker = 0, chest = 0;
bool disableGeneration = false;
Enemy* generateEndlessEnemy(int baselevele, int hpe, int atke, int defe, int levele, int livese, int playerclasse) {
	int x = 1, xtracker = (baselevele - 250), endlesshealth = 500, endlessattack = 50, endlessdefense = 30, endlesslevel = levele, endlessmaxhealth;
	xtracker = floor(xtracker / 10);
	x = xtracker;
	endlesshealth = endlesshealth + (12 * x);
	endlessattack = endlessattack + (4 * x);
	endlessdefense = endlessdefense + (3 * x);
	endlessmaxhealth = endlesshealth;
	return new Enemy("Endless Enemy", endlesshealth, endlessattack, endlessdefense, endlesslevel, 1, endlessmaxhealth);
	endlessSpawn = 0;
}
Enemy* generateEnemy(int baselevel, int hp, int atk, int def, int level, int lives, int playerclass) {
	int x = 0, z = 0, enemyhp = 0, enemyatk = 0, enemylives = 0, enemydef = 0, enemylvl = 0, enemymaxh = 0;
	if (baselevel == 200) {
		x = 13;
	}
	else if (baselevel == 100) {
		x = 11;
	}
	else if (baselevel >= 101) {
		x = r() % 2 + 10;
	}
	else if (baselevel >= 80) {
		x = r() % 4 + 7;
	}
	else if (baselevel >= 70) {
		x = r() % 4 + 6;
	}
	else if (baselevel >= 60) {
		x = r() % 4 + 5;
	}
	else if (baselevel >= 50) {
		x = r() % 4 + 4;
	}
	else if (baselevel >= 40) {
		x = r() % 4 + 3;
	}
	else if (baselevel >= 30) {
		x = r() % 4 + 2;
	}
	else if (baselevel >= 20) {
		x = r() % 4 + 1;
	}
	else if (baselevel >= 10) {
		x = r() % 3;
	}
	else {
		x = r() % 2;
	}
	if (lives >= 2) {
		enemylives = ceil(lives * .5);
	}
	else {
		enemylives = 1;
	}
	enemylvl = level;
	if (Knight.endlessmode == true && Knight.getkills() > 250 && Knight.getkills() % 50 != 0) {
		generateEndlessEnemy(Knight.baselevel, Knight.health, Knight.attackPower, Knight.defense, Knight.level, Knight.lives, Knight.getclass());
	}
	if (Knight.endlessmode == true && Knight.getkills() > 250) {
		if (Knight.getkills() % 50 == 0) {
			enemyhp = ceil(hp * 1.25);
			enemyatk = ceil(def * 2);
			enemydef = ceil(atk * .8);
			enemylives = ceil(lives * .5);
			enemylvl = level;
			enemymaxh = enemyhp;
			x = 12;
		}
	}
	if (endlessSpawn == 1) {
		switch (x) {
		case 0:
			return new Enemy("Shroom", 20, 3, 0, 1, 1, 20);
			break;
		case 1:
			return new Enemy("Shroom Knight", 25, 4, 0, 1, 2, 25);
			break;
		case 2:
			return new Enemy("Shroom ArchKnight", 30, 5, 2, enemylives, enemylvl, 30);
			break;
		case 3:
			return new Enemy("Noble Shroom", 35, 7, 4, enemylives, enemylvl, 35);
			break;
		case 4:
			return new Enemy("Royal Shroom", 45, 10, 7, enemylives, enemylvl, 45);
			break;
		case 5:
			return new Enemy("Princess Slime", 70, 13, 10, enemylives, enemylvl, 70);
			break;
		case 6:
			return new Enemy("Prince Shroom", 85, 15, 16, enemylives, enemylvl, 85);
			break;
		case 7:
			return new Enemy("King Shroom", 115, 18, 19, enemylives, enemylvl, 115);
			break;
		case 8:
			return new Enemy("Emperor Shroom", 150, 22, 22, enemylives, enemylvl, 150);
			break;
		case 9:
			return new Enemy("Leader Shroom", 170, 25, 27, enemylives, enemylvl, 170);
			break;
		case 10:
			return new Enemy("Divine Shroom", 200, 30, 30, enemylives, enemylvl, 200);
			break;
		case 11:
			cout << "--A boss has appeared!--" << endl;
			return new Enemy("Boss Shroom", 250, 37, 35, enemylives, enemylvl, 250);
			Knight.bossSpawned = true;
			break;
		case 12:
			cout << "--An endless boss has arrived...--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Jock Mushroom", enemyhp, enemyatk, enemydef, enemylives, enemylvl, enemymaxh);
			break;
		default:
			cout << "The creator has arrived...I wish you luck." << endl;
			Knight.bossSpawned = true;
			return new Enemy("Creator Shroom", 1000, 50, 45, enemylives, enemylvl, 10000);
			break;
		}
	}
	endlessSpawn = 1;
}
Enemy* generateEnemy2(int baselevel2, int hp2, int atk2, int def2, int level2, int lives2, int playerclass2) {
	int x = 0, enemyhp2 = 0, enemyatk2 = 0, enemylives2 = 0, enemydef2 = 0, enemylvl2 = 0, enemymaxh2 = 0;
	if (baselevel2 == 200) {
		x = 13;
	}
	else if (baselevel2 == 100) {
		x = 11;
	}
	else if (baselevel2 >= 101) {
		x = r() % 4 + 8;
	}
	else if (baselevel2 >= 80) {
		x = r() % 4 + 7;
	}
	else if (baselevel2 >= 70) {
		x = r() % 4 + 6;
	}
	else if (baselevel2 >= 60) {
		x = r() % 4 + 5;
	}
	else if (baselevel2 >= 50) {
		x = r() % 4 + 4;
	}
	else if (baselevel2 >= 40) {
		x = r() % 4 + 3;
	}
	else if (baselevel2 >= 30) {
		x = r() % 4 + 2;
	}
	else if (baselevel2 >= 20) {
		x = r() % 4 + 1;
	}
	else if (baselevel2 >= 10) {
		x = r() % 3;
	}
	else {
		x = r() % 2;
	}
	if (lives2 >= 2) {
		enemylives2 = ceil(lives2 * .5);
	}
	else {
		enemylives2 = 1;
	}
	enemylvl2 = level2;
	if (Knight.endlessmode == true && Knight.getkills() > 250 && Knight.getkills() % 50 != 0) {
		generateEndlessEnemy(Knight.baselevel, Knight.health, Knight.attackPower, Knight.defense, Knight.level, Knight.lives, Knight.getclass());
	}
	if (Knight.endlessmode == true && Knight.getkills() > 250) {
		if (Knight.getkills() % 50 == 0) {
			enemyhp2 = ceil(hp2 * 1.25);
			enemyatk2 = ceil(def2 * 2);
			enemydef2 = ceil(atk2 * .8);
			enemylives2 = ceil(lives2 * .5);
			enemylvl2 = level2;
			enemymaxh2 = enemyhp2;
			x = 12;
		}
	}
	if (endlessSpawn == 1) {
		switch (x) {
		case 0:
			return new Enemy("Slime", 20, 1, 0, 1, 0, 20);
			break;
		case 1:
			return new Enemy("Epic Slime", 25, 1, 0, 1, 0, 25);
			break;
		case 2:
			return new Enemy("Superior Slime", 30, 5, 2, enemylives2, enemylvl2, 30);
			break;
		case 3:
			return new Enemy("Super Slime", 35, 7, 4, enemylives2, enemylvl2, 35);
			break;
		case 4:
			return new Enemy("Incredible Slime", 45, 10, 7, enemylives2, enemylvl2, 45);
			break;
		case 5:
			return new Enemy("Superb Slime", 70, 13, 10, enemylives2, enemylvl2, 70);
			break;
		case 6:
			return new Enemy("King Slime", 85, 15, 16, enemylives2, enemylvl2, 85);
			break;
		case 7:
			return new Enemy("Demon Slime", 115, 18, 19, enemylives2, enemylvl2, 115);
			break;
		case 8:
			return new Enemy("Overlord Slime", 150, 22, 22, enemylives2, enemylvl2, 150);
			break;
		case 9:
			return new Enemy("Universal Super Slime", 170, 25, 27, enemylives2, enemylvl2, 170);
			break;
		case 10:
			return new Enemy("Godly Slime", 200, 30, 30, enemylives2, enemylvl2, 200);
			break;
		case 11:
			cout << "--A boss has appeared!--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Boss Slime", 250, 37, 35, enemylives2, enemylvl2, 250);
			break;
		case 12:
			cout << "--An endless mode boss has arrived...--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Jock Slime", enemyhp2, enemyatk2, enemydef2, enemylives2, enemylvl2, enemymaxh2);
			break;
		default:
			cout << "The creator has arrived...I wish you luck." << endl;
			Knight.bossSpawned = true;
			return new Enemy("Creator Slime", 1000, 50, 45, enemylives2, enemylvl2, 1000);
			break;
		}
	}
	endlessSpawn = 1;
}
Enemy* generateEnemy3(int baselevel3, int hp3, int atk3, int def3, int level3, int lives3, int playerclass3) {
	int x = 0, enemyhp3 = 0, enemyatk3 = 0, enemylives3 = 0, enemydef3 = 0, enemylvl3 = 0, enemymaxh3 = 0;
	if (baselevel3 == 200) {
		x = 13;
	}
	else if (baselevel3 == 100) {
		x = 11;
	}
	else if (baselevel3 >= 101) {
		x = r() % 4 + 8;
	}
	else if (baselevel3 >= 80) {
		x = r() % 4 + 7;
	}
	else if (baselevel3 >= 70) {
		x = r() % 4 + 6;
	}
	else if (baselevel3 >= 60) {
		x = r() % 4 + 5;
	}
	else if (baselevel3 >= 50) {
		x = r() % 4 + 4;
	}
	else if (baselevel3 >= 40) {
		x = r() % 4 + 3;
	}
	else if (baselevel3 >= 30) {
		x = r() % 4 + 2;
	}
	else if (baselevel3 >= 20) {
		x = r() % 4 + 1;
	}
	else if (baselevel3 >= 10) {
		x = r() % 3;
	}
	else {
		x = r() % 2;
	}
	if (lives3 >= 2) {
		enemylives3 = ceil(lives3 * .5);
	}
	else {
		enemylives3 = 1;
	}
	enemylvl3 = level3;
	if (Knight.endlessmode == true && Knight.getkills() > 250 && Knight.getkills() % 50 != 0) {
		generateEndlessEnemy(Knight.baselevel, Knight.health, Knight.attackPower, Knight.defense, Knight.level, Knight.lives, Knight.getclass());
	}
	if (Knight.endlessmode == true && Knight.getkills() > 250) {
		if (Knight.getkills() % 50 == 0) {
			enemyhp3 = ceil(hp3 * 1.25);
			enemyatk3 = ceil(def3 * 2);
			enemydef3 = ceil(atk3 * .8);
			enemylives3 = ceil(lives3 * .5);
			enemylvl3 = level3;
			enemymaxh3 = enemyhp3;
			x = 12;
		}
	}
	if (endlessSpawn == 1) {
		switch (x) {
		case 0:
			return new Enemy("Croc", 20, 3, 0, 1, 0, 20);
			break;
		case 1:
			return new Enemy("Croc Pot", 25, 4, 0, 1, 0, 25);
			break;
		case 2:
			return new Enemy("Mini Croc", 30, 5, 2, enemylives3, enemylvl3, 30);
			break;
		case 3:
			return new Enemy("Big Croc", 35, 7, 4, enemylives3, enemylvl3, 35);
			break;
		case 4:
			return new Enemy("Land Croc", 45, 10, 7, enemylives3, enemylvl3, 45);
			break;
		case 5:
			return new Enemy("Sharptooth Croc", 70, 13, 10, enemylives3, enemylvl3, 70);
			break;
		case 6:
			return new Enemy("King Croc", 85, 15, 16, enemylives3, enemylvl3, 85);
			break;
		case 7:
			return new Enemy("Develish Croc", 115, 18, 19, enemylives3, enemylvl3, 115);
			break;
		case 8:
			return new Enemy("Crocodile Dundee", 150, 22, 22, enemylives3, enemylvl3, 150);
			break;
		case 9:
			return new Enemy("Killer Croc", 170, 25, 27, enemylives3, enemylvl3, 170);
			break;
		case 10:
			return new Enemy("Transcendent Croc", 200, 30, 30, enemylives3, enemylvl3, 200);
			break;
		case 11:
			cout << "--A boss has appeared!--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Florida Croc", 250, 37, 35, enemylives3, enemylvl3, 250);
			break;
		case 12:
			cout << "--An endless mode boss has arrived...--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Jock Croc", enemyhp3, enemyatk3, enemydef3, enemylives3, enemylvl3, enemymaxh3);
			break;
		default:
			cout << "The creator has arrived...I wish you luck." << endl;
			Knight.bossSpawned = true;
			return new Enemy("Creator Croc", 1000, 50, 45, enemylives3, enemylvl3, 1000);
			break;
		}
	}
	endlessSpawn = 1;
}
Enemy* generateEnemy4(int baselevel4, int hp4, int atk4, int def4, int level4, int lives4, int playerclass4) {
	int x = 0, enemyhp4 = 0, enemyatk4 = 0, enemylives4 = 0, enemydef4 = 0, enemylvl4 = 0, enemymaxh4 = 0;
	if (baselevel4 == 200) {
		x = 13;
	}
	else if (baselevel4 == 100) {
		x = 11;
	}
	else if (baselevel4 >= 101) {
		x = r() % 4 + 8;
	}
	else if (baselevel4 >= 80) {
		x = r() % 4 + 7;
	}
	else if (baselevel4 >= 70) {
		x = r() % 4 + 6;
	}
	else if (baselevel4 >= 60) {
		x = r() % 4 + 5;
	}
	else if (baselevel4 >= 50) {
		x = r() % 4 + 4;
	}
	else if (baselevel4 >= 40) {
		x = r() % 4 + 3;
	}
	else if (baselevel4 >= 30) {
		x = r() % 4 + 2;
	}
	else if (baselevel4 >= 20) {
		x = r() % 4 + 1;
	}
	else if (baselevel4 >= 10) {
		x = r() % 3;
	}
	else {
		x = r() % 2;
	}
	if (lives4 >= 2) {
		enemylives4 = ceil(lives4 * .5);
	}
	else {
		enemylives4 = 1;
	}
	enemylvl4 = level4;
	if (Knight.endlessmode == true && Knight.getkills() > 250 && Knight.getkills() % 50 != 0) {
		generateEndlessEnemy(Knight.baselevel, Knight.health, Knight.attackPower, Knight.defense, Knight.level, Knight.lives, Knight.getclass());
	}
	if (Knight.endlessmode == true && Knight.getkills() > 250) {
		if (Knight.getkills() % 50 == 0) {
			enemyhp4 = ceil(hp4 * 1.25);
			enemyatk4 = ceil(def4 * 2);
			enemydef4 = ceil(atk4 * .8);
			enemylives4 = ceil(lives4 * .5);
			enemylvl4 = level4;
			enemymaxh4 = enemyhp4;
			x = 12;
		}
	}
	if (endlessSpawn == 1) {
		switch (x) {
		case 0:
			return new Enemy("Roo", 20, 3, 0, 1, 0, 20);
			break;
		case 1:
			return new Enemy("Joey Roo", 25, 4, 0, 1, 0, 25);
			break;
		case 2:
			return new Enemy("Kangaroo", 30, 5, 2, enemylives4, enemylvl4, 30);
			break;
		case 3:
			return new Enemy("Mother Roo", 35, 7, 4, enemylives4, enemylvl4, 35);
			break;
		case 4:
			return new Enemy("Boxer Roo", 45, 10, 7, enemylives4, enemylvl4, 45);
			break;
		case 5:
			return new Enemy("Jumping Roo", 70, 13, 10, enemylives4, enemylvl4, 70);
			break;
		case 6:
			return new Enemy("Killer Roo", 85, 15, 16, enemylives4, enemylvl4, 85);
			break;
		case 7:
			return new Enemy("Crackhead Roo", 115, 18, 19, enemylives4, enemylvl4, 115);
			break;
		case 8:
			return new Enemy("Aussie Roo", 150, 22, 22, enemylives4, enemylvl4, 150);
			break;
		case 9:
			return new Enemy("Jacked Roo", 170, 25, 27, enemylives4, enemylvl4, 170);
			break;
		case 10:
			return new Enemy("Paragon Roo", 200, 30, 30, enemylives4, enemylvl4, 200);
			break;
		case 11:
			cout << "--A boss has appeared!--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Boomaroo", 250, 37, 35, enemylives4, enemylvl4, 250);
			break;
		case 12:
			cout << "--An endless mode boss has arrived...--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Jock Roo", enemyhp4, enemyatk4, enemydef4, enemylives4, enemylvl4, enemymaxh4);
			break;
		default:
			cout << "The creator has arrived...I wish you luck." << endl;
			Knight.bossSpawned = true;
			return new Enemy("Creator Kangaroo", 1000, 50, 45, enemylives4, enemylvl4, enemymaxh4);
			break;
		}
	}
	endlessSpawn = 1;
}
Enemy* generateEnemy5(int baselevel5, int hp5, int atk5, int def5, int level5, int lives5, int playerclass5) {
	int x = 0, enemyhp5 = 0, enemyatk5 = 0, enemylives5 = 0, enemydef5 = 0, enemylvl5 = 0, enemymaxh5 = 0;
	if (baselevel5 == 200) {
		x = 13;
	}
	else if (baselevel5 == 100) {
		x = 11;
	}
	else if (baselevel5 >= 101) {
		x = r() % 4 + 8;
	}
	else if (baselevel5 >= 80) {
		x = r() % 4 + 7;
	}
	else if (baselevel5 >= 70) {
		x = r() % 4 + 6;
	}
	else if (baselevel5 >= 60) {
		x = r() % 4 + 5;
	}
	else if (baselevel5 >= 50) {
		x = r() % 4 + 4;
	}
	else if (baselevel5 >= 40) {
		x = r() % 4 + 3;
	}
	else if (baselevel5 >= 30) {
		x = r() % 4 + 2;
	}
	else if (baselevel5 >= 20) {
		x = r() % 4 + 1;
	}
	else if (baselevel5 >= 10) {
		x = r() % 3;
	}
	else {
		x = r() % 2;
	}
	if (lives5 >= 2) {
		enemylives5 = ceil(lives5 * .5);
	}
	else {
		enemylives5 = 1;
	}
	enemylvl5 = level5;
	if (Knight.endlessmode == true && Knight.getkills() > 250 && Knight.getkills() % 50 != 0) {
		generateEndlessEnemy(Knight.baselevel, Knight.health, Knight.attackPower, Knight.defense, Knight.level, Knight.lives, Knight.getclass());
	}
	if (Knight.endlessmode == true && Knight.getkills() > 250) {
		if (Knight.getkills() % 50 == 0) {
			enemyhp5 = ceil(hp5 * 1.25);
			enemyatk5 = ceil(def5 * 2);
			enemydef5 = ceil(atk5 * .8);
			enemylives5 = ceil(lives5 * .5);
			enemylvl5 = level5;
			enemymaxh5 = enemyhp5;
			x = 12;
		}
	}
	if (endlessSpawn == 1) {
		switch (x) {
		case 0:
			return new Enemy("Skeleton", 20, 3, 0, 1, 0, 20);
			break;
		case 1:
			return new Enemy("Skellie", 25, 4, 0, 1, 0, 25);
			break;
		case 2:
			return new Enemy("Enchanted Bow Skeleton", 30, 5, 2, enemylives5, enemylvl5, 30);
			break;
		case 3:
			return new Enemy("Aimbot Skellie", 35, 7, 4, enemylives5, enemylvl5, 35);
			break;
		case 4:
			return new Enemy("Sharpshooter Skeleton", 45, 10, 7, enemylives5, enemylvl5, 45);
			break;
		case 5:
			return new Enemy("Bony Bill", 70, 13, 10, enemylives5, enemylvl5, 70);
			break;
		case 6:
			return new Enemy("Crazy Bones", 85, 15, 16, enemylives5, enemylvl5, 85);
			break;
		case 7:
			return new Enemy("Broken Bone Skeleton", 115, 18, 19, enemylives5, enemylvl5, 115);
			break;
		case 8:
			return new Enemy("Boogie Bone", 150, 22, 22, enemylives5, enemylvl5, 150);
			break;
		case 9:
			return new Enemy("Ranked Skeleton", 170, 25, 27, enemylives5, enemylvl5, 170);
			break;
		case 10:
			return new Enemy("Captain Skellie", 200, 30, 30, enemylives5, enemylvl5, 200);
			break;
		case 11:
			cout << "--A boss has appeared!--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Super Skellie", 250, 37, 35, enemylives5, enemylvl5, 250);
			break;
		case 12:
			cout << "--An endless mode boss has arrived...--" << endl;
			Knight.bossSpawned = true;
			return new Enemy("Jock Skeleton", enemyhp5, enemyatk5, enemydef5, enemylives5, enemylvl5, enemymaxh5);
			break;
		default:
			cout << "The creator has arrived...I wish you luck." << endl;
			Knight.bossSpawned = true;
			return new Enemy("Creator Skeleton", 1000, 50, 45, enemylives5, enemylvl5, 1000);
			break;
		}
	}
	endlessSpawn = 1;
}
static void gameplay() {
	string modeChoice = "";
	cout << "Would you like to play in story mode or compete in... endless mode?" << endl;
	while (true) {
		cin >> modeChoice;
		std::transform(modeChoice.begin(), modeChoice.end(), modeChoice.begin(), ::tolower);
		if (modeChoice == "story") {
			Knight.storymode = true;
			break;
		}
		else if (modeChoice == "endless") {
			Knight.endlessmode = true;
			break;
		}
		else {
			cout << "Try again. Type endless or story." << endl;
		}
	}
	while (Knight.storymode == true) {
		cout << "Welcome to Evil Conquest!" << endl;
		cout << "Your objective is to kill the operator of all evil...the Creator!" << endl;
		cout << "You start at level one, for every kill you go up a level and gain more damage (Base attack damage + level)" << endl;
		cout << "--Level can only add up to 30 damage and/or healing--(Level gained from items does affect this)" << endl;
		cout << "At levels 15, 25, 50 and 100, you gain new abilities. At level 200 you fight the final boss(Level gained from items does not affect this)" << endl;
		cout << "I wish you well on your conquest." << endl;
		cout << endl;
		cout << "Would you like to be a 1- Knight, 2- Executioner, 3- Soulweaver, 4- Warforged Engineer, 5- Dreadnought, 6- Trickster or 7- Random?" << endl;
		cout << "-Knight has average health and damage-" << endl << "-Executioner has a lot less health and a lot more damage-" << endl << "-Soulweaver starts with 1 extra life for less attack/health and a special move-" << endl << "-Warforged Engineer has slightly higher health for slightly lower damage and a special move-" << endl << "-Dreadnought has a lot more health / maxhealth and a lot less damage-" << endl << "-Trickster has a little less health for barely more attack, and a special move.-" << endl;
		int cinFailchoice = 0, classcurrency = 0, playerclasschoiceint = 0;
		string playerclasschoice = "";
		cin >> ws;
		getline(cin, playerclasschoice);
		if (playerclasschoice == "1") {
			cout << "You chose Knight!" << endl;
		}
		else if (playerclasschoice == "2") {
			Knight.playerclassexecutioner();
			cout << "You chose Executioner!" << endl;
		}
		else if (playerclasschoice == "3") {
			Knight.playerclasssoulweaver();
			cout << "You chose Soulweaver!" << endl;
		}
		else if (playerclasschoice == "4") {
			Knight.playerclasswarforged();
			cout << "You chose Warforged Engineer!" << endl;
		}
		else if (playerclasschoice == "5") {
			Knight.playerclassdreadnought();
			cout << "You chose Dreadnought!" << endl;
		}
		else if (playerclasschoice == "6") {
			Knight.playerclasstrickster();
			cout << "You chose Trickster!" << endl;
		}
		else if (playerclasschoice == "7") {
			playerclasschoiceint = r() % 6 + 1;
			if (playerclasschoiceint == 1) {
				cout << "You were given Knight." << endl;
			}
			else if (playerclasschoiceint == 2) {
				Knight.playerclassexecutioner();
				cout << "You were given Executioner." << endl;
			}
			else if (playerclasschoiceint == 3) {
				Knight.playerclasssoulweaver();
				cout << "You were given Soulweaver." << endl;
			}
			else if (playerclasschoiceint == 4) {
				Knight.playerclasswarforged();
				cout << "You were given Warforged Engineer." << endl;
			}
			else if (playerclasschoiceint == 5) {
				Knight.playerclassdreadnought();
				cout << "You were given Dreadnought." << endl;
			}
			else if (playerclasschoiceint == 6) {
				Knight.playerclasstrickster();
				cout << "You were given Trickster." << endl;
			}
		}
		else {
			cout << "You chose nothing so I will choose for you." << endl;
			playerclasschoiceint = r() % 6 + 1;
			if (playerclasschoiceint == 1) {
				cout << "You were given Knight." << endl;
			}
			else if (playerclasschoiceint == 2) {
				Knight.playerclassexecutioner();
				cout << "You were given Executioner." << endl;
			}
			else if (playerclasschoiceint == 3) {
				Knight.playerclasssoulweaver();
				cout << "You were given Soulweaver." << endl;
			}
			else if (playerclasschoiceint == 4) {
				Knight.playerclasswarforged();
				cout << "You were given Warforged Engineer." << endl;
			}
			else if (playerclasschoiceint == 5) {
				Knight.playerclassdreadnought();
				cout << "You were given Dreadnought." << endl;
			}
			else if (playerclasschoiceint == 6) {
				Knight.playerclasstrickster();
				cout << "You were given Trickster." << endl;
			}
		}
		cout << "What would you like me to call you?" << endl;
		cin >> ws;
		getline(cin, Knight.name);
		cout << "Your name is " << Knight.getname() << "?" << endl << "Y/N" << endl;
		string acceptname = "";
		cin >> acceptname;
		if (acceptname == "Y" || acceptname == "y") {
			cout << "Welcome " << Knight.getname() << "!" << " I hope you are prepared for this treacherous journey..." << endl;
		}
		else if (acceptname == "N" || acceptname == "n") {
			cout << "Well come on then, make up your mind dude. I don't have all day " << "Lets try this again, but this is your last chance." << endl;
			cout << endl;
			cout << "What would you like me to call you?" << endl;
			cin >> Knight.name;
			cout << "Welcome " << Knight.getname() << "!" << " I hope you are prepared for this treacherous journey. Based on how long it took you to pick a name, for your sake, I would recommend turning around." << endl;
			cout << "Turn around? Y/N" << endl;
			string turnaround = "";
			cin >> turnaround;
			if (turnaround == "Y" || turnaround == "y") {
				Knight.setkillplayer();
				Knight.isAlive();
			}
			else if (turnaround == "N" || turnaround == "n") {
				cout << "Good luck kid, you need it" << endl;
			}
			else {
				cout << "Nice typo, I'm not even going to give you another chance" << endl;
				Knight.setkillplayer();
				Knight.isAlive();
			}
		}
		else {
			cout << "That wasn't a yes or a no, did you pass kindergarten?" << endl;
			string doesnothing = "";
			cin >> doesnothing;
			cout << "I dont even care, whatever you just entered did absolutely nothing. You're stuck with the name you gave me before now." << endl;
		}
		cout << "Where would you like to journey " << Knight.getname() << " ?" << endl;
		cout << "-1-Mushroom Kingdom-" << endl;
		cout << "-2-Gooey Glade-" << endl;
		cout << "-3-Croc Isle-" << endl;
		cout << "-4-Hopscotch Highlands-" << endl;
		cout << "-5-Skeletal Sanctum-" << endl;
		string areachoice = "";
		int areachoiceint = 0;
		cin >> ws;
		getline(cin, areachoice);
		std::transform(areachoice.begin(), areachoice.end(), areachoice.begin(), ::tolower);
		if (areachoice == "mushroom kingdom" || areachoice == "1") {
			cout << endl;
			cout << "-Welcome to the happy Kingdom of the Mushrooms! Normally you would be welcomed by, well a mushroom, but right now they are being invaded. Go get the invaders!-" << endl << endl;
			areachoiceint = 1;
		}
		else if (areachoice == "gooey glade" || areachoice == "2") {
			cout << endl;
			cout << "-Welcome to the uneasy feeling area of the slimes. Good Luck Surviving!-" << endl << endl;
			areachoiceint = 2;
		}
		else if (areachoice == "croc isle" || areachoice == "3") {
			cout << endl;
			cout << "-Welcome to the land of the crocs. Go find that croc king!-" << endl << endl;
			areachoiceint = 3;
		}
		else if (areachoice == "hopscotch highlands" || areachoice == "4") {
			cout << endl;
			cout << "-Welcome to the land of the kangaroos, attack that zoo owner!-" << endl << endl;
			areachoiceint = 4;
		}
		else if (areachoice == "skeletal sanctum" || areachoice == "5") {
			cout << endl;
			cout << "-Welcome to the graveyeard of your dead family...just kidding. Look out there's a skeleton!-" << endl << endl;
			areachoiceint = 5;
		}
		else {
			cout << "That area doesn't exist so I guess I'll choose for you" << endl;
			int x = 0;
			x = r() % 5 + 1;
			switch (x) {
			case 0:
				if (cin.fail()) {
					cout << endl;
					cout << "----------------------" << endl;
					cout << "I chose an area for you." << endl;
					cout << "----------------------" << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					areachoiceint = r() % 5 + 1;
					break;
				}
			case 1:
				areachoice = "Mushroom Kingdom";
				cout << endl;
				cout << "-Welcome to the happy Kingdom of the Mushrooms! Normally you would be welcomed by, well a mushroom, but right now they are being invaded. Go get them!-" << endl << endl;
				areachoiceint = 1;
				break;
			case 2:
				areachoice = "Gooey Glade";
				cout << endl;
				cout << "-Welcome to the uneasy feeling area of the slimes. Good Luck Surviving!-" << endl << endl;
				areachoiceint = 2;
				break;
			case 3:
				areachoice = "Croc Isle";
				cout << endl;
				cout << "-Welcome to the land of the crocs. Go find that croc king!-" << endl << endl;
				areachoiceint = 3;
				break;
			case 4:
				areachoice = "Hopscotch Highlands";
				cout << endl;
				cout << "-Welcome to the land of the kangaroos, attack that zoo owner!-" << endl << endl;
				areachoiceint = 4;
				break;
			case 5:
				areachoice = "Skeletal Sanctum";
				cout << endl;
				cout << "-Welcome to the graveyeard of your dead family...just kidding. Look out there's a skeleton!-" << endl << endl;
				areachoiceint = 5;
				break;
			default:
				if (cin.fail()) {
					cout << endl;
					cout << "----------------------" << endl;
					cout << "I chose an area for you." << endl;
					cout << "----------------------" << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					areachoiceint = r() % 5 + 1;
					break;
				}
			}
		}
		Enemy* Slime = nullptr;
		if (areachoiceint == 1) {
			Slime = generateEnemy(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 2) {
			Slime = generateEnemy2(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 3) {
			Slime = generateEnemy3(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 4) {
			Slime = generateEnemy4(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 5) {
			Slime = generateEnemy5(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}

		while (Knight.isAlive() && Slime->isAlive()) {
			Knight.checkitems();
			Knight.attack(Slime);
			if (Slime->gethealth() <= 0 && Knight.usinginvispotion == false) {
				cout << Slime->getname() << " has 0 health remaining." << endl;
			}
			else if (Slime->gethealth() > 0 && Knight.usinginvispotion == false && Knight.trickstermovebool == false) {
				cout << Slime->getname() << " has " << Slime->gethealth() << " health remaining." << endl;
			}
			cout << "-----------------------------------------------" << endl;
			Slime->attack(&Knight);
			if (Knight.gethealth() <= 0) {
				cout << Knight.getname() << ", you have 0 health remaining." << endl;
			}
			else if (Knight.gethealth() > 0 && Knight.usinginvispotion == false) {
				cout << Knight.getname() << ", you have " << Knight.gethealth() << " health remaining." << endl;
			}
			cout << "-----------------------------------------------" << endl;
			if (!Slime->isAlive()) {
				if (Knight.usinginvispotion == true) {
					delete Slime;
					cout << "You have escaped from this enemy using your invisibility. You will get no rewards for this escape." << endl;
					if (areachoiceint == 1) {
						Slime = generateEnemy(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 2) {
						Slime = generateEnemy2(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 3) {
						Slime = generateEnemy3(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 4) {
						Slime = generateEnemy4(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 5) {
						Slime = generateEnemy5(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					int enemyrandommessage = 0;
					enemyrandommessage = r() % 5;
					if (enemyrandommessage == 0) {
						cout << "A new " << Slime->getname() << " has appeared, stab it!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 1) {
						cout << "A " << Slime->getname() << " is approaching you! BE wary." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 2) {
						cout << "A " << Slime->getname() << " is preparing to attack, CHARGE!!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 3) {
						cout << "Reinfocements are approaching, be careful!" << endl;
						cout << "A " << Slime->getname() << " has appeared." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 4) {
						cout << "This " << Slime->getname() << " seems mad that you killed his friend." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					Knight.usinginvispotion = false;
				}
				else if (Knight.usinginvispotion == false) {
					delete Slime;
					classcurrency += 1;
					if (classcurrency == 50 || classcurrency == 100 || classcurrency == 150) {
						cout << "Which stat would you like to upgrade? (1=hp, 2=atk, 3=def, 4=lvl, 5=extra life) *Note* Only hp can be upgraded more than once." << endl;
						int stat = 0;
						cin >> stat;
						switch (stat) {
						case 1:
							Knight.maxhealthupgrade = true;
							cout << "You now have " << Knight.gethealth() << " health." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 2:
							Knight.attackupgrade = true;
							cout << "You now have " << Knight.getattackPower() << " attack." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 3:
							Knight.defenseupgrade = true;
							cout << "You now have " << Knight.getdefense() << " defense." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 4:
							Knight.levelupgrade = true;
							cout << "You are now level " << Knight.getlevel() << "." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 5:
							Knight.addlives(1);
							cout << "You now have " << Knight.getlives() << " lives" << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						default:
							cout << "That choice doesn't exist, I'll choose for you." << endl;
							int x = 0;
							x = r() % 5 + 1;
							if (x == 1) {
								Knight.maxhealthupgrade = true;
							}
							else if (x == 2) {
								Knight.attackupgrade = true;
							}
							else if (x == 3) {
								Knight.defenseupgrade = true;
							}
							else if (x == 4) {
								Knight.levelupgrade = true;
							}
							else {
								Knight.addlives(1);
							}
							break;
						}
					}
					else if (classcurrency == 20 || classcurrency == 40 || classcurrency == 60 || classcurrency == 80 || classcurrency == 100 || classcurrency == 120 || classcurrency == 140 || classcurrency == 160 || classcurrency == 180 && Knight.playercompanion == true) {
						cout << "You have found a rare treasure!" << endl;
						int treasure;
						treasure = r() % 99 + 1;
						if (treasure <= 30) {
							Knight.helmet = true;
							cout << "You got a fancy hat.";
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 30 && treasure <= 60) {
							Knight.chestplate = true;
							cout << "You have acquired a weird robe.";
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 61 && treasure <= 90) {
							Knight.boots = true;
							cout << "You put on some cool shoes.";
							cout << endl;
							treasure = 0;
						}
						else {
							int legend;
							legend = r() % 3;
							if (legend == 0 && Knight.vladimirsArmor == false) {
								cout << "You acquired the armor of the legend...Vladimir!" << endl;
								Knight.vladimirsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 1 && Knight.lockhartsArmor == false) {
								cout << "You acquired the armor of the legend...Lockhart!" << endl;
								Knight.lockhartsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 2 && Knight.narsosArmor == false) {
								cout << "You acquired the armor of the legend...Narso!" << endl;
								Knight.narsosArmor = true;
								cout << endl;
								treasure = 0;
							}
						}
					}
					else if (classcurrency == 20 || classcurrency == 40 || classcurrency == 60 || classcurrency == 80 || classcurrency == 100 || classcurrency == 120 || classcurrency == 140 || classcurrency == 160 || classcurrency == 180) {
						cout << "You have found a rare treasure!" << endl;
						int treasure;
						treasure = r() % 99 + 1;
						if (treasure <= 33) {
							Knight.helmet = true;
							cout << "You got a fancy hat." << endl;
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 33 && treasure <= 66) {
							Knight.chestplate = true;
							cout << "You have acquired a weird robe." << endl;
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 66 && treasure <= 99) {
							Knight.boots = true;
							cout << "You put on some cool shoes." << endl;
							cout << endl;
							treasure = 0;
						}
						else {
							int legend;
							legend = r() % 3;
							if (legend == 0 && Knight.vladimirsArmor == false) {
								cout << "You acquired the armor of the legend...Vladimir!" << endl;
								Knight.vladimirsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 1 && Knight.lockhartsArmor == false) {
								cout << "You acquired the armor of the legend...Lockhart!" << endl;
								Knight.lockhartsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 2 && Knight.narsosArmor == false) {
								cout << "You acquired the armor of the legend...Narso!" << endl;
								Knight.narsosArmor = true;
								cout << endl;
								treasure = 0;
							}
						}
					}
					if (Knight.factionchoiceint == 1) {
						Knight.attackPower += ceil(Knight.getattackPower() * .01);
						Knight.defense += ceil(Knight.getdefense() * .01);
					}
					else if (Knight.factionchoiceint == 2) {
						Knight.attackPower += ceil(Knight.getattackPower() * .02);
					}
					else if (Knight.factionchoiceint == 3) {
						Knight.maxhealth += ceil(Knight.getmaxhealth() * .01);
						Knight.defense += ceil(Knight.getdefense() * .01);
					}
					else if (Knight.factionchoiceint == 4) {
						Knight.attackPower += ceil(Knight.getattackPower() * .01);
						Knight.maxhealth += ceil(Knight.getmaxhealth() * .01);
					}
					Knight.setmaxhealth();
					if (Knight.dragonmount == true) {
						Knight.incrementbaselevel(4);
					}
					else if (Knight.horsemount == true) {
						Knight.incrementbaselevel(2);
					}
					else {
						Knight.incrementbaselevel(1);
					}
					Knight.incrementkills();
					if (Knight.goldloomMagnet == true) {
						Knight.storetracker += 2.5;
						Knight.Goldloom += r() % 26 + 10;
					}
					else {
						Knight.storetracker += 1;
						Knight.Goldloom += r() % 16 + 10;
					}
					if (Knight.fasttravel == true) {
						Knight.incrementvillage(2);
					}
					else {
						Knight.incrementvillage(1);
					}
					if (Knight.isAlive() == true && Knight.getbaselevel() >= 50 && playerclasschoice == "6") {
						Knight.stopremessaging = 1;
						Knight.trickstermove = true;
						cout << "You have unlocked your Trickster skill, Confuse!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 75 && playerclasschoice == "4") {
						Knight.stopremessaging = 1;
						Knight.warforgedmove = true;
						cout << "You have unlocked your Warforged Engineer skill, Risky Detonation!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 90 && playerclasschoice == "3") {
						Knight.stopremessaging = 1;
						Knight.soulweavermove = true;
						cout << "You have unlocked your Soulweaver skill, Fortuitous Gambit!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 80 && playerclasschoice == "1") {
						Knight.stopremessaging = 1;
						Knight.knightmove = true;
						cout << "You have unlocked your special Knight skill, Titans Strike!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 75 && playerclasschoice == "5") {
						Knight.stopremessaging = 1;
						Knight.dreadnoughtmove = true;
						cout << "You have unlocked your special Dreadnought skill, Healing Remedy!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 80 && playerclasschoice == "2") {
						Knight.stopremessaging = 1;
						Knight.executionermove = true;
						cout << "You have unlocked your special Executioner skill, Soul Surge!" << endl;
					}
					if (areachoiceint == 1) {
						Slime = generateEnemy(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 2) {
						Slime = generateEnemy2(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 3) {
						Slime = generateEnemy3(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 4) {
						Slime = generateEnemy4(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 5) {
						Slime = generateEnemy5(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					cout << "You are now level " << Knight.getbaselevel() << "." << endl;
					if (Knight.getbaselevel() >= 50 && Knight.isAlive() == true && Knight.factionchoiceint == 0) {
						cout << "You can join a faction! Which faction would you like to join?" << endl;
						cout << "-Shadowborn Syndicate - A faction for those who tread a dark path..." << endl;
						cout << "-Emberfall Covenant - A faction for those who wish to wield the power of ancient flames..." << endl;
						cout << "-Celestial Vanguard - A faction for those who wish to find the light in all this darkness..." << endl;
						cout << "-Ironclad Dominion - A faction for those who believe they can become the best of the best..." << endl;
						cin >> ws;
						getline(cin, Knight.factionchoice);
						std::transform(Knight.factionchoice.begin(), Knight.factionchoice.end(), Knight.factionchoice.begin(), ::tolower);
						if (Knight.factionchoice == "shadowborn syndicate" || Knight.factionchoice == "shadowborn") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Shadowborn Syndicate. Welcome to the land of no return." << endl;
							Knight.factionchoiceint = 1;
						}
						else if (Knight.factionchoice == "emberfall covenant" || Knight.factionchoice == "emberfall") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Emberfall Covenant! Good luck on your journey to wield the ancient flames." << endl;
							Knight.factionchoiceint = 2;
						}
						else if (Knight.factionchoice == "celestial vanguard" || Knight.factionchoice == "celestial") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Celestial Vanguard! I hope you will find the light in this darkness." << endl;
							Knight.factionchoiceint = 3;
						}
						else if (Knight.factionchoice == "ironclad dominion" || Knight.factionchoice == "ironclad") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Ironclad Dominion. I wish you well, becoming the best." << endl;
							Knight.factionchoiceint = 4;
						}
					}
					if (Knight.killememiesquest == true) {
						Knight.questoneprogress += 1;
						if (Knight.questoneprogress >= 15) {
							cout << "-Your quest is ready to turn in!-" << endl;
						}
					}
					if (Knight.killabossquest == true) {
						if (Knight.bossSpawned == true) {
							Knight.questfiveprogress += 1;
							cout << "-Your quest is ready to turn in!-" << endl;
						}
					}
					Knight.DLC1tracker++;
					int enemyrandommessage;
					enemyrandommessage = r() % 5;
					if (enemyrandommessage == 0) {
						cout << "A " << Slime->getname() << " has appeared, stab it!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 1) {
						cout << "A " << Slime->getname() << " is approaching you! BE wary." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 2) {
						cout << "A " << Slime->getname() << " is preparing to attack, CHARGE!!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 3) {
						cout << "Reinforcements are approaching, be careful!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 4) {
						cout << "This " << Slime->getname() << " seems mad that you killed his friend. GET HIM!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					cout << endl;
					int item = 0;
					item = r() % 105 + 1;
					if (item == 1 && Knight.Excalibur == false) {
						Knight.Excalibur = true;
						cout << "--You gained a super item! (Excalibur)--" << endl;
						cout << endl;
					}
					else if (item == 2) {
						Knight.superiorleveltonic = true;
						cout << "--You gained a super item! (SuperiorLevelTonic)--" << endl;
						cout << endl;
					}
					else if (item == 3 || item == 4 || item == 5 && Knight.Knife == false) {
						Knight.Knife = true;
						cout << "--You gained an item! (Knife)--" << endl;
						cout << endl;
					}
					else if (item == 6 || item == 7 && Knight.Sword == false) {
						Knight.Sword = true;
						cout << "--You gained an item! (Sword)--" << endl;
						cout << endl;
					}
					else if (item == 8 || item == 9 || item == 10) {
						Knight.leveltonic = true;
						cout << "--You gained an item! (LevelTonic)--" << endl;
						cout << endl;
					}
					else if (item == 11) {
						Knight.superpotion = true;
						cout << "--You gained a godly item! (Super potion)--" << endl;
						cout << endl;
					}
					else if (item >= 12 && item <= 13) {
						if (Knight.travelersbackpack == true) {
							Knight.healthtonicitem += 1;
						}
						else {
							Knight.itemusehealthtonic();
						}
						cout << "--You gained a health tonic! (Healing potion)--" << endl;
						cout << endl;
					}
					else if (item == 14 || item == 15 && Knight.accuratesword == false) {
						Knight.accuratesword = true;
						cout << "--You gained the legendary accuracy sword! (never miss again)--" << endl;
						cout << endl;
					}
					else if (item == 16 || item == 17 && Knight.shield == false) {
						Knight.shield = true;
						cout << "--You can now dual wield with a shield! (Shield)--" << endl;
						cout << endl;
					}
					else if (item == 18 && Knight.horsemount == false) {
						Knight.horsemount = true;
						cout << "--You can now progress faster! (Horse Mount)--" << endl;
						cout << endl;
					}
					else if (item == 19 && Knight.dragonmount == false) {
						Knight.dragonmount = true;
						cout << "--You can now progress the fastest! (Dragon Mount)--" << endl;
						cout << endl;
					}
					else if (item == 20 && Knight.goldloomMagnet == false) {
						Knight.goldloomMagnet = true;
						cout << "--The shop now refreshes more frequently and you get more Goldloom! (Goldloom Magnet)--" << endl;
						cout << endl;
					}
					if (Knight.bossSpawned == true) {
						Knight.bossSpawned = false;
					}
					if (Knight.getbaselevel() >= 200 && Knight.isAlive() == true) {
						break;
					}
					chest = r() % 100 + 1;
					if (chest == 1) {
						Knight.pins = 3;         // Number of pins in the lock
						Knight.minRange = 1;     // Minimum value for each pin
						Knight.maxRange = 2;     // Maximum value for each pin
						Knight.attempts = 3;     // Number of attempts
						Knight.playLockpickingMinigame(Knight.pins, Knight.minRange, Knight.maxRange, Knight.attempts);
					}
					Knight.setmaxhealth();
				}
			}
		}
		if (!Knight.isAlive() && Knight.killplayer == false) {
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			int deathmessage = 0;
			deathmessage = r() % 5 + 1;
			if (deathmessage == 1) {
				cout << "You have been slain, better luck next time soldier." << endl;
			}
			else if (deathmessage == 2) {
				cout << "The enemies were too powerful... try again." << endl;
			}
			else if (deathmessage == 3) {
				cout << "You have now become their food, try again once you get stronger." << endl;
			}
			else if (deathmessage == 4) {
				cout << "They have erased the memory of you...the end." << endl;
			}
			else {
				cout << "The attackers have now taken over the world, you failed." << endl;
			}
			cout << endl;
			cout << "--Your overall stats were--" << "-" << endl;
			cout << "-Baselevel = " << Knight.getbaselevel() << "-" << endl;
			cout << "-Level = " << Knight.getlevel() << "-" << endl;
			cout << "-Maxhealth = " << Knight.getmaxhealth() << "-" << endl;
			cout << "-Health = " << Knight.gethealth() << "-" << endl;
			cout << "-Attack = " << Knight.getattackPower() << "-" << endl;
			cout << "-defense = " << Knight.getdefense() << "-" << endl;
			cout << "-Kills = " << Knight.getkills() << "-" << endl;
			cout << "-Lives = " << Knight.getlives() << "-" << endl;
			if (Knight.getclass() == 1) {
				cout << "-Class = Knight-" << endl;
			}
			else if (Knight.getclass() == 2) {
				cout << "-Class = Executioner-" << endl;
			}
			else if (Knight.getclass() == 3) {
				cout << "-Class = Soulweaver-" << endl;
			}
			else if (Knight.getclass() == 4) {
				cout << "-Class = Warforged Engineer-" << endl;
			}
			else if (Knight.getclass() == 5) {
				cout << "-Class = Dreadnought-" << endl;
			}
			else if (Knight.getclass() == 6) {
				cout << "-Class = Trickster-" << endl;
			}
			cout << "Would you like to try Again? (Y/N)" << endl;
			Knight.delay(3);
			string retry = "";
			cin >> retry;
			if (retry == "N" || retry == "n") {
				SteamAPI_Shutdown();
				break;
			}
			else if (retry == "Y" || retry == "y") {
				cout << endl << endl;
				Knight.resetKnight();
			}
			else {
				cout << "Not a valid answer, I'm kicking you out." << endl;
				break;
			}
		}
		else if (Knight.killplayer == true) {
			cout << Knight.getname() << " you should try to be less indecisive." << endl;
			cout << "Game Over." << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			break;
		}
		else {
			cout << Slime->getlives();
			cout << "You have saved the universe from the Creator and became a hero!" << endl;
			cout << "--Your overall stats were--" << "-" << endl;
			cout << "-Baselevel = " << Knight.getbaselevel() << "-" << endl;
			cout << "-Level = " << Knight.getlevel() << "-" << endl;
			cout << "-Maxhealth = " << Knight.getmaxhealth() << "-" << endl;
			cout << "-Health = " << Knight.gethealth() << "-" << endl;
			cout << "-Attack = " << Knight.getattackPower() << "-" << endl;
			cout << "-defense = " << Knight.getdefense() << "-" << endl;
			cout << "-Kills = " << Knight.getkills() << "-" << endl;
			cout << "-Lives = " << Knight.getlives() << "-" << endl;
			cout << "-Store Currency = " << Knight.Goldloom << "-" << endl;
			if (Knight.getclass() == 1) {
				cout << "-Class = Knight" << "-" << endl;
			}
			else if (Knight.getclass() == 2) {
				cout << "-Class = Executioner" << "-" << endl;
			}
			else if (Knight.getclass() == 3) {
				cout << "-Class = Soulweaver" << "-" << endl;
			}
			else if (Knight.getclass() == 4) {
				cout << "-Class = Warforged Engineer" << "-" << endl;
			}
			else if (Knight.getclass() == 5) {
				cout << "-Class = Dreadnought" << "-" << endl;
			}
			else if (Knight.getclass() == 6) {
				cout << "-Class = Trickster" << "-" << endl;
			}
			cout << "The world thanks you for your service, " << Knight.getname() << "." << endl;
			cout << "Play Again? (Y/N)" << endl;
			Knight.delay(3);
			string playagain = "";
			cin >> playagain;
			if (playagain == "N" || playagain == "n") {
				cout << "Hope to see you again soon!";
				SteamAPI_Shutdown();
				break;
			}
			else if (playagain == "Y" || playagain == "y") {
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				Knight.resetKnight();
			}
			else {
				cout << "Not a valid answer, goodbye." << endl;
				SteamAPI_Shutdown();
				break;
			}
		}
		SteamAPI_Shutdown();
	}
	//start of endless mode
	while (Knight.endlessmode == true) {
		cout << "Welcome to Evil Conquest...Endless mode!" << endl;
		cout << "Your goal is to progress as far as you can and gain the best stats possible." << endl;
		cout << "You start at level one, for every kill you go up a level and gain more damage (Base attack damage + level)" << endl;
		cout << "--Level can only add up to 30 damage and/or healing--(Level gained from items does affect this)" << endl;
		cout << "At levels 15, 25, 50 and 100, you gain new abilities. Every 100 levels a boss spawns and every 50 levels a mini boss spawns." << endl;
		cout << "I wish you well on your conquest." << endl;
		cout << endl;
		cout << "Would you like to be a 1- Knight, 2- Executioner, 3- Soulweaver, 4- Warforged Engineer, 5- Dreadnought, 6- Trickster or 7- Random?" << endl;
		cout << "-Knight has average health and damage-" << endl << "-Executioner has a lot less health and a lot more damage-" << endl << "-Soulweaver starts with 1 extra life for less attack/health and a special move-" << endl << "-Warforged Engineer has slightly higher health for slightly lower damage and a special move-" << endl << "-Dreadnought has a lot more health / maxhealth and a lot less damage-" << endl << "-Trickster has a little less health for barely more attack, and a special move.-" << endl;
		int cinFailchoice = 0, classcurrency = 0, playerclasschoiceint = 0;
		string playerclasschoice = "";
		cin >> ws;
		getline(cin, playerclasschoice);
		if (playerclasschoice == "1") {
			cout << "You chose Knight!" << endl;
		}
		else if (playerclasschoice == "2") {
			Knight.playerclassexecutioner();
			cout << "You chose Executioner!" << endl;
		}
		else if (playerclasschoice == "3") {
			Knight.playerclasssoulweaver();
			cout << "You chose Soulweaver!" << endl;
		}
		else if (playerclasschoice == "4") {
			Knight.playerclasswarforged();
			cout << "You chose Warforged Engineer!" << endl;
		}
		else if (playerclasschoice == "5") {
			Knight.playerclassdreadnought();
			cout << "You chose Dreadnought!" << endl;
		}
		else if (playerclasschoice == "6") {
			Knight.playerclasstrickster();
			cout << "You chose Trickster!" << endl;
		}
		else if (playerclasschoice == "7") {
			playerclasschoiceint = r() % 6 + 1;
			if (playerclasschoiceint == 1) {
				cout << "You were given Knight." << endl;
			}
			else if (playerclasschoiceint == 2) {
				Knight.playerclassexecutioner();
				cout << "You were given Executioner." << endl;
			}
			else if (playerclasschoiceint == 3) {
				Knight.playerclasssoulweaver();
				cout << "You were given Soulweaver." << endl;
			}
			else if (playerclasschoiceint == 4) {
				Knight.playerclasswarforged();
				cout << "You were given Warforged Engineer." << endl;
			}
			else if (playerclasschoiceint == 5) {
				Knight.playerclassdreadnought();
				cout << "You were given Dreadnought." << endl;
			}
			else if (playerclasschoiceint == 6) {
				Knight.playerclasstrickster();
				cout << "You were given Trickster." << endl;
			}
		}
		else {
			cout << "You chose nothing so I will choose for you." << endl;
			playerclasschoiceint = r() % 6 + 1;
			if (playerclasschoiceint == 1) {
				cout << "You were given Knight." << endl;
			}
			else if (playerclasschoiceint == 2) {
				Knight.playerclassexecutioner();
				cout << "You were given Executioner." << endl;
			}
			else if (playerclasschoiceint == 3) {
				Knight.playerclasssoulweaver();
				cout << "You were given Soulweaver." << endl;
			}
			else if (playerclasschoiceint == 4) {
				Knight.playerclasswarforged();
				cout << "You were given Warforged Engineer." << endl;
			}
			else if (playerclasschoiceint == 5) {
				Knight.playerclassdreadnought();
				cout << "You were given Dreadnought." << endl;
			}
			else if (playerclasschoiceint == 6) {
				Knight.playerclasstrickster();
				cout << "You were given Trickster." << endl;
			}
		}
		cout << "What would you like me to call you?" << endl;
		cin >> ws;
		getline(cin, Knight.name);
		cout << "Your name is " << Knight.getname() << "?" << endl << "Y/N" << endl;
		string acceptname = "";
		cin >> acceptname;
		if (acceptname == "Y" || acceptname == "y") {
			cout << "Welcome " << Knight.getname() << "!" << " I hope you are prepared for this treacherous journey..." << endl;
		}
		else if (acceptname == "N" || acceptname == "n") {
			cout << "Well come on then, make up your mind dude. I don't have all day " << "Lets try this again, but this is your last chance." << endl;
			cout << endl;
			cout << "What would you like me to call you?" << endl;
			cin >> Knight.name;
			cout << "Welcome " << Knight.getname() << "!" << " I hope you are prepared for this treacherous journey. Based on how long it took you to pick a name, for your sake, I would recommend turning around." << endl;
			cout << "Turn around? Y/N" << endl;
			string turnaround = "";
			cin >> turnaround;
			if (turnaround == "Y" || turnaround == "y") {
				Knight.setkillplayer();
				Knight.isAlive();
			}
			else if (turnaround == "N" || turnaround == "n") {
				cout << "Good luck kid, you need it" << endl;
			}
			else {
				cout << "Nice typo, I'm not even going to give you another chance" << endl;
				Knight.setkillplayer();
				Knight.isAlive();
			}
		}
		else {
			cout << "That wasn't a yes or a no, did you pass kindergarten?" << endl;
			string doesnothing = "";
			cin >> doesnothing;
			cout << "I dont even care, whatever you just entered did absolutely nothing. You're stuck with the name you gave me before now." << endl;
		}
		cout << "Where would you like to journey " << Knight.getname() << " ?" << endl;
		cout << "-1-Mushroom Kingdom-" << endl;
		cout << "-2-Gooey Glade-" << endl;
		cout << "-3-Croc Isle-" << endl;
		cout << "-4-Hopscotch Highlands-" << endl;
		cout << "-5-Skeletal Sanctum-" << endl;
		string areachoice = "";
		int areachoiceint = 0;
		cin >> ws;
		getline(cin, areachoice);
		std::transform(areachoice.begin(), areachoice.end(), areachoice.begin(), ::tolower);
		if (areachoice == "mushroom kingdom" || areachoice == "1") {
			cout << endl;
			cout << "-Welcome to the happy Kingdom of the Mushrooms! Normally you would be welcomed by, well a mushroom, but right now they are being invaded. Go get the invaders!-" << endl << endl;
			areachoiceint = 1;
		}
		else if (areachoice == "gooey glade" || areachoice == "2") {
			cout << endl;
			cout << "-Welcome to the uneasy feeling area of the slimes. Good Luck Surviving!-" << endl << endl;
			areachoiceint = 2;
		}
		else if (areachoice == "croc isle" || areachoice == "3") {
			cout << endl;
			cout << "-Welcome to the land of the crocs. Go find that croc king!-" << endl << endl;
			areachoiceint = 3;
		}
		else if (areachoice == "hopscotch highlands" || areachoice == "4") {
			cout << endl;
			cout << "-Welcome to the land of the kangaroos, attack that zoo owner!-" << endl << endl;
			areachoiceint = 4;
		}
		else if (areachoice == "skeletal sanctum" || areachoice == "5") {
			cout << endl;
			cout << "-Welcome to the graveyeard of your dead family...just kidding. Look out there's a skeleton!-" << endl << endl;
			areachoiceint = 5;
		}
		else {
			cout << "That area doesn't exist so I guess I'll choose for you" << endl;
			int x = 0;
			x = r() % 5 + 1;
			switch (x) {
			case 0:
				if (cin.fail()) {
					cout << endl;
					cout << "----------------------" << endl;
					cout << "I chose an area for you." << endl;
					cout << "----------------------" << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					areachoiceint = r() % 5 + 1;
					break;
				}
			case 1:
				areachoice = "Mushroom Kingdom";
				cout << endl;
				cout << "-Welcome to the happy Kingdom of the Mushrooms! Normally you would be welcomed by, well a mushroom, but right now they are being invaded. Go get them!-" << endl << endl;
				areachoiceint = 1;
				break;
			case 2:
				areachoice = "Gooey Glade";
				cout << endl;
				cout << "-Welcome to the uneasy feeling area of the slimes. Good Luck Surviving!-" << endl << endl;
				areachoiceint = 2;
				break;
			case 3:
				areachoice = "Croc Isle";
				cout << endl;
				cout << "-Welcome to the land of the crocs. Go find that croc king!-" << endl << endl;
				areachoiceint = 3;
				break;
			case 4:
				areachoice = "Hopscotch Highlands";
				cout << endl;
				cout << "-Welcome to the land of the kangaroos, attack that zoo owner!-" << endl << endl;
				areachoiceint = 4;
				break;
			case 5:
				areachoice = "Skeletal Sanctum";
				cout << endl;
				cout << "-Welcome to the graveyeard of your dead family...just kidding. Look out there's a skeleton!-" << endl << endl;
				areachoiceint = 5;
				break;
			default:
				if (cin.fail()) {
					cout << endl;
					cout << "----------------------" << endl;
					cout << "I chose an area for you." << endl;
					cout << "----------------------" << endl << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					areachoiceint = r() % 5 + 1;
					break;
				}
			}
		}
		Enemy* Slime = nullptr;
		if (areachoiceint == 1) {
			Slime = generateEnemy(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 2) {
			Slime = generateEnemy2(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 3) {
			Slime = generateEnemy3(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 4) {
			Slime = generateEnemy4(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}
		else if (areachoiceint == 5) {
			Slime = generateEnemy5(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
		}

		while (Knight.isAlive() && Slime->isAlive()) {
			Knight.checkitems();
			Knight.attack(Slime);
			if (Slime->gethealth() <= 0 && Knight.usinginvispotion == false) {
				cout << Slime->getname() << " has 0 health remaining." << endl;
			}
			else if (Slime->gethealth() > 0 && Knight.usinginvispotion == false && Knight.trickstermovebool == false && Knight.warforgedmovebool == false) {
				cout << Slime->getname() << " has " << Slime->gethealth() << " health remaining." << endl;
			}
			cout << "-----------------------------------------------" << endl;
			Slime->attack(&Knight);
			if (Knight.gethealth() <= 0) {
				cout << Knight.getname() << ", you have 0 health remaining." << endl;
			}
			else if (Knight.gethealth() > 0 && Knight.usinginvispotion == false) {
				cout << Knight.getname() << ", you have " << Knight.gethealth() << " health remaining." << endl;
			}
			cout << "-----------------------------------------------" << endl;
			if (!Slime->isAlive()) {
				disableGeneration = false;
				if (Knight.usinginvispotion == true) {
					delete Slime;
					cout << "You have escaped from this enemy using your invisibility." << endl;
					if (areachoiceint == 1) {
						Slime = generateEnemy(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 2) {
						Slime = generateEnemy2(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 3) {
						Slime = generateEnemy3(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 4) {
						Slime = generateEnemy4(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 5) {
						Slime = generateEnemy5(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					int enemyrandommessage = 0;
					enemyrandommessage = r() % 5;
					if (enemyrandommessage == 0) {
						cout << "A new " << Slime->getname() << " has appeared, stab it!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 1) {
						cout << "A " << Slime->getname() << " is approaching you! BE wary." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 2) {
						cout << "A " << Slime->getname() << " is preparing to attack, CHARGE!!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 3) {
						cout << "Reinfocements are approaching, be careful!" << endl;
						cout << "A " << Slime->getname() << " has appeared." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 4) {
						cout << "This " << Slime->getname() << " seems mad that you killed his friend." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					Knight.usinginvispotion = false;
				}
				else if (Knight.usinginvispotion == false) {
					delete Slime;
					classcurrency += 1;
					if (classcurrency == 50 || classcurrency == 100 || classcurrency == 150) {
						cout << "Which stat would you like to upgrade? (1=hp, 2=atk, 3=def, 4=lvl, 5=extra life) *Note* Only hp can be upgraded more than once." << endl;
						int stat = 0;
						cin >> stat;
						switch (stat) {
						case 1:
							Knight.maxhealthupgrade = true;
							cout << "You now have " << Knight.gethealth() << " health." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 2:
							Knight.attackupgrade = true;
							cout << "You now have " << Knight.getattackPower() << " attack." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 3:
							Knight.defenseupgrade = true;
							cout << "You now have " << Knight.getdefense() << " defense." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 4:
							Knight.levelupgrade = true;
							cout << "You are now level " << Knight.getlevel() << "." << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						case 5:
							Knight.addlives(1);
							cout << "You now have " << Knight.getlives() << " lives" << endl;
							cout << "-----------------------------------------------" << endl;
							break;
						default:
							cout << "That choice doesn't exist, I'll choose for you." << endl;
							int x = 0;
							x = r() % 5 + 1;
							if (x == 1) {
								Knight.maxhealthupgrade = true;
							}
							else if (x == 2) {
								Knight.attackupgrade = true;
							}
							else if (x == 3) {
								Knight.defenseupgrade = true;
							}
							else if (x == 4) {
								Knight.levelupgrade = true;
							}
							else {
								Knight.addlives(1);
							}
							break;
						}
					}
					else if (classcurrency == 20 || classcurrency == 40 || classcurrency == 60 || classcurrency == 80 || classcurrency == 100 || classcurrency == 120 || classcurrency == 140 || classcurrency == 160 || classcurrency == 180 && Knight.playercompanion == true) {
						cout << "You have found a rare treasure!" << endl;
						int treasure;
						treasure = r() % 99 + 1;
						if (treasure <= 30) {
							Knight.helmet = true;
							cout << "You got a fancy hat.";
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 30 && treasure <= 60) {
							Knight.chestplate = true;
							cout << "You have acquired a weird robe.";
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 61 && treasure <= 90) {
							Knight.boots = true;
							cout << "You put on some cool shoes.";
							cout << endl;
							treasure = 0;
						}
						else {
							int legend;
							legend = r() % 3;
							if (legend == 0 && Knight.vladimirsArmor == false) {
								cout << "You acquired the armor of the legend...Vladimir!" << endl;
								Knight.vladimirsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 1 && Knight.lockhartsArmor == false) {
								cout << "You acquired the armor of the legend...Lockhart!" << endl;
								Knight.lockhartsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 2 && Knight.narsosArmor == false) {
								cout << "You acquired the armor of the legend...Narso!" << endl;
								Knight.narsosArmor = true;
								cout << endl;
								treasure = 0;
							}
						}
					}
					else if (classcurrency == 20 || classcurrency == 40 || classcurrency == 60 || classcurrency == 80 || classcurrency == 100 || classcurrency == 120 || classcurrency == 140 || classcurrency == 160 || classcurrency == 180) {
						cout << "You have found a rare treasure!" << endl;
						int treasure;
						treasure = r() % 99 + 1;
						if (treasure <= 33) {
							Knight.helmet = true;
							cout << "You got a fancy hat." << endl;
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 33 && treasure <= 66) {
							Knight.chestplate = true;
							cout << "You have acquired a weird robe." << endl;
							cout << endl;
							treasure = 0;
						}
						else if (treasure > 66 && treasure <= 99) {
							Knight.boots = true;
							cout << "You put on some cool shoes." << endl;
							cout << endl;
							treasure = 0;
						}
						else {
							int legend;
							legend = r() % 3;
							if (legend == 0) {
								cout << "You acquired the armor of the legend...Vladimir!" << endl;
								Knight.vladimirsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else if (legend == 1) {
								cout << "You acquired the armor of the legend...Lockhart!" << endl;
								Knight.lockhartsArmor = true;
								cout << endl;
								treasure = 0;
							}
							else {
								cout << "You acquired the armor of the legend...Narso!" << endl;
								Knight.narsosArmor = true;
								cout << endl;
								treasure = 0;
							}
						}
					}
					if (Knight.factionchoiceint == 1) {
						Knight.attackPower += ceil(Knight.getattackPower() * .005);
						Knight.defense += ceil(Knight.getdefense() * .005);
					}
					else if (Knight.factionchoiceint == 2) {
						Knight.attackPower += ceil(Knight.getattackPower() * .01);
					}
					else if (Knight.factionchoiceint == 3) {
						Knight.maxhealth += ceil(Knight.getmaxhealth() * .005);
						Knight.defense += ceil(Knight.getdefense() * .005);
					}
					else if (Knight.factionchoiceint == 4) {
						Knight.attackPower += ceil(Knight.getattackPower() * .005);
						Knight.maxhealth += ceil(Knight.getmaxhealth() * .005);
					}
					if (Knight.dragonmount == true) {
						Knight.incrementbaselevel(4);
					}
					else if (Knight.horsemount == true) {
						Knight.incrementbaselevel(2);
					}
					else {
						Knight.incrementbaselevel(1);
					}
					if (Knight.getbaselevel() > 200) {
						Knight.villagetracker += 1;
					}
					Knight.incrementkills();
					if (Knight.goldloomMagnet == true) {
						Knight.storetracker += 2.5;
						Knight.Goldloom += r() % 26 + 10;
					}
					else {
						Knight.storetracker += 1;
						Knight.Goldloom += r() % 16 + 10;
					}
					Knight.DLC1tracker++;
					if (Knight.isAlive() == true && Knight.getbaselevel() >= 50 && playerclasschoice == "6") {
						Knight.stopremessaging = 1;
						Knight.trickstermove = true;
						cout << "You have unlocked your Trickster skill, Confuse!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 75 && playerclasschoice == "4") {
						Knight.stopremessaging = 1;
						Knight.warforgedmove = true;
						cout << "You have unlocked your Warforged Engineer skill, Risky Detonation!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 90 && playerclasschoice == "3") {
						Knight.stopremessaging = 1;
						Knight.soulweavermove = true;
						cout << "You have unlocked your Soulweaver skill, Fortuitous Gambit!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 80 && playerclasschoice == "1") {
						Knight.stopremessaging = 1;
						Knight.knightmove = true;
						cout << "You have unlocked your special Knight skill, Titans Strike!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 75 && playerclasschoice == "5") {
						Knight.stopremessaging = 1;
						Knight.dreadnoughtmove = true;
						cout << "You have unlocked your special Dreadnought skill, Healing Remedy!" << endl;
					}
					else if (Knight.isAlive() == true && Knight.getbaselevel() >= 80 && playerclasschoice == "2") {
						Knight.stopremessaging = 1;
						Knight.executionermove = true;
						cout << "You have unlocked your special Executioner skill, Soul Surge!" << endl;
					}
					if (areachoiceint == 1) {
						Slime = generateEnemy(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 2) {
						Slime = generateEnemy2(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 3) {
						Slime = generateEnemy3(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 4) {
						Slime = generateEnemy4(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					else if (areachoiceint == 5) {
						Slime = generateEnemy5(Knight.getbaselevel(), Knight.getmaxhealth(), Knight.getattackPower(), Knight.getdefense(), Knight.getlevel(), Knight.getlives(), Knight.getclass());
					}
					cout << "You are now level " << Knight.getbaselevel() << "." << endl;
					if (Knight.getbaselevel() >= 50 && Knight.isAlive() == true && Knight.factionchoiceint == 0) {
						cout << "You can now join a faction! Which faction would you like to join?" << endl;
						cout << "-Shadowborn Syndicate - A faction for those who tread a dark path..." << endl;
						cout << "-Emberfall Covenant - A faction for those who wish to wield the power of ancient flames..." << endl;
						cout << "-Celestial Vanguard - A faction for those who wish to find the light in all this darkness..." << endl;
						cout << "-Ironclad Dominion - A faction for those who believe they can become the best of the best..." << endl;
						cin >> ws;
						getline(cin, Knight.factionchoice);
						std::transform(Knight.factionchoice.begin(), Knight.factionchoice.end(), Knight.factionchoice.begin(), ::tolower);
						if (Knight.factionchoice == "shadowborn syndicate" || Knight.factionchoice == "shadowborn") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Shadowborn Syndicate. Welcome to the land of no return." << endl;
							Knight.factionchoiceint = 1;
						}
						else if (Knight.factionchoice == "emberfall covenant" || Knight.factionchoice == "emberfall") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Emberfall Covenant! Good luck on your journey to wield the ancient flames." << endl;
							Knight.factionchoiceint = 2;
						}
						else if (Knight.factionchoice == "celestial vanguard" || Knight.factionchoice == "celestial") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Celestial Vanguard! I hope you will find the light in this darkness." << endl;
							Knight.factionchoiceint = 3;
						}
						else if (Knight.factionchoice == "ironclad dominion" || Knight.factionchoice == "ironclad") {
							cout << "-----------------------------------------------" << endl;
							cout << "You chose the Ironclad Dominion. I wish you well, becoming the best." << endl;
							Knight.factionchoiceint = 4;
						}
					}
					if (Knight.killememiesquest == true) {
						Knight.questoneprogress += 1;
						if (Knight.questoneprogress >= 15) {
							cout << "-Your quest is ready to turn in!-" << endl;
						}
					}
					if (Knight.killabossquest == true) {
						if (Knight.bossSpawned == true) {
							Knight.questfiveprogress += 1;
							cout << "-Your quest is ready to turn in!-" << endl;
						}
					}
					int enemyrandommessage;
					enemyrandommessage = r() % 5;
					if (enemyrandommessage == 0) {
						cout << "A " << Slime->getname() << " has appeared, stab it!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 1) {
						cout << "A " << Slime->getname() << " is approaching you! BE wary." << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 2) {
						cout << "A " << Slime->getname() << " is preparing to attack, CHARGE!!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 3) {
						cout << "Reinforcements are approaching, be careful!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					else if (enemyrandommessage == 4) {
						cout << "This " << Slime->getname() << " seems mad that you killed his friend. GET HIM!!" << endl;
						cout << "-----------------------------------------------" << endl;
					}
					cout << endl;
					int item = 0;
					item = r() % 105 + 1;
					if (item == 1 && Knight.Excalibur == false) {
						Knight.Excalibur = true;
						cout << "--You gained a super item! (Excalibur)--" << endl;
						cout << endl;
					}
					else if (item == 2) {
						Knight.superiorleveltonic = true;
						cout << "--You gained a super item! (SuperiorLevelTonic)--" << endl;
						cout << endl;
					}
					else if (item == 3 || item == 4 || item == 5 && Knight.Knife == false) {
						Knight.Knife = true;
						cout << "--You gained an item! (Knife)--" << endl;
						cout << endl;
					}
					else if (item == 6 || item == 7 && Knight.Sword == false) {
						Knight.Sword = true;
						cout << "--You gained an item! (Sword)--" << endl;
						cout << endl;
					}
					else if (item == 8 || item == 9 || item == 10) {
						Knight.leveltonic = true;
						cout << "--You gained an item! (LevelTonic)--" << endl;
						cout << endl;
					}
					else if (item == 11) {
						Knight.superpotion = true;
						cout << "--You gained a godly item! (Super potion)--" << endl;
						cout << endl;
					}
					else if (item >= 12 && item <= 13) {
						if (Knight.travelersbackpack == true) {
							Knight.healthtonicitem += 1;
						}
						else {
							Knight.itemusehealthtonic();
						}
						cout << "--You gained a health tonic! (Healing potion)--" << endl;
						cout << endl;
					}
					else if (item == 14 || item == 15 || item == 16 && Knight.accuratesword == false) {
						Knight.accuratesword = true;
						cout << "--You gained the legendary accuracy sword! (never miss again)--" << endl;
						cout << endl;
					}
					else if (item == 17 || item == 18 && Knight.shield == false) {
						Knight.shield = true;
						cout << "--You can now dual wield with a shield! (Shield)--" << endl;
						cout << endl;
					}
					else if (item == 19 && Knight.horsemount == false) {
						Knight.horsemount = true;
						cout << "--You can now progress faster! (Horse Mount)--" << endl;
						cout << endl;
					}
					else if (item == 20 && Knight.dragonmount == false) {
						Knight.dragonmount = true;
						cout << "--You can now progress the fastest! (Dragon Mount)--" << endl;
						cout << endl;
					}
					else if (item == 21 || item == 22) {
						Knight.cipherblueprint += 1;
						cout << "--You got a cipher blueprint! Use the key to read it...--" << endl;
						cout << endl;
					}
					else if (item == 23 || item == 24 && Knight.cipherkey == false) {
						Knight.cipherkey == true;
						cout << "--You got a cipher key! Use it on blueprints to unlock new information...--" << endl;
						cout << endl;
					}
					else if ((item == 25 || item == 26) && Knight.ciphertracker == 3) {
						Knight.riddle == true;
						cout << "--You acquired a special riddle! Use it from your backpack...--" << endl;
						cout << endl;
					}
					else if ((item == 27 || item == 28) && Knight.ciphertracker == 4) {
						Knight.soulstone += 1;
						cout << "--You found a rate Soulstone!--" << endl;
						cout << endl;
					}
					else if ((item == 29 || item == 30 || item == 31) && Knight.endlessmode == true && Knight.ciphertracker == 4) {
						Knight.radiantgem += 1;
						cout << "--You stumbled upon a Radiant Gem!--" << endl;
						cout << endl;
					}
					else if (item == 32 || item == 33 || item == 34 || item == 35 || item == 36 && Knight.bossSpawned == true) {
						Knight.lostartifact = +1;
						cout << "--You found a Lost Artifact!.--" << endl;
						cout << endl;
					}
					else if (item == 37 && Knight.goldloomMagnet == false) {
						Knight.goldloomMagnet = true;
						cout << "--Your shop now appears more frequently and you get more money! (Goldloom Magnet)--" << endl;
						cout << endl;
					}
					else if (item == 38 && Knight.fasttravel == false) {
						Knight.fasttravel = true;
						cout << "--You have unlocked fast travel! You can now visit the village 2x faster." << endl;
						cout << endl;
					}
					if (Knight.killememiesquest == true) {
						Knight.questoneprogress += 1;
						if (Knight.questoneprogress >= 15) {
							cout << "Your quest is ready to be turned in." << endl;
						}
					}
					if (Knight.bossSpawned == true && Knight.mysteriousstrangerquest == true) {
						Knight.mysteriousstrangerquesttracker += 1;
						if (Knight.mysteriousstrangerquesttracker == 3) {
							Knight.mysteriousquest();
						}
					}
					if (Knight.bossSpawned == true) {
						Knight.bossSpawned = false;
					}
					randomevent = r() % 100 + 1;
					if (randomevent == 1 || randomevent == 2 && Knight.mysteriousstrangerquestactive == false) {
						string yesno = "";
						cout << "A mysterious stranger is approaching..." << endl << "Would you like a quest?" << endl;
						cin >> ws;
						getline(cin, yesno);
						std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
						randomevent = r() % 5 + 1;
						if (yesno == "yes" || yesno == "y") {
							if (randomevent == 1) {
								cout << "--You must kill 3 bosses--" << endl;
								Knight.mysteriousstrangerquest = true;
								Knight.mysteriousstrangerquestactive = true;
							}
							else if (randomevent == 2) {
								cout << "--You must craft a cursed artifact--" << endl;
								Knight.mysteriousstrangerquest2 = true;
								Knight.mysteriousstrangerquestactive = true;
							}
							if (randomevent == 3) {
								cout << "--You must use 5 items--" << endl;
								Knight.mysteriousstrangerquest3 = true;
								Knight.mysteriousstrangerquestactive = true;
							}
							else if (randomevent == 4) {
								cout << "--You must forge 3 pieces of armor--" << endl;
								Knight.mysteriousstrangerquest4 = true;
								Knight.mysteriousstrangerquestactive = true;
							}
							else if (randomevent == 5) {
								cout << "--You must forge 2 weapons--" << endl;
								Knight.mysteriousstrangerquest5 = true;
								Knight.mysteriousstrangerquestactive = true;
							}
						}
						else if (yesno == "no" || yesno == "n") {
							cout << "You missed out on a great opportunity." << endl;
							cout << "-The mysterious stranger has left-" << endl;
						}
						else {
							cout << "Since you can't type, the mysterious stranger impatiently left you." << endl;
						}
						chest = r() % 100 + 1;
						if (chest == 1) {
							Knight.pins = 3;         // Number of pins in the lock
							Knight.minRange = 1;     // Minimum value for each pin
							Knight.maxRange = 2;     // Maximum value for each pin
							Knight.attempts = 3;     // Number of attempts
							Knight.playLockpickingMinigame(Knight.pins, Knight.minRange, Knight.maxRange, Knight.attempts);
						}
						Knight.setmaxhealth();
					}
				}
			}
		}
		if (!Knight.isAlive() && Knight.killplayer == false) {
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			int deathmessage = 0;
			deathmessage = r() % 5 + 1;
			if (deathmessage == 1) {
				cout << "You have been slain, better luck next time soldier." << endl;
			}
			else if (deathmessage == 2) {
				cout << "The enemies were too powerful... try again." << endl;
			}
			else if (deathmessage == 3) {
				cout << "You have now become their food, try again once you get stronger." << endl;
			}
			else if (deathmessage == 4) {
				cout << "They have erased the memory of you...the end." << endl;
			}
			else {
				cout << "The attackers have now taken over the world, you failed." << endl;
			}
			cout << endl;
			cout << "--Your overall stats were--" << "-" << endl;
			cout << "-Baselevel = " << Knight.getbaselevel() << "-" << endl;
			cout << "-Level = " << Knight.getlevel() << "-" << endl;
			cout << "-Maxhealth = " << Knight.getmaxhealth() << "-" << endl;
			cout << "-Health = " << Knight.gethealth() << "-" << endl;
			cout << "-Attack = " << Knight.getattackPower() << "-" << endl;
			cout << "-defense = " << Knight.getdefense() << "-" << endl;
			cout << "-Kills = " << Knight.getkills() << "-" << endl;
			cout << "-Lives = " << Knight.getlives() << "-" << endl;
			if (Knight.getclass() == 1) {
				cout << "-Class = Knight-" << endl;
			}
			else if (Knight.getclass() == 2) {
				cout << "-Class = Executioner-" << endl;
			}
			else if (Knight.getclass() == 3) {
				cout << "-Class = Soulweaver-" << endl;
			}
			else if (Knight.getclass() == 4) {
				cout << "-Class = Warforged Engineer-" << endl;
			}
			else if (Knight.getclass() == 5) {
				cout << "-Class = Dreadnought-" << endl;
			}
			else if (Knight.getclass() == 6) {
				cout << "-Class = Trickster-" << endl;
			}
			cout << "Would you like to try Again? (Y/N)" << endl;
			Knight.delay(3);
			string retry = "";
			cin >> retry;
			if (retry == "N" || retry == "n") {
				SteamAPI_Shutdown();
				break;
			}
			else if (retry == "Y" || retry == "y") {
				cout << endl << endl;
				Knight.resetKnight();
			}
			else {
				cout << "Not a valid answer, I'm kicking you out." << endl;
				SteamAPI_Shutdown();
				break;
			}
		}
		else if (Knight.killplayer == true) {
			cout << Knight.getname() << " you should try to be less indecisive." << endl;
			cout << "Game Over." << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			SteamAPI_Shutdown();
			break;
		}
	}
	SteamAPI_Shutdown();
}
int main() {
	SteamAPI_Init();
	if (SteamAPI_Init() == true) {
		gameplay();
	}
	else {
		cout << "Steam initialization failed. You can still play if you don't mind." << endl;
		cout << "Would you still like to play?" << endl;
		while (true) {
			string yesorno;
			cin >> yesorno;
			std::transform(yesorno.begin(), yesorno.end(), yesorno.begin(), ::tolower);
			if (yesorno == "y" || yesorno == "yes") {
				gameplay();
				break;
			}
			else if (yesorno == "n" || yesorno == "no") {
				cout << "Came back soon!" << endl;
				break;
			}
			else {
				cout << "Not a valid answer, try again." << endl;
			}
		}
	}
	return 0;
}
