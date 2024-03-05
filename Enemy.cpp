#include "Enemy.h"

Enemy::Enemy(string n2, int hp2, int atk2, int def2, int live2, int lvl2, int maxh2) {
    name = n2;
    health = hp2;
    attackPower = atk2;
    lives = live2;
    level = lvl2;
    maxhealth = maxh2;
    defense = def2;
}
int critchance, d, accuracy, attackself;
void Enemy::attack(Character* Target) {
    if (Target->trickstermovebool == true && health > 0 && Target->getlevel() >= 100) {
        critchance = r() % 100 + 1;
        attackself = r() % 100 + 1;
        if (attackself > 60 && critchance > 70) {
            d = r() % 10 + ceil(attackPower * 1.5);
            health -= d;
            cout << "The enemy got confused and attacked itself for " << d << " damage!" << endl;
            cout << "The " << name << " has " << health << " remaining." << endl;
            Target->trickstermovebool = false;
        }
        else if (attackself > 60) {
            d = r() % 10 + attackPower;
            health -= d;
            cout << "The enemy got confused and attacked itself for " << d << " damage!" << endl;
            cout << "The " << name << " has " << health << " remaining." << endl;
            Target->trickstermovebool = false;
        }
        else if (attackself <= 60 && critchance > 70) {
            cout << "The enemy resisted your willpower and did not get confused." << endl;
            d = r() % 10 + ceil(attackPower * 1.5);
            cout << name << " has crit and dealt " << d << " damage." << endl;
            Target->takeDmg(d);
            Target->trickstermovebool = false;
        }
        else {
            cout << "The enemy resisted your willpower and did not get confused." << endl;
            d = r() % 10 + attackPower;
            cout << name << " dealt " << d << " damage." << endl;
            Target->takeDmg(d);
            Target->trickstermovebool = false;
        }
    }
    else if (Target->trickstermovebool == true && health > 0) {
        critchance = r() % 100 + 1;
        attackself = r() % 100 + 1;
        if (attackself > 60 && critchance > 70) {
            d = r() % 7 + ceil(attackPower * 1.5);
            health -= d;
            cout << "The enemy got confused and attacked itself for " << d << " damage!" << endl;
            cout << "The " << name << " has " << health << " remaining." << endl;
            Target->trickstermovebool = false;
        }
        else if (attackself > 60) {
            d = r() % 7 + attackPower;
            health -= d;
            cout << "The enemy got confused and attacked itself for " << d << " damage!" << endl;
            cout << "The " << name << " has " << health << " remaining." << endl;
            Target->trickstermovebool = false;
        }
        else if (attackself <= 60 && critchance > 70) {
            cout << "The enemy resisted your willpower and did not get confused." << endl;
            d = r() % 7 + ceil(attackPower * 1.5);
            cout << name << " has crit and dealt " << d << " damage." << endl;
            Target->takeDmg(d);
            Target->trickstermovebool = false;
        }
        else {
            cout << "The enemy resisted your willpower and did not get confused." << endl;
            d = r() % 7 + attackPower;
            cout << name << " dealt " << d << " damage." << endl;
            Target->takeDmg(d);
            Target->trickstermovebool = false;
        }
    }
    else if (health > 0 && getlevel() >= 100) {
        accuracy = r() % 100 + 1;
        critchance = r() % 100 + 1;
        if (accuracy > 10 && critchance <= 5) {
            d = r() % 10 + ceil(attackPower * 1.5);
            cout << name << " dealt " << d << " damage." << endl;
            Target->takeDmg(d);
        }
        else if (accuracy > 10) {
            d = r() % 10 + attackPower;
            cout << name << " dealt " << d << " damage." << endl;
            Target->takeDmg(d);
        }
        else if (accuracy <= 10) {
            cout << name << " has missed its attack!" << endl;
        }
    }
    else if (health > 0) {
        accuracy = r() % 100 + 1;
        critchance = r() % 100 + 1;
        if (accuracy > 10 && critchance <= 5) {
            d = r() % 6 + ceil(attackPower * 1.5);
            cout << name << " dealt " << d << " damage." << endl;
            Target->takeDmg(d);
        }
        else if (accuracy > 10) {
            d = r() % 6 + attackPower;
            cout << name << " dealt " << d << " damage." << endl;
            Target->takeDmg(d);
        }
        else if (accuracy <= 10) {
            cout << name << " has missed its attack!" << endl;
        }
    }
    else if (usinginvispotion == false && health <= 0) {
        cout << "You have killed the " << name << "!" << endl;
    }
}
