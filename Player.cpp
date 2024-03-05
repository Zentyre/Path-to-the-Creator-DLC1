#include "Player.h"
#include <iostream>
#include <random>
#include <cmath>
Player::Player(string n, int maxh, int hp, int atk, int def, int baselvl, int live) {
    name = n;
    maxhealth = maxh;
    health = hp;
    attackPower = atk;
    defense = def;
    baselevel = baselvl;
    lives = live;
}
Enemy enemy("null", 0, 0, 0, 0, 0, 0);
int Player::calculatePoints(const std::string& input) {
    std::map<char, int> letterPoints = {
        {'a', (r() % 10 + 1)}, {'b', (r() % 10 + 1)}, {'c', (r() % 10 + 1)}, {'d', (r() % 10 + 1)}, {'e', (r() % 10 + 1)},
        {'f', (r() % 10 + 1)}, {'g', (r() % 10 + 1)}, {'h', (r() % 10 + 1)}, {'i', (r() % 10 + 1)}, {'j', (r() % 10 + 1)},
        {'k', (r() % 10 + 1)}, {'l', (r() % 10 + 1)}, {'m', (r() % 10 + 1)}, {'n', (r() % 10 + 1)}, {'o', (r() % 10 + 1)},
        {'p', (r() % 10 + 1)}, {'q', (r() % 10 + 1)}, {'r', (r() % 10 + 1)}, {'s', (r() % 10 + 1)}, {'t', (r() % 10 + 1)},
        {'u', (r() % 10 + 1)}, {'v', (r() % 10 + 1)}, {'w', (r() % 10 + 1)}, {'x', (r() % 10 + 1)}, {'y', (r() % 10 + 1)},
        {'z', (r() % 10 + 1)}
    };

    int totalPoints = 0;
    for (char letter : input) {
        // Convert the letter to lowercase for case-insensitive comparison
        char lowercaseLetter = std::tolower(letter);

        // Check if the letter is in the map
        if (letterPoints.find(lowercaseLetter) != letterPoints.end()) {
            // Add the corresponding points to the total
            totalPoints += letterPoints[lowercaseLetter];
        }
    }
    return totalPoints;
}
void Player::village(Enemy* Target) {
    if (baselevel > 200) {
        if (visitedbefore == true) {
            cout << "Welcome back to the village!" << endl;
            isplayingvillage = true;
            string yesno = "";
            if (villagerandomevent == 0) {
                villagerandomevent = r() % 2 + 1;
            }
            if (villagerandomevent == 1) {
                if (randommessage != 1 && randommessage != 2 && randommessage != 3) {
                    randommessage = r() % 3;
                }
                if (randommessage == 0) {
                    cout << "The well broke and they are losing water fast, rebuild it!" << endl;
                    cout << "You need 2 wood to repair this. You have " << wood << "wood." << endl;
                    cout << "Would you like to repair it?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y") {
                        wood -= 2;
                        cout << "You have repaired the villages well! You got 1 Soulstone, 2 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have enough wood to save the village." << endl;
                    }
                }
                else if (randommessage == 1) {
                    cout << "There's a fire, put it out quick!!" << endl;
                    if (bucketowater == 0) {
                        cout << "You need a water bucket to put out the fire. You have " << bucketowater << " water buckets." << endl;
                    }
                    else if (bucketowater > 1) {
                        cout << "You need a water bucket to put out the fire. You have " << bucketowater << " water buckets." << endl;
                    }
                    else if (bucketowater == 1) {
                        cout << "You need a water bucket to put out the fire. You have " << bucketowater << " water bucket." << endl;
                    }
                    cout << "Would you like to put out the fire?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y") {
                        bucketowater -= 1;
                        cout << "You have put out the fire! You got 1 Soulstone, 2 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have water to save the village." << endl;
                    }
                }
                else {
                    cout << "A villagers house was destroyed by a storm, fix it!" << endl;
                    cout << "You need 5 wood to repair the house. You have " << wood << " wood." << endl;
                    cout << "Would you like to repair the house?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if ((yesno == "yes" || yesno == "y") && wood > 5) {
                        wood -= 5;
                        cout << "You have repaired the house! You got 1 Soulstone, 3 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 3;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have enough wood to save the village." << endl;
                    }
                    else {
                        cout << "You don't have enough wood for this. Come back when you have more." << endl;
                    }
                }
            }
            else if (villagerandomevent == 2) {
                if (randommessage != 1 && randommessage != 2 && randommessage != 3) {
                    randommessage = r() % 3;
                }
                if (randommessage == 0) {
                    cout << "A villager is sick and needs your help to heal him." << endl;
                    cout << "You need medicine to heal the villager. You have " << medicine << " medical supplies." << endl;
                    cout << "Would you like to heal the villager?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y") {
                        medicine -= 1;
                        cout << "You give the villager the medicine and he starts to feel better. You got 1 Soulstone, 2 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have medicine to save the villager." << endl;
                    }
                }
                else if (randommessage == 1) {
                    cout << "The village is running low on supplies, make a donation." << endl;
                    cout << "You need 3 wood and 2 food to donate to this villager. You have " << wood << " wood and " << food << " food." << endl;
                    cout << "Would you like to donate to the villager?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y") {
                        wood -= 3;
                        food -= 2;
                        cout << "You have helped this poor villager! You got 2 Soulstone, 3 Radiant Gems and 1 Lost Artifact." << endl;
                        soulstone += 2;
                        radiantgem += 3;
                        lostartifact++;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have wood and food to save the villager." << endl;
                    }
                }
                else {
                    cout << "A villager needs some food, give him some." << endl;
                    cout << "You need 3 food to help the villager. You have " << food << " food." << endl;
                    cout << "Would you like give the villager some food?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y") {
                        food -= 3;
                        cout << "You have given the villager food! You got 1 Soulstone and 2 Radiant Gems." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have food to save the villager." << endl;
                    }
                }
            }
            else {
                cout << "Your return is welcomed with open arms, but there is nothing wrong." << endl;
            }
        }
        else if (villagetracker < 10) {
            cout << "The villagers are still happy with your work and have no problems. Check again later." << endl;
        }
        else {
            visitedbefore = true;
            cout << "Welcome to the village! I see this is your first visit. Here you take care of this village, defend them from attackers and help them repair buildings and you'll be rewarded." << endl;
            isplayingvillage = true;
            string yesno = "";
            if (villagerandomevent == 0) {
                villagerandomevent = r() % 2 + 1;
            }
            if (villagerandomevent == 1) {
                if (randommessage != 1 && randommessage != 2 && randommessage != 3) {
                    randommessage = r() % 3;
                }
                if (randommessage == 0) {
                    cout << "The well broke and they are losing water fast, rebuild it!" << endl;
                    cout << "You need 2 wood to repair this. You have " << wood << " wood." << endl;
                    cout << "Would you like to repair it?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y" && wood >= 2) {
                        wood -= 2;
                        cout << "You have repaired the villages well! You got 1 Soulstone, 2 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have enough wood to save the village." << endl;
                    }
                }
                else if (randommessage == 1) {
                    cout << "There's a fire, put it out quick!!" << endl;
                    if (bucketowater == 0) {
                        cout << "You need a water bucket to put out the fire. You have " << bucketowater << " water buckets." << endl;
                    }
                    else if (bucketowater > 1) {
                        cout << "You need a water bucket to put out the fire. You have " << bucketowater << " water buckets." << endl;
                    }
                    else if (bucketowater == 1) {
                        cout << "You need a water bucket to put out the fire. You have " << bucketowater << " water bucket." << endl;
                    }
                    cout << "Would you like to put out the fire?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y" && bucketowater >= 1) {
                        bucketowater -= 1;
                        cout << "You have put out the fire! You got 1 Soulstone, 2 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have water to save the village." << endl;
                    }
                }
                else {
                    cout << "A villagers house was destroyed by a storm, fix it!" << endl;
                    cout << "You need 5 wood to repair the house. You have " << wood << " wood." << endl;
                    cout << "Would you like to repair the house?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if ((yesno == "yes" || yesno == "y") && wood >= 5) {
                        wood -= 5;
                        cout << "You have repaired the house! You got 1 Soulstone, 3 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 3;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have enough wood to save the village." << endl;
                    }
                    else {
                        cout << "You don't have enough wood for this. Come back when you have more." << endl;
                    }
                }
            }
            else if (villagerandomevent == 2) {
                if (randommessage != 1 && randommessage != 2 && randommessage != 3) {
                    randommessage = r() % 3;
                }
                if (randommessage == 0) {
                    cout << "A villager is sick and needs your help to heal him." << endl;
                    cout << "You need medicine to heal the villager. You have " << medicine << " medical supplies." << endl;
                    cout << "Would you like to heal the villager?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y" && medicine >= 1) {
                        medicine -= 1;
                        cout << "You give the villager the medicine and he starts to feel better. You got 1 Soulstone, 2 Radiant Gems and 1 Food." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        food += 1;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have medicine to save the villager." << endl;
                    }
                }
                else if (randommessage == 1) {
                    cout << "The village is running low on supplies, make a donation." << endl;
                    cout << "You need 3 wood and 2 food to donate to this villager. You have " << wood << " wood and " << food << " food." << endl;
                    cout << "Would you like to donate to the villager?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y" && wood >= 3 && food >= 2) {
                        wood -= 3;
                        food -= 2;
                        cout << "You have helped this poor villager! You got 2 Soulstone, 3 Radiant Gems and 1 Lost Artifact." << endl;
                        soulstone += 2;
                        radiantgem += 3;
                        lostartifact++;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have wood and food to save the villager." << endl;
                    }
                }
                else {
                    cout << "A villager needs some food, give him some." << endl;
                    cout << "You need 3 food to help the villager. You have " << food << " food." << endl;
                    cout << "Would you like give the villager some food?" << endl;
                    cin >> ws;
                    getline(cin, yesno);
                    std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                    if (yesno == "yes" || yesno == "y" && food >= 3) {
                        food -= 3;
                        cout << "You have given the villager food! You got 1 Soulstone and 2 Radiant Gems." << endl;
                        soulstone += 1;
                        radiantgem += 2;
                        villagerandomevent = 0;
                        randommessage = 0;
                    }
                    else if (yesno == "no" || yesno == "n") {
                        cout << "Come back when you have food to save the villager." << endl;
                    }
                }
            }
            else {
                cout << "Your return is welcomed with open arms, but there is nothing wrong." << endl;
            }

        }
    }
    else {
        cout << "You have not unlocked this feature yet. You must be atleast baselevel 200." << endl;
    }
}
void Player::mysteriousquest() {
    int randomgoldloom = 0, randomsoulstone = 0, randomgem = 0, randomlostartifact = 0;
    cout << "You have completed my quest " << name << ". Here is your reward for your assistance." << endl;
    randomgoldloom = r() % 50 + 1;
    Goldloom += randomgoldloom;
    cout << randomgoldloom << " Goldloom, ";
    randomsoulstone = r() % 3 + 1;
    soulstone += randomsoulstone;
    cout << randomsoulstone << "Soulstone, ";
    randomlostartifact = r() % 10 + 1;
    if (randomlostartifact == 1) {
        randomgem = r() % 5 + 2;
        radiantgem += randomgem;
        cout << randomgem << "Radiant Gems, ";
        cout << "1 Lost Artifact." << endl;
    }
    else {
        randomgem = r() % 5 + 2;
        radiantgem += randomgem;
        cout << randomgem << "Radiant Gems.";
    }
    mysteriousstrangerquestactive = false;
    mysteriousstrangerquest = false;
    mysteriousstrangerquest2 = false;
    mysteriousstrangerquest3 = false;
    mysteriousstrangerquest4 = false;
    mysteriousstrangerquest5 = false;
    mysteriousstrangerquesttracker = 0;
    mysteriousstrangerquesttracker2 = 0;
    mysteriousstrangerquesttracker3 = 0;
    mysteriousstrangerquesttracker4 = 0;
    mysteriousstrangerquesttracker5 = 0;
}
void Player::playerclassexecutioner() {
    maxhealth -= 14;
    health -= 7;
    attackPower += 4;
    defense += 1;
    classtype = 2;
}
void Player::playerclasssoulweaver() {
    maxhealth -= 12;
    health -= 6;
    attackPower -= 2;
    defense += 2;
    addlives(1);
    classtype = 3;
}
void Player::playerclasswarforged() {
    maxhealth += 24;
    health += 12;
    attackPower -= 2;
    defense += 3;
    classtype = 4;
}
void Player::playerclassdreadnought() {
    maxhealth += 40;
    health += 20;
    attackPower -= 3;
    defense += 3;
    classtype = 5;
}
void Player::playerclasstrickster() {
    maxhealth -= 10;
    health -= 5;
    attackPower += 1;
    defense += 1;
    classtype = 6;
}
void Player::itemusehealthtonic() {
    setmaxhealth();
    if (level >= 200) {
        health += 150;
    }
    else if (level >= 150) {
        health += 100;
    }
    else if (level >= 100) {
        health += 75;
    }
    else if (level >= 50) {
        health += 50;
    }
    else {
        health += 25;
    }
    if (health > maxhealth) {
        health = maxhealth;
    }
    if (healthtonicitem >= 1) {
        healthtonicitem -= 1;
    }
    cout << "You now have " << health << " health." << endl;
}
void Player::forgerestarting() {
    string forgeUpgrade = "", forgechoice = "";
    while (true) {
        cout << "What would you like to upgrade?" << endl;
        if (ciphertracker == 4) {
            cout << "If you are here to craft the Regenerative Mantle instead of using the feature named CRAFTING, type Mantle. I hope this was worth my inconvenience of coding the craft here too." << endl;
        }
        cin >> ws;
        getline(cin, forgeUpgrade);
        std::transform(forgeUpgrade.begin(), forgeUpgrade.end(), forgeUpgrade.begin(), ::tolower);
        if (forgeUpgrade == "narso's armor" && (armorupgrade == true || lightningshard == true) && narsosArmor == true) {
            cout << "What would you like to use to upgrade Narso's Armor? (Lightning Shard or Armor Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded Narso's Armor using a Lightning Shard!" << endl;
                lightningGodarmor = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                narsosArmor = false;
            }
            else if (forgechoice == "armor upgrade") {
                cout << "You have upgraded Narso's Armor using an Armor Upgrade!" << endl;
                upgradedgodarmor = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                narsosArmor = false;
            }
            else {
                cout << "That wasn't Armor Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "lockhart's armor" && (armorupgrade == true || lightningshard == true) && lockhartsArmor == true) {
            cout << "What would you like to use to upgrade Lockhart's Armor? (Lightning Shard or Armor Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded Lockhart's Armor using a Lightning Shard!" << endl;
                lightningGodarmor = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                lockhartsArmor = false;
            }
            else if (forgechoice == "armor upgrade") {
                cout << "You have upgraded Lockhart's Armor using an Armor Upgrade!" << endl;
                upgradedgodarmor = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                lockhartsArmor = false;
            }
            else {
                cout << "That wasn't Armor Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "vladimir's armor" && (armorupgrade == true || lightningshard == true) && vladimirsArmor == true) {
            cout << "What would you like to use to upgrade Vladimir's Armor? (Lightning Shard or Armor Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded Vladimir's Armor using a Lightning Shard!" << endl;
                lightningGodarmor = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                vladimirsArmor = false;
            }
            else if (forgechoice == "armor upgrade") {
                cout << "You have upgraded Vladimir's Armor using an Armor Upgrade!" << endl;
                upgradedgodarmor = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                vladimirsArmor = false;
            }
            else {
                cout << "That wasn't Armor Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "glass shoes" && (armorupgrade == true || lightningshard == true) && glassshoes == true) {
            cout << "What would you like to use to upgrade your Glass Shoes? (Lightning Shard or Armor Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded your Glass Shoes using a Lightning Shard!" << endl;
                lightningglassshoes = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                glassshoes = false;
            }
            else if (forgechoice == "armor upgrade") {
                cout << "You have upgraded your Glass Shoes using an Armor Upgrade!" << endl;
                upgradedglassshoes = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                glassshoes = false;
            }
            else {
                cout << "That wasn't Armor Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "mystic helmet" || forgeUpgrade == "Mystic helmet" || forgeUpgrade == "mystic Helmet" || forgeUpgrade == "Mystic Helmet" && (armorupgrade == true || lightningshard == true) && mystichelmet == true) {
            cout << "What would you like to use to upgrade your Mystic Helmet? (Lightning Shard or Armor Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded your Mystic Helmet using a Lightning Shard!" << endl;
                lightningmystichelmet = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                mystichelmet = false;
            }
            else if (forgechoice == "armor upgrade") {
                cout << "You have upgraded your Mystic Helmet using an Armor Upgrade!" << endl;
                upgradedmystichelmet = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                mystichelmet = false;
            }
            else {
                cout << "That wasn't Armor Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "dragonscale chestplate" && (armorupgrade == true || lightningshard == true) && dragonscalechestplate == true) {
            cout << "What would you like to use to upgrade your Dragonscale Chestplate? (Lightning Shard or Armor Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded Nyour Dragonscale Chestplate using a Lightning Shard!" << endl;
                lightningdragonscalechestplate = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                dragonscalechestplate = false;
            }
            else if (forgechoice == "armor upgrade") {
                cout << "You have upgraded your Dragonscale Chestplate using an Armor Upgrade!" << endl;
                upgradedDragonscalechestplate = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest4 == true) {
                    mysteriousstrangerquesttracker4 += 1;
                    if (mysteriousstrangerquesttracker4 == 3) {
                        mysteriousquest();
                    }
                }
                dragonscalechestplate = false;
            }
            else {
                cout << "That wasn't Armor Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "flaming longsword" && (weaponupgrade == true || lightningshard == true) && flaminglongsword == true) {
            cout << "What would you like to use to upgrade the Flaming Longsword? (Lightning Shard or Weapon Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded your Flaming Longsword using a Lightning Shard!" << endl;
                lightningflaminglongsword = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest5 == true) {
                    mysteriousstrangerquesttracker5 += 1;
                    if (mysteriousstrangerquesttracker5 == 2) {
                        mysteriousquest();
                    }
                }
                flaminglongsword = false;
            }
            else if (forgechoice == "weapon upgrade") {
                cout << "You have upgraded your Flaming Longsword using a Weapon Upgrade!" << endl;
                upgradedflaminglongsword = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest5 == true) {
                    mysteriousstrangerquesttracker5 += 1;
                    if (mysteriousstrangerquesttracker5 == 2) {
                        mysteriousquest();
                    }
                }
                flaminglongsword = false;
            }
            else {
                cout << "That wasn't Weapon Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "excalibur" && (weaponupgrade == true || lightningshard == true) && Excalibur == true) {
            cout << "What would you like to use to upgrade your Excalibur? (Lightning Shard or Weapon Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded your Excalibur using a Lightning Shard!" << endl;
                lightningexcalibur = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest5 == true) {
                    mysteriousstrangerquesttracker5 += 1;
                    if (mysteriousstrangerquesttracker5 == 2) {
                        mysteriousquest();
                    }
                }
                Excalibur = false;
            }
            else if (forgechoice == "weapon upgrade") {
                cout << "You have upgraded your Excalibur using a Weapon Upgrade!" << endl;
                upgradedexcalibur = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest5 == true) {
                    mysteriousstrangerquesttracker5 += 1;
                    if (mysteriousstrangerquesttracker5 == 2) {
                        mysteriousquest();
                    }
                }
                Excalibur = false;
            }
            else {
                cout << "That wasn't Weapon Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "voidshroud slicer" && (weaponupgrade == true || lightningshard == true) && VoidshroudSlicer == true) {
            cout << "What would you like to use to upgrade your Voidshroud Slicer? (Lightning Shard or Weapon Upgrade)" << endl;
            cin >> ws;
            getline(cin, forgechoice);
            std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
            if (forgechoice == "lightning shard") {
                cout << "You have upgraded your Voidshroud Slicer using a Lightning Shard!" << endl;
                lightningvoidshroudslicer = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest5 == true) {
                    mysteriousstrangerquesttracker5 += 1;
                    if (mysteriousstrangerquesttracker5 == 2) {
                        mysteriousquest();
                    }
                }
                VoidshroudSlicer = false;
            }
            else if (forgechoice == "weapon upgrade") {
                cout << "You have upgraded your Voidshroud Slicer using a Weapon Upgrade!" << endl;
                upgradedvoidshroudslicer = true;
                checkitems();
                if (forgeanitemquest == true) {
                    questthreeprogress += 1;
                }
                if (mysteriousstrangerquest5 == true) {
                    mysteriousstrangerquesttracker5 += 1;
                    if (mysteriousstrangerquesttracker5 == 2) {
                        mysteriousquest();
                    }
                }
                VoidshroudSlicer = false;
            }
            else {
                cout << "That wasn't Weapon Upgrade or Lightning Shard. Try again." << endl;
            }
        }
        else if (forgeUpgrade == "mantle" && radiantgem >= 4 && soulstone >= 2 && Goldloom >= 50 && healthtonicitem >= 1) {
            string yesno = "";
            cout << "Are you sure you want to craft the Regenerative Mantle?" << endl;
            cin >> ws;
            getline(cin, yesno);
            std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
            if (yesno == "yes" || yesno == "y") {
                cout << "You now have the Regenerative Mantle!" << endl;
                radiantgem -= 4;
                soulstone -= 2;
                Goldloom -= 50;
                healthtonicitem -= 1;
                regenerativemantle = true;
                if (craftanitemquest == true) {
                    questtwoprogress += 1;
                }
            }
            else if (yesno == "no" || yesno == "n") {
                cout << "Come again later and ill make it for you." << endl;
                break;
            }
            else {
                cout << "That wasnt yes or no. Try again." << endl;
            }
        }
        else {
            cout << "That item does not exist or you dont have the required materials. Try again." << endl;
            break;
        }
        cout << "Would you like to upgrade something else?" << endl;
        cin >> forgechoice;
        std::transform(forgechoice.begin(), forgechoice.end(), forgechoice.begin(), ::tolower);
        if (forgechoice == "no" || forgechoice == "n") {
            break;
        }
    }
}
void Player::forgecrafting() {
    string craftingchoice = "";
    int craftedsomething = 0, trackwhatcanbecrafted = 0;
    while (true) {
        cout << "You have these crafting materials currently." << endl;
        if (soulstone >= 1) {
            if (soulstone == 1) {
                cout << "-" << soulstone << " Soulstone" << endl;
            }
            else {
                cout << "-" << soulstone << " Soulstones" << endl;
            }
        }
        if (radiantgem >= 1) {
            if (radiantgem == 1) {
                cout << "-" << radiantgem << " Radiant Gem" << endl;
            }
            else {
                cout << "-" << radiantgem << " Radiant Gems" << endl;
            }
        }
        cout << endl << "You can currently craft ";
        if (soulstone >= 2 && radiantgem >= 4 && Goldloom >= 50 && healthtonicitem >= 1) {
            cout << "the Regenerative Mantle";
            trackwhatcanbecrafted += 1;
        }
        if (lostartifact > 0 && soulstone >= 1 && radiantgem >= 2 && Goldloom >= 25) {
            if (trackwhatcanbecrafted == 1) {
                cout << ", ";
            }
            cout << "any artifact";
            trackwhatcanbecrafted += 1;
        }
        if (trackwhatcanbecrafted == 0) {
            cout << "nothing." << endl;
            break;
        }
        else {
            cout << "." << endl;
        }
        cout << "What would you like to craft?" << endl;
        cin >> ws;
        getline(cin, craftingchoice);
        std::transform(craftingchoice.begin(), craftingchoice.end(), craftingchoice.begin(), ::tolower);
        if (craftingchoice == "mantle") {
            string yesno = "";
            cout << "Are you sure you want to craft the Regenerative Mantle?" << endl;
            cin >> ws;
            getline(cin, yesno);
            std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
            if (yesno == "yes" || yesno == "y") {
                if (radiantgem >= 4 && soulstone >= 2 && Goldloom >= 50 && healthtonicitem >= 1) {
                    cout << "You now have the Regenerative Mantle!" << endl;
                    radiantgem -= 4;
                    soulstone -= 2;
                    Goldloom -= 50;
                    healthtonicitem -= 1;
                    regenerativemantle = true;
                    craftedsomething++;
                    if (craftanitemquest == true) {
                        questtwoprogress += 1;
                    }
                    ciphertracker = 5;
                }
                else {
                    cout << "You don't have the required materials to craft this yet." << endl;
                }
            }
            else if (yesno == "no" || yesno == "n") {
                cout << "Come again later and ill make it for you." << endl;
                break;
            }
            else {
                cout << "That wasnt yes or no." << endl;
            }
        }
        else if (craftingchoice == "artifact") {
            string yesno = "";
            cout << "Are you sure you want to craft a cursed artifact?" << endl;
            cin >> ws;
            getline(cin, yesno);
            std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
            if (yesno == "yes" || yesno == "y") {
                cout << "Would you like to craft the 1-Cursed Heart, 2-Enchanted Sachel, 3-Glowing Glasses, 4-Fiery Necklace or 5-Shiny Belt." << endl;
                getline(cin, yesno);
                if (yesno == "1" && lostartifact > 0 && soulstone >= 1 && radiantgem >= 2 && Goldloom >= 25) {
                    cout << "You crafted a Cursed Heart!" << endl;
                    cursedheart = true;
                    lostartifact -= 1;
                    soulstone -= 1;
                    radiantgem -= 1;
                    Goldloom -= 25;
                    if (craftanitemquest == true) {
                        questtwoprogress += 1;
                    }
                    if (mysteriousstrangerquest2 == true) {
                        mysteriousquest();
                    }
                    craftedsomething++;
                }
                else if (yesno == "2" && lostartifact > 0 && soulstone >= 1 && radiantgem >= 2 && Goldloom >= 25) {
                    cout << "You crafted an Enchanted Sachel!" << endl;
                    enchantedsachel = true;
                    lostartifact -= 1;
                    soulstone -= 1;
                    radiantgem -= 1;
                    Goldloom -= 25;
                    if (craftanitemquest == true) {
                        questtwoprogress += 1;
                    }
                    craftedsomething++;
                }
                else if (yesno == "3" && lostartifact > 0 && soulstone >= 1 && radiantgem >= 2 && Goldloom >= 25) {
                    cout << "You crafted some Glowing Glasses!" << endl;
                    glowingglasses = true;
                    lostartifact -= 1;
                    soulstone -= 1;
                    radiantgem -= 1;
                    Goldloom -= 25;
                    if (craftanitemquest == true) {
                        questtwoprogress += 1;
                    }
                    craftedsomething++;
                }
                else if (yesno == "4" && lostartifact > 0 && soulstone >= 1 && radiantgem >= 2 && Goldloom >= 25) {
                    cout << "You crafted the Fiery Necklace!" << endl;
                    fierynecklace = true;
                    lostartifact -= 1;
                    soulstone -= 1;
                    radiantgem -= 1;
                    Goldloom -= 25;
                    if (craftanitemquest == true) {
                        questtwoprogress += 1;
                    }
                    craftedsomething++;
                }
                else if (yesno == "5" && lostartifact > 0 && soulstone >= 1 && radiantgem >= 2 && Goldloom >= 25) {
                    cout << "You crafted a Shiny Belt!" << endl;
                    shinybelt = true;
                    lostartifact -= 1;
                    soulstone -= 1;
                    radiantgem -= 1;
                    Goldloom -= 25;
                    if (craftanitemquest == true) {
                        questtwoprogress += 1;
                    }
                    craftedsomething++;
                }
                else {
                    cout << "You don't have the required materials to craft an artifact." << endl;
                }
            }
            else if (yesno == "no" || yesno == "n") {
                cout << "Come again later and i'll make it for you." << endl;
                break;
            }
            else {
                cout << "That wasnt yes or no." << endl;
            }
        }
        if (craftedsomething == 1) {
            craftedsomething -= 1;
            cout << "Would you like to craft anything else?" << endl;
            cin >> craftingchoice;
            if (craftingchoice == "No" || craftingchoice == "no" || craftingchoice == "n" || craftingchoice == "N") {
                break;
            }
        }
        else {
            cout << "Come again! but craft something next time." << endl;
        }
    }
}

void Player::setmaxhealth() {
    int charactermaxhealth = 0;
    if (level >= 500) {
        charactermaxhealth = 500;
    }
    else if (level >= 450) {
        charactermaxhealth = 450;
    }
    else if (level >= 400) {
        charactermaxhealth = 400;
    }
    else if (level >= 350) {
        charactermaxhealth = 350;
    }
    else if (level >= 300) {
        charactermaxhealth = 300;
    }
    else if (level >= 250) {
        charactermaxhealth = 250;
    }
    else if (level >= 200) {
        charactermaxhealth = 200;
    }
    else if (level >= 150) {
        charactermaxhealth = 150;
    }
    else if (level >= 100) {
        charactermaxhealth = 100;
    }
    else if (level >= 75) {
        charactermaxhealth = 75;
    }
    else if (level >= 50) {
        charactermaxhealth = 50;
    }
    else {
        charactermaxhealth = 30;
    }
    //adds more health based on maxhealthupgrade amount
    if (maxhealthtracker >= 1) {
        charactermaxhealth += 50 * maxhealthtracker;
    }
    //adds more health based on items
    if (upgradedexcalibur == true) {
        charactermaxhealth += trackexcaliburmaxhealth;
    }
    if (upgradedflaminglongsword == true) {
        charactermaxhealth += trackflamingmaxhealth;
    }
    if (upgradedvoidshroudslicer == true) {
        charactermaxhealth += trackvoidshroudmaxhealth;
    }
    if (upgradedDragonscalechestplate == true) {
        charactermaxhealth += 25;
    }
    if (lightningdragonscalechestplate == true) {
        charactermaxhealth += 14;
    }
    if (upgradedgodarmor == true) {
        charactermaxhealth += 40;
    }
    if (upgradedmystichelmet == true) {
        charactermaxhealth += 20;
    }
    if (upgradedglassshoes == true) {
        charactermaxhealth += 14;
    }
    if (mystichelmet == true) {
        charactermaxhealth += 8;
    }
    if (helmet == true) {
        charactermaxhealth += 5;
    }
    if (boots == true) {
        charactermaxhealth += 4;
    }
    if (chestplate == true) {
        charactermaxhealth += 8;
    }
    if (narsosArmor == true) {
        charactermaxhealth += 12;
    }
    if (lockhartsArmor == true) {
        charactermaxhealth += 12;
    }
    if (vladimirsArmor == true) {
        charactermaxhealth += 12;
    }
    //maxhealth upgrade based on faction
    if (factionchoiceint == 3) {
        charactermaxhealth += ceil(.01 * (kills - 50));
    }
    if (factionchoiceint == 4) {
        charactermaxhealth += ceil(.01 * (kills - 50));
    }
    //maxhealth based on classes
    if (classtype == 2) {
        charactermaxhealth -= 14;
    }
    else if (classtype == 3 || classtype == 6) {
        charactermaxhealth -= 12;
    }
    else if (classtype == 4) {
        charactermaxhealth += 24;
    }
    else if (classtype == 5) {
        charactermaxhealth += 40;
    }
    maxhealth = charactermaxhealth;
    if (health > maxhealth) {
        health = maxhealth;
    }
}
void Player::checkitems() {
    if (Excalibur == true) {
        if (excaliburtracker == 0) {
            attackPower += 14;
            excaliburtracker += 1;
        }
    }
    if (VoidshroudSlicer == true) {
        if (factionchoiceint == 1 && voidshroudtracker > 0 && voidshroudtracker < 2) {
            attackPower += 6;
            voidshroudtracker += 1;
        }
        else if (voidshroudtracker == 0) {
            attackPower += 18;
            voidshroudtracker += 1;
        }
    }
    if (Knife == true) {
        if (knifetracker == 0) {
            attackPower += 2;
            knifetracker += 1;
        }
    }
    if (Sword == true) {
        if (swordtracker == 0) {
            attackPower += 4.5;
            swordtracker += 1;
        }
    }
    if (leveltonic == true) {
        level += 10;
        tracklevelpotion += 1;
        leveltonic = false;
    }
    if (superiorleveltonic == true) {
        level += 15;
        tracksuperiorlevelpotion += 1;
        superiorleveltonic = false;
    }
    if (superpotion == true) {
        level += 15;
        attackPower += 6;
        tracksuperpotion += 1;
        superpotion = false;
    }
    if (helmet == true) {
        if (helmtracker == 0) {
            defense += 4;
            maxhealth += 5;
            helmtracker += 1;
        }
    }
    if (chestplate == true) {
        if (chesttracker == 0) {
            defense += 7;
            maxhealth += 8;
            chesttracker += 1;
        }
    }
    if (boots == true) {
        if (boottracker == 0) {
            defense += 3;
            maxhealth += 4;
            boottracker += 1;
        }
    }
    if (shield == true) {
        if (shieldtracker == 0) {
            defense += 10;
            shieldtracker += 1;
        }
    }
    if (narsosArmor == true || lockhartsArmor == true || vladimirsArmor == true) {
        if (godtracker == 0) {
            defense += 20;
            maxhealth += 12;
            godtracker += 1;
        }
    }
    if (defenseupgrade == true) {
        if (defenseupgradetracker == 0) {
            defense += 10;
            defenseupgradetracker += 1;
        }
    }
    if (maxhealthupgrade == true) {
        maxhealthtracker += 1;
        setmaxhealth();
        health += 25;
        maxhealthupgrade = false;
    }
    if (attackupgrade == true) {
        attackPower += 10;
        attackupgrade = false;
    }
    if (levelupgrade == true) {
        level += 15;
        levelupgrade = false;
    }
    if (flaminglongsword == true) {
        if (factionchoiceint == 2 && flamingtracker > 0 && flamingtracker < 2) {
            attackPower += 4;
            flamingtracker += 1;
        }
        else if (flamingtracker == 0) {
            attackPower += 11;
            flamingtracker += 1;
        }
    }
    if (dragonscalechestplate == true) {
        if (factionchoiceint == 4 && dragontracker > 0 && dragontracker < 2) {
            defense += 5;
            dragontracker += 1;
        }
        else if (dragontracker == 0) {
            defense += 11;
            maxhealth += 14;
            dragontracker += 1;
        }
    }
    if (glassshoes == true) {
        if (shoetracker == 0) {
            defense += 7;
            maxhealth += 6;
            shoetracker += 1;
        }
    }
    if (mystichelmet == true) {
        if (factionchoiceint == 3 && mystictracker > 0 && mystictracker < 2) {
            defense += 3;
            mystictracker += 1;
        }
        else if (mystictracker == 0) {
            defense += 9;
            maxhealth += 8;
            mystictracker += 1;
        }
    }
    if (healingpotionitem == true) {
        health = maxhealth;
        cout << "You have healed to " << health << " health." << endl;
        healingpotionitem = false;
    }
    if (lightningdragonscalechestplate == true) {
        if (factionchoiceint == 4 && lightningdragontracker > 0 && lightningdragontracker < 2) {
            defense += 5;
            lightningdragontracker += 1;
        }
        else if (lightningdragontracker == 0) {
            defense += 11;
            maxhealth += 14;
            attackPower += 25;
            lightningdragontracker += 1;
        }
    }
    if (upgradedDragonscalechestplate == true) {
        if (factionchoiceint == 4 && upgradeddragontracker > 0 && upgradeddragontracker < 2) {
            defense += 10;
            upgradeddragontracker += 1;
        }
        else if (upgradeddragontracker == 0) {
            defense += 18;
            maxhealth += 25;
            upgradeddragontracker += 1;
        }
    }
    if (lightningexcalibur == true) {
        if (lightningexcaliburtracker == 0) {
            attackPower += 35;
            lightningexcaliburtracker += 1;
        }
    }
    if (upgradedexcalibur == true) {
        if (upgradedexcaltracker == 0) {
            attackPower += 18;
            trackexcaliburmaxhealth += ceil(maxhealth * .25);
            maxhealth += trackexcaliburmaxhealth;
            upgradedexcaltracker += 1;
        }
    }
    if (lightningflaminglongsword == true) {
        if (factionchoiceint == 2 && lightninglongswordtracker > 0 && lightninglongswordtracker < 2) {
            attackPower += 7;
            lightninglongswordtracker += 1;
        }
        else if (lightninglongswordtracker == 0) {
            attackPower += 20;
            lightninglongswordtracker += 1;
        }
    }
    if (upgradedflaminglongsword == true) {
        if (factionchoiceint == 2 && upgradedlongswordtracker > 0 && upgradedlongswordtracker < 2) {
            attackPower += 4;
            defense += 3;
            upgradedlongswordtracker += 1;
        }
        else if (upgradedlongswordtracker == 0) {
            attackPower += 11;
            trackflamingmaxhealth += ceil(maxhealth * .1);
            maxhealth += trackflamingmaxhealth;
            upgradedlongswordtracker += 1;
        }
    }
    if (lightningGodarmor == true) {
        if (lightninggodtracker == 0) {
            defense += 30;
            attackPower += 35;
            lightninggodtracker += 1;
        }
    }
    if (upgradedgodarmor == true) {
        if (upgradedgodtracker == 0) {
            defense += 40;
            maxhealth += 40;
            upgradedgodtracker += 1;
        }
    }
    if (upgradedmystichelmet == true) {
        if (factionchoiceint == 3 && upgradedmystictracker > 0 && upgradedmystictracker < 2) {
            defense += 9;
            upgradedmystictracker += 1;
        }
        else if (upgradedmystictracker == 0) {
            defense += 16;
            maxhealth += 20;
            upgradedmystictracker += 1;
        }
    }
    if (lightningmystichelmet == true) {
        if (factionchoiceint == 3 && lightningmystictracker > 0 && lightningmystictracker < 2) {
            defense += 7;
            lightningmystictracker += 1;
        }
        else if (lightningmystictracker == 0) {
            defense += 12;
            attackPower += 20;
            lightningmystictracker += 1;
        }
    }
    if (upgradedglassshoes == true) {
        if (upgradedglasstracker == 0) {
            defense += 11;
            maxhealth += 14;
            upgradedglasstracker += 1;
        }
    }
    if (lightningglassshoes == true) {
        if (lightningglasstracker == 0) {
            defense += 9;
            attackPower += 12;
            lightningglasstracker += 1;
        }
    }
    if (upgradedvoidshroudslicer == true) {
        if (factionchoiceint == 1 && upgradedvoidshroudtracker > 0 && upgradedvoidshroudtracker < 2) {
            attackPower += 8;
            upgradedvoidshroudtracker += 1;
        }
        else if (upgradedvoidshroudtracker == 0) {
            attackPower += 22;
            trackvoidshroudmaxhealth += ceil(maxhealth * .4);
            maxhealth += trackvoidshroudmaxhealth;
            upgradedvoidshroudtracker += 1;
        }
    }
    if (lightningvoidshroudslicer == true) {
        if (factionchoiceint == 1 && lightningvoidshroudtracker > 0 && lightningvoidshroudtracker < 2) {
            attackPower += 18;
            defense += 5;
            lightningvoidshroudtracker += 1;
        }
        else if (lightningvoidshroudtracker == 0) {
            attackPower += 42;
            lightningvoidshroudtracker += 1;
        }
    }
}
void Player::attack(Character* Target) {
    setmaxhealth();
    int playerInput, x, h;
    string purchasechoice = "", yesnobackpack = "", yesnopurchase = "", forgerestart = "", forgeOption = "", game = "";
    int accuracy = 0;
    if (classtype == 1 && storymode == true) { //knight attack messages |health =25|attackPower=4|lives=1|
        if (knightmove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Titans Strike) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 2 && storymode == true) { //executioner attack messages |health =15|attackPower=7|lives=1|
        if (executionermove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Soul Surge) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 3 && storymode == true) { //soulweaver attack messages |health =20|attackPower=3|lives=2|
        if (soulweavermove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Fortuitous Gambit) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 4 && storymode == true) { //warforged engineer attack messages |health =40|attackPower=3|lives=1|
        if (warforgedmove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Risky Detonation) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 5 && storymode == true) { //dreadnought attack messages |health =50|attackPower=1|lives=1|
        if (dreadnoughtmove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Fortress Fury) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 6 && storymode == true) { //trickster attack messages |health =20|attackPower=5|lives=1|
        if (trickstermove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Confuse) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 1 && endlessmode == true) { //endless knight attack messages |health =25|attackPower=4|lives=1|
        if (baselevel > 200) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Titans Strike) 7 (Store) 8 (Forgery) 9 (Stats) 10 (Inventory) 11 (Quests) 12 (Village) 0 (Special Skill Info)" << endl;
        }
        else if (knightmove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Titans Strike) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 2 && endlessmode == true) { //endless executioner attack messages |health =15|attackPower=7|lives=1|
        if (baselevel > 200) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Soul Surge) 7 (Store) 8 (Forgery) 9 (Stats) 10 (Inventory) 11 (Quests) 12 (Village) 0 (Special Skill Info)" << endl;
        }
        else if (executionermove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Soul Surge) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 3 && endlessmode == true) { //endless soulweaver attack messages |health =20|attackPower=3|lives=2|
        if (baselevel > 200) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Fortuitous Gambit) 7 (Store) 8 (Forgery) 9 (Stats) 10 (Inventory) 11 (Quests) 12 (Village) 0 (Special Skill Info)" << endl;
        }
        else if (soulweavermove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Fortuitous Gambit) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 4 && endlessmode == true) { //endless warforged engineer attack messages |health =40|attackPower=3|lives=1|
        if (baselevel > 200) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Risky Detonation) 7 (Store) 8 (Forgery) 9 (Stats) 10 (Inventory) 11 (Quests) 12 (Village) 0 (Special Skill Info)" << endl;
        }
        else if (warforgedmove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Risky Detonation) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 5 && endlessmode == true) { //endless dreadnought attack messages |health =50|attackPower=1|lives=1|
        if (baselevel > 200) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Fortress Fury) 7 (Store) 8 (Forgery) 9 (Stats) 10 (Inventory) 11 (Quests) 12 (Village) 0 (Special Skill Info)" << endl;
        }
        else if (dreadnoughtmove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Fortress Fury) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    else if (classtype == 6 && endlessmode == true) { //endless trickster attack messages |health =20|attackPower=5|lives=1|
        if (baselevel > 200) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Confuse) 7 (Store) 8 (Forgery) 9 (Stats) 10 (Inventory) 11 (Quests) 12 (Village) 0 (Special Skill Info)" << endl;
        }
        else if (trickstermove == true) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 6 (Confuse) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 50) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 5 (" << 7 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 12 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 25) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 4 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 9 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " heal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else if (baselevel >= 15) {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 3 (" << 6 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 11 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "dmg) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
        else {
            cout << "Choose: 1 (" << 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 8 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " dmg) 2 (" << 2 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << "-" << 5 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower << " lifesteal) 7 (Store) 8 (Forge) 9 (Stats) 10 (Inventory) 11 (Quests) 0 (Special Skill Info)" << endl;
        }
    }
    cin >> playerInput;
    switch (playerInput) {
    case 0:
        if (cin.fail()) {
            cout << endl;
            cout << "----------------------" << endl;
            cout << "Please enter a number." << endl;
            cout << "----------------------" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            attack(Target);
            break;
        }
        if (factionchoiceint == 1) {
            cout << "You are a part of the Shadowborn Syndicate. You gain a .5% increase to attack and defense on kill. You deal more damage with the Voidshroud Slicer." << endl;
            cout << "-----------------------------------------------" << endl;
        }
        else if (factionchoiceint == 2) {
            cout << "You chose the Emberfall Covenant! You gain a 1% increase to attack on kill. You deal more damage with the Flaming Longsword." << endl;
            cout << "-----------------------------------------------" << endl;
        }
        else if (factionchoiceint == 3) {
            cout << "You chose the Celestial Vanguard! You gain a .5% increase to defense and maxhealth on kill. You gain more defense from the Mystic Helmet." << endl;
            cout << "-----------------------------------------------" << endl;
        }
        else if (factionchoiceint == 4) {
            cout << "You are a part of the Ironclad Dominion. You gain a .5% increase to attack and maxhealth on kill. You gain more defense from the Dragonscale Chestplate." << endl;
            cout << "-----------------------------------------------" << endl;
        }
        if (classtype == 1) {
            cout << "--The knight class unlocks its special skill (Titans Strike) at level 80. It is just a normal attack but with more damage.--" << endl << endl;
        }
        else if (classtype == 2) {
            cout << "--The executioner class unlocks its special skill (Soul Surge) at level 80. This skill is a slightly better damage lifesteal with a 20% chance to crit.--" << endl << endl;
        }
        else if (classtype == 3) {
            cout << "--The soulweaver class unlocks its special skill (Fortuitous Gambit) at level 90. This skill is a little damage attack that has a 5% chance to give you a life and a 50% chance to deal damage.--" << endl << endl;
        }
        else if (classtype == 4) {
            cout << "--The warforged engineer unlocks its special skill (Risky Detonation) at level 75. This skill throws a very high damage bomb but also damages you. As this class enemies have 50% of your defense instead of the usual 75%.--" << endl << endl;
        }
        else if (classtype == 5) {
            cout << "--The dreadnought class unlocks its special skill (Fortress Fury) at level 75. This skill deals damage that scales with your defense.--" << endl << endl;
        }
        else if (classtype == 6) {
            cout << "--The trickster class unlocks its special skill (Confuse) at level 50. This skill has a 40% chance to make the enemy attack itself with a crit rate of 30% and it negates all defense, but, if it fails the enemy will also have 100% accuracy for that attack.--" << endl << endl;
        }
        cout << "**NOTE** All special skills have 100% accuracy and 10% crit chance." << endl << endl;
        attack(Target);
        break;
    case 1:
        accuracy = r() & 100 + 1;
        if (accuratesword == true || fallen == true) {
            x = r() % 5 + 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower; //normal attack
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "Your mantle healed you for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            cout << endl;
            fallen = false;
            int message;
            message = r() % 5 + 1;
            if (message == 1) {
                cout << "-----------------------------------------------" << endl;
                cout << name << ", you dealt " << x << " damage." << endl;
            }
            else if (message == 2) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime for " << x << " damage." << endl;
            }
            else if (message == 3) {
                cout << "-----------------------------------------------" << endl;
                cout << "You stabbed the slime for " << x << " damage." << endl;
            }
            else if (message == 4) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime in the face for " << x << " damage." << endl;
            }
            else {
                cout << "-----------------------------------------------" << endl;
                cout << "You bludgeon the slime for " << x << " damage." << endl;
            }
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            break;
        }
        else if (accuracy > 10) {
            x = r() % 5 + 4 + (((level >= 75) ? 30 : floor(level / 2.5))) + attackPower; //normal attack
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            cout << endl;
            fallen = false;
            int message;
            message = r() % 5 + 1;
            if (message == 1) {
                cout << "-----------------------------------------------" << endl;
                cout << name << ", you dealt " << x << " damage." << endl;
            }
            else if (message == 2) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime for " << x << " damage." << endl;
            }
            else if (message == 3) {
                cout << "-----------------------------------------------" << endl;
                cout << "You stabbed the slime for " << x << " damage." << endl;
            }
            else if (message == 4) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime in the face for " << x << " damage." << endl;
            }
            else {
                cout << "-----------------------------------------------" << endl;
                cout << "You bludgeon the slime for " << x << " damage." << endl;
            }
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            break;
        }
        else {
            cout << "-----------------------------------------------" << endl;
            cout << name << " You have slipped and fallen, losing this turn." << endl;
            fallen = true;
            break;
        }
    case 2:
        accuracy = r() & 100 + 1;
        if (accuratesword == true || fallen == true) {
            x = r() % 4 + 2 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            h = ceil(x / 2.5);
            health += h;
            cout << endl;
            fallen = false;
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you dealt " << x << " damage." << endl;
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else if (accuracy > 10) {
            x = r() % 4 + 2 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            h = ceil(x / 2.5);
            health += h;
            cout << endl;
            fallen = false;
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you dealt " << x << " damage." << endl;
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else {
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you have slipped and fallen, losing this turn." << endl;
            fallen = true;
            break;
        }
    case 3:
        accuracy = r() & 100 + 1;
        if (baselevel >= 15 && accuratesword == true || fallen == true) {
            x = r() % 6 + 6 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower; //normal attack
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            cout << endl;
            fallen = false;
            int message;
            message = r() % 5 + 1;
            if (message == 1) {
                cout << "-----------------------------------------------" << endl;
                cout << name << ", you dealt " << x << " damage." << endl;
            }
            else if (message == 2) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime for " << x << " damage." << endl;
            }
            else if (message == 3) {
                cout << "-----------------------------------------------" << endl;
                cout << "You stabbed the slime for " << x << " damage." << endl;
            }
            else if (message == 4) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime in the face for " << x << " damage." << endl;
            }
            else {
                cout << "-----------------------------------------------" << endl;
                cout << "You bludgeon the slime for " << x << " damage." << endl;
            }
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            break;
        }
        else if (baselevel >= 15 && accuracy > 10) {
            x = r() % 6 + 6 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            cout << endl;
            fallen = false;
            int message;
            message = r() % 5 + 1;
            if (message == 1) {
                cout << "-----------------------------------------------" << endl;
                cout << name << ", you dealt " << x << " damage." << endl;
            }
            else if (message == 2) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime for " << x << " damage." << endl;
            }
            else if (message == 3) {
                cout << "-----------------------------------------------" << endl;
                cout << "You stabbed the slime for " << x << " damage." << endl;
            }
            else if (message == 4) {
                cout << "-----------------------------------------------" << endl;
                cout << "You kicked the slime in the face for " << x << " damage." << endl;
            }
            else {
                cout << "-----------------------------------------------" << endl;
                cout << "You bludgeon the slime for " << x << " damage." << endl;
            }
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            break;
        }
        else if (baselevel >= 15 && accuracy <= 10) {
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you have slipped and fallen, losing this turn." << endl;
            fallen = true;
            break;
        }
        else {
            cout << "-----------------------------------------------" << endl;
            cout << "You are not a high enough level for this move." << endl;
            cout << "-----------------------------------------------" << endl;
            cout << endl;
            attack(Target);
            break;
        }
        break;
    case 4:
        accuracy = r() & 100 + 1; //single heal
        if (baselevel >= 25 && accuratesword == true || fallen == true) {
            fallen = false;
            x = r() % 4 + 6 + ((level >= 75) ? 30 : floor(level / 2.5));
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a healing buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            h = x;
            health += h;
            cout << "-----------------------------------------------" << endl;
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else if (baselevel >= 25 && accuracy > 10) {
            fallen = false;
            x = r() % 4 + 6 + ((level >= 75) ? 30 : floor(level / 2.5));
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a healing buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            h = x;
            health += h;
            cout << "-----------------------------------------------" << endl;
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else if (baselevel >= 25 && accuracy <= 10) {
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you have slipped and fallen, losing this turn." << endl;
            fallen = true;
            break;
        }
        else {
            cout << "-----------------------------------------------" << endl;
            cout << "You are not a high enough level for this move." << endl;
            cout << "-----------------------------------------------" << endl;
            cout << endl;
            attack(Target);
            break;
        }
    case 5:
        accuracy = r() & 100 + 1; //lifesteal attack
        if (baselevel >= 50 && accuratesword == true || fallen == true) {
            x = r() % 6 + 7 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            h = ceil(x / 2.5);
            health += h;
            cout << endl;
            fallen = false;
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you dealt " << x << " damage." << endl;
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else if (baselevel >= 50 && accuracy > 10) {
            fallen = false;
            x = r() % 6 + 7 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            h = ceil(x / 2.5);
            health += h;
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you dealt " << x << " damage." << endl;
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else if (baselevel >= 50 && accuracy <= 10) {
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you have slipped and fallen, losing this turn." << endl;
            fallen = true;

            break;
        }
        else {
            cout << "-----------------------------------------------" << endl;
            cout << "You are not a high enough level for this move." << endl;
            cout << "-----------------------------------------------" << endl;
            cout << endl;
            attack(Target);
            break;
        }
    case 6:
        if (soulweavermove == true) {
            int addLifeChance;
            addLifeChance = r() % 100 + 1;
            if (addLifeChance <= 5) {
                addlives(1);
                x = r() % 4 + 4 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
                int critchance = 0;
                critchance = r() % 100 + 1;
                if (critchance <= 10) {
                    x = ceil(x * 1.5);
                }
                if (playercompanion == true) {
                    int randomcompanionevent = 0;
                    cout << "-----------------------------------------------" << endl;
                    randomcompanionevent = r() % 4;
                    if (randomcompanionevent == 0) {
                        cout << "Your companion has mysteriously made your armor stronger!";
                        defense += 2;
                    }
                    else if (randomcompanionevent == 1) {
                        cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                        health += ((level >= 75) ? 30 : floor(level / 2.5));
                    }
                    else if (randomcompanionevent == 2) {
                        cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                        x += ((level >= 75) ? 30 : floor(level / 2.5));
                    }
                    else {
                        cout << "Your companion didn't do anything this round.";
                    }
                }
                if (regenerativemantle == true) {
                    setmaxhealth();
                    int heal = 0;
                    heal += ceil((getlevel() - getbaselevel()) * .25);
                    health += heal;
                    if (health > maxhealth) {
                        health = maxhealth;
                        cout << "You had no wounds to heal." << endl;
                    }
                    else if (health < maxhealth) {
                        cout << "You healed for " << heal << " health." << endl;
                    }
                }
                Target->takeDmg(x);
                cout << "-----------------------------------------------" << endl;
                cout << name << ", you dealt " << x << " damage and gained an extra life!" << endl;
                if (Target->getdefense() > 0) {
                    cout << Target->enemydefenseReduction << endl;
                }
            }
            else if (addLifeChance > 5 && addLifeChance <= 50) {
                x = r() % 4 + 4 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
                int critchance = 0;
                critchance = r() % 100 + 1;
                if (critchance <= 10) {
                    x = ceil(x * 1.5);
                }
                if (playercompanion == true) {
                    int randomcompanionevent = 0;
                    cout << "-----------------------------------------------" << endl;
                    randomcompanionevent = r() % 4;
                    if (randomcompanionevent == 0) {
                        cout << "Your companion has mysteriously made your armor stronger!";
                        defense += 2;
                    }
                    else if (randomcompanionevent == 1) {
                        cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                        health += ((level >= 75) ? 30 : floor(level / 2.5));
                    }
                    else if (randomcompanionevent == 2) {
                        cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                        x += ((level >= 75) ? 30 : floor(level / 2.5));
                    }
                    else {
                        cout << "Your companion didn't do anything this round.";
                    }
                }
                if (regenerativemantle == true) {
                    setmaxhealth();
                    int heal = 0;
                    heal += ceil((getlevel() - getbaselevel()) * .25);
                    health += heal;
                    if (health > maxhealth) {
                        health = maxhealth;
                        cout << "You had no wounds to heal." << endl;
                    }
                    else if (health < maxhealth) {
                        cout << "You healed for " << heal << " health." << endl;
                    }
                }
                Target->takeDmg(x);
                cout << "-----------------------------------------------" << endl;
                cout << name << ", you dealt " << x << " damage." << endl;
                if (Target->getdefense() > 0) {
                    cout << Target->enemydefenseReduction << endl;
                }
            }
            else if (addLifeChance > 50) {
                cout << "-----------------------------------------------" << endl;
                cout << name << ", your skill failed." << endl;
            }
            break;
        }
        else if (warforgedmove == true) {
            x = r() % 26 + 25;
            int critchance = 0;
            critchance = r() % 100 + 1;
            if (critchance <= 10) {
                x = ceil(x * 1.5);
            }
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : level) << "!" << endl;
                    health += ((level >= 75) ? 30 : level);
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : level) << "." << endl;
                    x += ((level >= 75) ? 30 : level);
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            cout << "You threw a bomb at the enemy, it dealt " << x << " damage! You took " << ceil(x / 2.5) << " damage." << endl;
            Target->takeDmg(x);
            health -= ceil(x / 2.5);
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            break;
        }
        else if (trickstermove == true) {
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 3;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            trickstermovebool = true;
            cout << endl;
            break;
        }
        else if (knightmove == true) {
            x = r() % 7 + 8 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            int critchance = 0;
            critchance = r() % 100 + 1;
            if (critchance <= 10) {
                x = ceil(x * 1.5);
            }
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            Target->takeDmg(x);
            cout << name << ", you dealt " << x << " damage." << endl;
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            break;
        }
        else if (dreadnoughtmove == true) {
            x = r() % 7 + 10 + ((level >= 75) ? 30 : floor(level / 2.5));
            int critchance = 0;
            critchance = r() % 100 + 1;
            if (critchance <= 10) {
                x = ceil(x * 1.5);
            }
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            x = x + floor(defense / 2);
            Target->takeDmg(x);
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you dealt " << x << " damage." << endl;
            break;
        }
        else if (executionermove == true) {
            x = r() % 11 + 7 + ((level >= 75) ? 30 : floor(level / 2.5)) + attackPower;
            int critrate;
            critrate = r() % 100 + 1;
            if (critrate <= 10) {
                x = ceil(x * 1.5);
            }
            if (playercompanion == true) {
                int randomcompanionevent = 0;
                cout << "-----------------------------------------------" << endl;
                randomcompanionevent = r() % 4;
                if (randomcompanionevent == 0) {
                    cout << "Your companion has mysteriously made your armor stronger!";
                    defense += 2;
                }
                else if (randomcompanionevent == 1) {
                    cout << "Your companion healed you for " << ((level >= 75) ? 30 : floor(level / 1.5)) << "!";
                    health += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else if (randomcompanionevent == 2) {
                    cout << "Your companion gave you a damage buff of " << ((level >= 75) ? 30 : floor(level / 1.5)) << ".";
                    x += ((level >= 75) ? 30 : floor(level / 2.5));
                }
                else {
                    cout << "Your companion didn't do anything this round.";
                }
            }
            if (regenerativemantle == true) {
                setmaxhealth();
                int heal = 0;
                heal += ceil((getlevel() - getbaselevel()) * .25);
                health += heal;
                if (health > maxhealth) {
                    health = maxhealth;
                    cout << "You had no wounds to heal." << endl;
                }
                else if (health < maxhealth) {
                    cout << "You healed for " << heal << " health." << endl;
                }
            }
            h = ceil(x * .5);
            health += h;
            Target->takeDmg(x);
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << name << ", you dealt " << x << " damage." << endl;
            if (Target->getdefense() > 0) {
                cout << Target->enemydefenseReduction << endl;
            }
            if (health >= maxhealth) {
                health = maxhealth;
                cout << "You have no wounds to heal." << endl;
            }
            else {
                cout << "You healed for " << h << " damage." << endl;
            }
            break;
        }
        else {
            cout << "-------------------------------------" << endl;
            cout << " You have not unlocked this skill." << endl;
            cout << "-------------------------------------" << endl;
            cout << endl;
            attack(Target);
            break;
        }
    case 7:
        if (storetracker >= 6) {
            cout << "Welcome to my store, you are welcome to browse my wares..." << endl;
            cout << "Spelling does count, make sure to be precise in my shop. **NOTES** Only Forge Hammer and Molotov can be bought more than once at a time. Don't buy something you already have." << endl;
            cout << "You currently have " << Goldloom << " Goldloom to spend. Spend it wisely..." << endl << endl;
            if (storesave == 0) {
                shop1 = r() % 5 + 1;
                shop2 = r() % 5 + 6;
                shop3 = r() % 5 + 11;
                storesave = 1;
            }
            if (shop1 == 1) {
                cout << "Armor Plating - 100 - A mysterious plating that enhances armor if combined with a forgehammer..." << endl << endl;
            }
            else if (shop1 == 2) {
                cout << "Sharpening Stone - 100 - A space stone that enhances weapons if combined with a forgehammer..." << endl << endl;
            }
            else if (shop1 == 3) {
                cout << "Forge Hammer - 50 -Used with other items to do various things." << endl << endl;
            }
            else if (shop1 == 4) {
                cout << "Lightning Shard - 200 - When combined with a forgehammer something mysterious will happen to your item..." << endl << endl;
            }
            else if (shop1 == 5) {
                cout << "Invisibility Potion - 400 - Used to skip a battle when you find it necessary.(Can't be used on bosses and you wont recieve rewards from fight)" << endl << endl;
            }
            if (shop2 == 6) {
                cout << "Travelers Backpack - 250 - When you have this item, potions you recieve are now saved and available when you want them, instead of being instantly used." << endl << endl;
            }
            else if (shop2 == 7) {
                cout << "Companion - 500 - This little guy may look innocent but he isn't. Causes random events to happen, good or bad..." << endl << endl;
            }
            else if (shop2 == 8) {
                cout << "Flaming Longsword - 250 - A weapon not as good as excalibur, but a weapon nontheless." << endl << endl;
            }
            else if (shop2 == 9) {
                cout << "Molotov - 250 - Throw this at an enemy to deal 60% of their max health." << endl << endl;
            }
            else if (shop2 == 10) {
                cout << "Dragonscale Chestplate - 250 - A chestplate only wore by the gods..." << endl << endl;
            }
            if (shop3 == 11) {
                cout << "Maxhealth Upgrade - 300 - This item can only be purchases once and increases max health by 50." << endl << endl;
            }
            else if (shop3 == 12) {
                cout << "Healing Potion - 150 - Heals you to max hp (instant use)" << endl << endl;
            }
            else if (shop3 == 13) {
                cout << "Glass Shoes - 250 - I think cinderella dropped something." << endl << endl;
            }
            else if (shop3 == 14) {
                cout << "Mystic Helmet - 250 - A helmet that can protect you from anything that falls on your head." << endl << endl;
            }
            else if (shop3 == 15) {
                cout << "Voidshroud Slicer - 300 - A sword forged specially for the shadows." << endl << endl;
            }
            cout << "Would you like to buy anything this visit?" << endl;
            cin >> ws;
            getline(cin, yesnopurchase);
            std::transform(yesnopurchase.begin(), yesnopurchase.end(), yesnopurchase.begin(), ::tolower);
            if (yesnopurchase == "n" || yesnopurchase == "no") {
                cout << "Maybe next time." << endl << endl;
                attack(Target);
                break;
            }
            else if (yesnopurchase == "yes" || yesnopurchase == "y") {
                cout << "Great!" << endl;
            }
            else {
                cout << "Not a valid answer." << endl;
                attack(Target);
                break;
            }
            cout << "What would you like to buy this visit?" << endl << endl;
            cin >> ws;
            getline(cin, purchasechoice);
            std::transform(purchasechoice.begin(), purchasechoice.end(), purchasechoice.begin(), ::tolower);
            cout << endl;
            if (purchasechoice == "armor plating" && shop1 == 1) {
                if (Goldloom >= 100) {
                    cout << "You bought Armor Plating!" << endl;
                    armorupgrade = true;
                    Goldloom -= 100;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 100) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "sharpening stone" && shop1 == 2) {
                if (Goldloom >= 100) {
                    cout << "You bought a Sharpening Stone!" << endl;
                    weaponupgrade = true;
                    Goldloom -= 100;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 100) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "forge hammer" && shop1 == 3) {
                while (true) {
                    string yesno = "";
                    int amountbought = 0;
                    if (Goldloom >= 25 && amountbought == 1) {
                        cout << "You bought a Forge Hammer!" << endl;
                        forgehammer += 1;
                        Goldloom -= 50;
                        storetracker = 0;
                        checkitems();
                        amountbought += 1;
                        storesave = 0;
                    }
                    else if (Goldloom >= 50 && amountbought == 0) {
                        cout << "You bought a Forge Hammer!" << endl;
                        forgehammer += 1;
                        Goldloom -= 50;
                        storetracker = 0;
                        checkitems();
                        amountbought += 1;
                        storesave = 0;
                    }
                    else if (Goldloom < 50 && amountbought == 0) {
                        cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                        storetracker -= 1;
                        break;
                    }
                    else if (Goldloom < 25 && amountbought == 1) {
                        cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                        storetracker -= 1;
                        break;
                    }
                    if (amountbought == 1) {
                        cout << "Would you like to buy another one for 25 Goldloom?" << endl;
                        cin >> ws;
                        getline(cin, yesno);
                        std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                        cout << "Would you like to buy another one for 125 Goldloom?" << endl;
                        cin >> ws;
                        getline(cin, yesno);
                        std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                        if (yesno == "no" || yesno == "n") {
                            cout << "Your loss." << endl;
                            break;
                        }
                    }
                }
            }
            else if (purchasechoice == "lightning shard" && shop1 == 4) {
                if (Goldloom >= 200) {
                    cout << "You bought a Lightning Shard!" << endl;
                    lightningshard = true;
                    Goldloom -= 200;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 200) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "invisibility potion" && shop1 == 5) {
                if (Goldloom >= 400) {
                    cout << "You bought an Invisibility Potion!" << endl;
                    invisibilitypotion += 1;
                    Goldloom -= 400;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 400) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "travelers backpack" && shop2 == 6) {
                if (Goldloom >= 250) {
                    cout << "You bought A Travelers Backpack!" << endl;
                    travelersbackpack = true;
                    Goldloom -= 250;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 250) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "companion" && shop2 == 7) {
                if (Goldloom >= 500) {
                    cout << "You bought your own special Companion!" << endl;
                    playercompanion = true;
                    Goldloom -= 500;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 500) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "flaming longsword" && shop2 == 8) {
                if (Goldloom >= 250) {
                    cout << "You bought your very own Flaming Longsword!" << endl;
                    flaminglongsword = true;
                    Goldloom -= 250;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 250) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "molotov" && shop2 == 9) {
                while (true) {
                    int amountbought = 0;
                    string yesno = "";
                    if (Goldloom >= 125 && amountbought == 1) {
                        cout << "You bought a Molotov!" << endl;
                        molotov += 1;
                        Goldloom -= 250;
                        storetracker = 0;
                        amountbought += 1;
                        checkitems();
                        storesave = 0;
                    }
                    else if (Goldloom >= 250 && amountbought == 0) {
                        cout << "You bought a Molotov!" << endl;
                        molotov += 1;
                        Goldloom -= 250;
                        storetracker = 0;
                        amountbought += 1;
                        checkitems();
                        storesave = 0;
                    }
                    else if (Goldloom < 250 && amountbought == 0) {
                        cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                        storetracker -= 1;
                        break;
                    }
                    else if (Goldloom < 125 && amountbought == 1) {
                        cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                        storetracker -= 1;
                        break;
                    }
                    if (amountbought == 1) {
                        cout << "Would you like to buy another one for 125 Goldloom?" << endl;
                        cin >> ws;
                        getline(cin, yesno);
                        std::transform(yesno.begin(), yesno.end(), yesno.begin(), ::tolower);
                        if (yesno == "no" || yesno == "n") {
                            cout << "Your loss." << endl;
                            break;
                        }
                    }
                }
            }
            else if (purchasechoice == "dragonscale chestplate" && shop2 == 10) {
                if (Goldloom >= 250) {
                    cout << "You bought a Dragonscale Chestplate!" << endl;
                    dragonscalechestplate = true;
                    Goldloom -= 250;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 250) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "maxhealth upgrade" && shop3 == 11) {
                if (Goldloom >= 300) {
                    cout << "You bought a Maxhealth upgrade!" << endl;
                    maxhealthtracker += 1;
                    Goldloom -= 300;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 300) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "healing potion" && shop3 == 12) {
                if (Goldloom >= 150) {
                    cout << "You bought a Healing Potion!" << endl;
                    healingpotionitem = true;
                    Goldloom -= 150;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 150) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "glass shoes" && shop3 == 13) {
                if (Goldloom >= 250) {
                    cout << "You bought the lost glass shoe!" << endl;
                    glassshoes = true;
                    Goldloom -= 250;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 250) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "mystic helmet" && shop3 == 14) {
                if (Goldloom >= 250) {
                    cout << "You bought a Mystic Helmet!" << endl;
                    mystichelmet = true;
                    Goldloom -= 250;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 250) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else if (purchasechoice == "voidshroud slicer" && shop3 == 15) {
                if (Goldloom >= 300) {
                    cout << "You bought a Voidshroud Slicer!" << endl;
                    VoidshroudSlicer = true;
                    Goldloom -= 300;
                    storetracker = 0;
                    checkitems();
                    storesave = 0;
                }
                else if (Goldloom < 300) {
                    cout << "You are too broke for this item and have lost access to the shop for this round." << endl;
                    storetracker -= 1;
                }
            }
            else {
                cout << "That item does not exist or is not for sale currently." << endl;
                storetracker -= 1;
            }
        }
        else {
            cout << endl << "-The shop is currently being restocked.-" << endl;
        }
        cout << endl;
        attack(Target);
        break;
    case 8:
        cout << "-----------------------------------------------" << endl;
        cout << "Welcome to the forge, " << name << "." << endl;
        if (endlessmode == true) {
            cout << "In this ancient place, you can combine special materials to enhance your stats." << endl;
        }
        else if (storymode == true) {
            cout << "In this ancient place, you can combine special materials with your armor and weapons to enhance their abilities." << endl;
        }
        if (endlessmode == true) {
            cout << "Are you here for forging or crafting?" << endl;
            cin >> ws;
            getline(cin, forgeOption);
            std::transform(forgeOption.begin(), forgeOption.end(), forgeOption.begin(), ::tolower);
            if (forgeOption == "forging") {
                if ((weaponupgrade == false && armorupgrade == false && lightningshard == false && forgehammer == 0 && radiantgem == 0 && soulstone == 0)) {
                    cout << "You have no upgrades to use yet. Go buy some from the store." << endl;
                    cout << "-----------------------------------------------" << endl;
                    attack(Target);
                    break;
                }
                cout << "You have these upgrades currently:" << endl;
                if (weaponupgrade == true) {
                    cout << "-Weapon Upgrade-" << endl;
                }
                if (armorupgrade == true) {
                    cout << "-Armor Upgrade-" << endl;
                }
                if (lightningshard == true) {
                    cout << "-Ligntning Shard-" << endl;
                }
                if (forgehammer > 0) {
                    if (forgehammer == 1) {
                        cout << "-" << forgehammer << " Forgehammer-" << endl;
                    }
                    else {
                        cout << "-" << forgehammer << " Forgehammers-" << endl;
                    }
                }
                if (dragonscalechestplate == false && mystichelmet == false && glassshoes == false && Excalibur == false && flaminglongsword == false && VoidshroudSlicer == false && narsosArmor == false && vladimirsArmor == false && lockhartsArmor == false && ciphertracker <= 3) {
                    cout << "You have no armor or weapons to upgrade, go buy some from the store or get them as a lucky drop." << endl;
                    cout << "-----------------------------------------------" << endl;
                    attack(Target);
                    break;
                }
                cout << "-----------------------------------------------" << endl;
                cout << "You have these items to upgrade:" << endl;
                if (narsosArmor == true) {
                    cout << "-Narso's Armor (+20 defense)-" << endl;
                }
                if (vladimirsArmor == true) {
                    cout << "-Vladimir's Armor (+20 defense)-" << endl;
                }
                if (lockhartsArmor == true) {
                    cout << "-Lockhart's Armor (+20 defense)-" << endl;
                }
                if (glassshoes == true) {
                    cout << "-Glass Shoes (+7 defense|+6 maxhealth)-" << endl;
                }
                if (mystichelmet == true) {
                    cout << "-Mystic Helmet (+9 defense|+8 maxhealth)-" << endl;
                }
                if (dragonscalechestplate == true) {
                    cout << "-Dragonscale Chestplate (+11 defense|+14 maxhealth)-" << endl;
                }
                if (flaminglongsword == true) {
                    cout << "-Flaming Longsword (+11 attack)-" << endl;
                }
                if (Excalibur == true) {
                    cout << "-Excalibur (+14 attack)-" << endl;
                }
                if (VoidshroudSlicer == true) {
                    cout << "-Voidshroud Slicer (+18 attack)-" << endl;
                }
                cout << "-----------------------------------------------" << endl;
                forgerestarting();
            }
            else if (forgeOption == "crafting") {
                forgecrafting();
                attack(Target);
                break;
            }
            else {
                cout << "That isn't an option. Try again." << endl;
                attack(Target);
                break;
            }
        }
        else if (storymode == true) {
            if ((weaponupgrade == false && armorupgrade == false && lightningshard == false && forgehammer == 0 && radiantgem == 0 && soulstone == 0)) {
                cout << "You have no upgrades to use yet. Go buy some from the store." << endl;
                cout << "-----------------------------------------------" << endl;
                attack(Target);
                break;
            }
            cout << "You have these upgrades currently:" << endl;
            if (weaponupgrade == true) {
                cout << "-Weapon Upgrade-" << endl;
            }
            if (armorupgrade == true) {
                cout << "-Armor Upgrade-" << endl;
            }
            if (lightningshard == true) {
                cout << "-Ligntning Shard-" << endl;
            }
            if (forgehammer > 0) {
                if (forgehammer == 1) {
                    cout << "-" << forgehammer << " Forgehammer-" << endl;
                }
                else {
                    cout << "-" << forgehammer << " Forgehammers-" << endl;
                }
            }
            if (dragonscalechestplate == false && mystichelmet == false && glassshoes == false && Excalibur == false && flaminglongsword == false && VoidshroudSlicer == false && narsosArmor == false && vladimirsArmor == false && lockhartsArmor == false && ciphertracker <= 3) {
                cout << "You have no armor or weapons to upgrade, go buy some from the store or get them as a lucky drop." << endl;
                cout << "-----------------------------------------------" << endl;
                attack(Target);
                break;
            }
            cout << "-----------------------------------------------" << endl;
            cout << "You have these items to upgrade:" << endl;
            if (narsosArmor == true) {
                cout << "-Narso's Armor (+20 defense)-" << endl;
            }
            if (vladimirsArmor == true) {
                cout << "-Vladimir's Armor (+20 defense)-" << endl;
            }
            if (lockhartsArmor == true) {
                cout << "-Lockhart's Armor (+20 defense)-" << endl;
            }
            if (glassshoes == true) {
                cout << "-Glass Shoes (+7 defense|+6 maxhealth)-" << endl;
            }
            if (mystichelmet == true) {
                cout << "-Mystic Helmet (+9 defense|+8 maxhealth)-" << endl;
            }
            if (dragonscalechestplate == true) {
                cout << "-Dragonscale Chestplate (+11 defense|+14 maxhealth)-" << endl;
            }
            if (flaminglongsword == true) {
                cout << "-Flaming Longsword (+11 attack)-" << endl;
            }
            if (Excalibur == true) {
                cout << "-Excalibur (+14 attack)-" << endl;
            }
            if (VoidshroudSlicer == true) {
                cout << "-Voidshroud Slicer (+18 attack)-" << endl;
            }
            cout << "-----------------------------------------------" << endl;
            forgerestarting();
        }
        attack(Target);
        break;
    case 9:
        cout << " --Your Stats--" << endl;
        cout << "--" << maxhealth << " Maxhealth--" << endl;
        cout << "--" << health << " Health--" << endl;
        cout << "--" << attackPower << " Attack--" << endl;
        cout << "--" << defense << " defense--" << endl;
        cout << "--" << baselevel << " Baselevel--" << endl;
        cout << "--" << level + baselevel << " Level--" << endl;
        cout << "--" << lives << " Lives--" << endl;
        cout << "--" << kills << " Kills--" << endl;
        cout << "--" << Goldloom << " Goldloom--" << endl;
        cout << "--" << questscompleted << " Quests Completed--" << endl;
        if (classtype == 1) {
            cout << "-Class = Knight-" << endl;
        }
        else if (classtype == 2) {
            cout << "-Class = Executioner-" << endl;
        }
        else if (classtype == 3) {
            cout << "-Class = Soulweaver-" << endl;
        }
        else if (classtype == 4) {
            cout << "-Class = Warforged Engineer-" << endl;
        }
        else if (classtype == 5) {
            cout << "-Class = Dreadnought-" << endl;
        }
        else if (classtype == 6) {
            cout << "-Class = Trickster-" << endl;
        }
        cout << "--Quest--" << endl;
        if (questpicker == 1) {
            cout << "You have killed " << questoneprogress << " enemies out of 15." << endl;
        }
        else if (questpicker == 2) {
            cout << "You have crafted " << questtwoprogress << " out of 1." << endl;
        }
        else if (questpicker == 3) {
            cout << "You have forged " << questthreeprogress << " out of 1." << endl;
        }
        else if (questpicker == 4) {
            cout << "You have used " << questfourprogress << " out of 2." << endl;
        }
        else if (questpicker == 5) {
            cout << "You have killed " << questfiveprogress << " out of 1." << endl;
        }
        cout << endl << endl;
        cout << " --" << Target->name << " Stats--" << endl;
        cout << "--" << Target->maxhealth << " Maxhealth--" << endl;
        cout << "--" << Target->health << " Health--" << endl;
        cout << "--" << Target->attackPower << " Attack--" << endl;
        cout << "--" << Target->defense << " defense--" << endl;
        cout << "--" << Target->level << " Level--" << endl;
        cout << "--" << Target->lives << " Lives--" << endl;
        attack(Target);
        break;
    case 10:
        cout << "------------------------------------------------" << endl;
        if (riddle == false && cipherkey == false && cipherblueprint == 0 && VoidshroudSlicer == false && lightningvoidshroudslicer == false && upgradedvoidshroudslicer == false && shield == false && levelupgrade == false && superiorleveltonic == false && defenseupgrade == false && narsosArmor == false && vladimirsArmor == false && lockhartsArmor == false && superpotion == false && attackupgrade == false && leveltonic == false && Sword == false && Knife == false && Excalibur == false && accuratesword == false && helmet == false && chestplate == false && boots == false && maxhealthtracker == 0 && tracklevelpotion == 0 && tracksuperiorlevelpotion == 0 && tracksuperpotion == 0 && glassshoes == false && flaminglongsword == false && dragonscalechestplate == false && mystichelmet == false && molotov == 0 && forgehammer == 0 && playercompanion == false && travelersbackpack == false && healthtonicitem == 0 && goldloomMagnet == false && horsemount == false && dragonmount == false && molotov == 0 && invisibilitypotion == 0 && wood == 0 && food == 0 && bucketowater == 0 && medicine == 0) {
            cout << "You have no items yet." << endl;
            cout << "------------------------------------------------" << endl;
            attack(Target);
            break;
        }
        if (Knife == true || Sword == true || Excalibur == true || VoidshroudSlicer == true || accuratesword == true || lightningexcalibur == true || lightningflaminglongsword == true || flaminglongsword == true || lightningvoidshroudslicer == true || upgradedexcalibur == true || upgradedflaminglongsword == true || upgradedvoidshroudslicer == true) {
            cout << "--Weapons--" << endl;
        }
        if (lightningflaminglongsword == true) {
            cout << "Lightning Framing Longsword (+20 Attack)" << endl;
        }
        if (upgradedflaminglongsword == true) {
            cout << "Upgraded Flaming Longsword (+11 Attack|+10% Max Health)" << endl;
        }
        if (upgradedexcalibur == true) {
            cout << "Upgraded Excalibur (+18 Attack|+25% Max Health)" << endl;
        }
        if (upgradedvoidshroudslicer == true) {
            cout << "Upgraded Voidshroud Slicer (+18 Attack|+40% Max Health)" << endl;
        }
        if (lightningvoidshroudslicer == true) {
            cout << "Lightning Voidshroud Slicer (+42 Attack)" << endl;
        }
        if (flaminglongsword == true) {
            cout << "Flaming Longsword (+11 attack)" << endl;
        }
        if (lightningexcalibur == true) {
            cout << "Lightning Excalibur (+35 Attack)" << endl;
        }
        if (VoidshroudSlicer == true) {
            cout << "Voidshroud Slicer (+18 Attack)" << endl;
        }
        if (accuratesword == true) {
            cout << "Accurate Sword (No more slipping!)" << endl;
        }
        if (Excalibur == true) {
            cout << "Excalibur (+14 attack)" << endl;
        }
        if (Knife == true) {
            cout << "Knife (+2 attack)" << endl;
        }
        if (Sword == true) {
            cout << "Sword (+4 attack)" << endl;
        }
        if (vladimirsArmor == true || narsosArmor == true || lockhartsArmor == true || glassshoes == true || mystichelmet == true || dragonscalechestplate == true || helmet == true || boots == true || chestplate == true || shield == true || lightningdragonscalechestplate == true || lightningglassshoes == true || lightningmystichelmet == true || upgradedDragonscalechestplate == true || upgradedgodarmor == true || upgradedglassshoes == true || upgradedmystichelmet == true || lightningGodarmor == true) {
            cout << "--Armor--" << endl;
        }
        if (vladimirsArmor == true) {
            cout << "Vladimir's Armor (+20 defense)" << endl;
        }
        if (narsosArmor == true) {
            cout << "-Narso's Armor (+20 defense)-" << endl;
        }
        if (lockhartsArmor == true) {
            cout << "-Lockhart's Armor (+20 defense)-" << endl;
        }
        if (glassshoes == true) {
            cout << "Glass Shoes (+7 defense|+6 maxhealth)" << endl;
        }
        if (mystichelmet == true) {
            cout << "Mystic Helmet (+9 defense|+8 maxhealth)" << endl;
        }
        if (dragonscalechestplate == true) {
            cout << "Dragonscale Chestplate (+11 defense|+14 maxhealth)" << endl;
        }
        if (helmet == true) {
            cout << "Helmet (+7 defense|+5 maxhealth)" << endl;
        }
        if (boots == true) {
            cout << "Boots (+5 defense|+4 maxhealth)" << endl;
        }
        if (shield == true) {
            cout << "Shield (+10 defense)" << endl;
        }
        if (chestplate == true) {
            cout << "Chestplate (+10 defense|+8 maxhealth)" << endl;
        }
        if (upgradedDragonscalechestplate == true) {
            cout << "Upgraded Dragonscale Chestplate (+18 defense|+25 Max Health)" << endl;
        }
        if (lightningdragonscalechestplate == true) {
            cout << "Lightning Dragonscale Chestplate (+11 defense|+14 Max Health|+25 Attack)" << endl;
        }
        if (lightningmystichelmet == true) {
            cout << "Lightning Mystic Helmet (+12 defense|+20 Attack)" << endl;
        }
        if (lightningGodarmor == true) {
            cout << "Lightning God Armor (+30 defense|+35 Attack)" << endl;
        }
        if (upgradedgodarmor == true) {
            cout << "Upgraded God Armor (+40 defense|+40 Max Health)" << endl;
        }
        if (upgradedmystichelmet == true) {
            cout << "Upgraded Mystic Helmet (+16 defense|+20 Max Health)" << endl;
        }
        if (upgradedglassshoes == true) {
            cout << "Upgraded Glass Shoes (+11 defense|+14 Max Health)" << endl;
        }
        if (lightningglassshoes == true) {
            cout << "Lightning Glass Shoes (+9 defense|+12 Attack)" << endl;
        }
        if (defenseupgrade == true || attackupgrade == true || levelupgrade == true || maxhealthtracker > 0 || tracklevelpotion > 0 || tracksuperiorlevelpotion > 0 || tracksuperpotion > 0 || leveltonic == true || superiorleveltonic == true || superpotion == true) {
            cout << "--Upgrades/Potions--" << endl;
        }
        if (defenseupgrade == true) {
            cout << "defense Perk (+10 defense)" << endl;
        }
        if (attackupgrade == true) {
            cout << "Attack Perk (+10 attack)" << endl;
        }
        if (levelupgrade == true) {
            cout << "Level Perk (+15 level)" << endl;
        }
        if (maxhealthtracker > 0) {
            cout << "Max Health Upgrade (+" << 50 * maxhealthtracker << " maxhealth)" << endl;
        }
        if (tracklevelpotion > 0) {
            cout << "Level Potions (+ " << 10 * tracklevelpotion << " levels)" << endl;
        }
        if (tracksuperiorlevelpotion > 0) {
            cout << "Superior Level Potions (+ " << 15 * tracksuperiorlevelpotion << " levels)" << endl;
        }
        if (tracksuperpotion > 0) {
            cout << "Super Potions (+ " << 15 * tracksuperpotion << " levels + " << 6 * tracksuperpotion << " Attack)" << endl;
        }
        if (leveltonic == true) {
            cout << "Level Tonic (+10 level)" << endl;
        }
        if (superiorleveltonic == true) {
            cout << "Superior Level Tonic (+15 level)" << endl;
        }
        if (superpotion == true) {
            cout << "Super Potion (+20 level|+10 attack)" << endl;
        }
        if (travelersbackpack == true || playercompanion == true || goldloomMagnet == true || horsemount == true || dragonmount == true || cipherblueprint > 0 || armorupgrade == true || weaponupgrade == true || lightningshard == true || forgehammer > 0) {
            cout << "--Special Items--" << endl;
        }
        if (travelersbackpack == true) {
            cout << "Travelers Backpack (Allows you to hold potions)" << endl;
        }
        if (playercompanion == true) {
            cout << "Companion (Does something random every attack and increases odds of finding treasure)" << endl;
        }
        if (goldloomMagnet == true) {
            cout << "Goldloom Magnet (More money and shop refreshes faster)" << endl;
        }
        if (horsemount == true) {
            cout << "Horse Mount (Better increase in baselevel on kill)" << endl;
        }
        if (dragonmount == true) {
            cout << "Dragon Mount (Best increase in baselevel on kill)" << endl;
        }
        if (cipherblueprint > 0) {
            cout << cipherblueprint << " Cipher Blueprint (Use a key to read...)" << endl;
        }
        if (armorupgrade == true) {
            cout << "Armor Plating (Used to upgrade armor)" << endl;
        }
        if (weaponupgrade == true) {
            cout << "Sharpening Stone (Used to upgrade weapons)" << endl;
        }
        if (lightningshard == true) {
            cout << "Lightning Shard (Used to upgrade armor/weapons)" << endl;
        }
        if (forgehammer > 0) {
            cout << forgehammer << " Forge Hammer (Used with other items to enhance artillery)" << endl;
        }
        if (wood > 0 || food > 0 || medicine > 0 || bucketowater > 0) {
            cout << "--Village--" << endl;
        }
        if (wood > 0) {
            cout << wood << " Wood (Use in village)" << endl;
        }
        if (food > 0) {
            cout << food << " Food (Use in village)" << endl;
        }
        if (medicine > 0) {
            cout << medicine << " Medicine (Use in village)" << endl;
        }
        if (bucketowater > 0) {
            cout << bucketowater << " Water Bucket (Use in village)" << endl;
        }
        if (invisibilitypotion > 0 || healthtonicitem > 0 && molotov > 0 || cipherkey == true || riddle == true) {
            cout << "--Usable--" << endl;
        }
        if (invisibilitypotion > 0) {
            cout << invisibilitypotion << " Invisibility Potion (Skip a battle)" << endl;
        }
        if (healthtonicitem > 0) {
            cout << healthtonicitem << " Health Tonic (Heal 100,75,50 or 25 based on level)" << endl;
        }
        if (molotov > 0) {
            cout << molotov << " Molotov (60% max health dmg)" << endl;
        }
        if (cipherkey == true) {
            cout << "Cipher Key (Use this to read the blueprint...)" << endl;
        }
        if (riddle == true) {
            cout << "Riddle (Unlocks a special recipe if answered correctly...)" << endl;
        }
        cout << "------------------------------------------------" << endl;
        cout << endl;
        cout << "Are there any items you would like to use? Y?N" << endl;
        cin >> ws;
        getline(cin, yesnobackpack);
        std::transform(yesnobackpack.begin(), yesnobackpack.end(), yesnobackpack.begin(), ::tolower);
        if (yesnobackpack == "yes" || yesnobackpack == "y") {
            cout << "Which item would you like to use?" << endl << endl;
            if (healthtonicitem >= 1) {
                cout << "-Health Tonic-" << endl;
            }
            if (invisibilitypotion >= 1) {
                cout << "-Invisibility Potion-" << endl;
            }
            if (molotov >= 1) {
                cout << "-Molotov-" << endl;
            }
            if (cipherkey == true && endlessmode == true) {
                cout << "-Cipher Key-" << endl;
            }
            if (riddle == true && endlessmode == true) {
                cout << "-Riddle-" << endl;
            }
            string itemuse = "";
            cin >> ws;
            getline(cin, itemuse);
            std::transform(itemuse.begin(), itemuse.end(), itemuse.begin(), ::tolower);
            if (itemuse == "health tonic" && healthtonicitem >= 1) {
                cout << "You used a Health Tonic!" << endl;
                itemusehealthtonic();
                if (usetwoitemsquest == true) {
                    questfiveprogress += 1;
                }
            }
            else if (itemuse == "invisibility potion" && invisibilitypotion >= 1) {
                cout << "You used an Invisibility Potion!" << endl;
                usinginvispotion = true;
                itemuseinvispotion(Target); //test to see if works
                if (usetwoitemsquest == true) {
                    questfiveprogress += 1;
                }
            }
            else if (itemuse == "molotov" && molotov >= 1) {
                cout << "------------------------------------------------" << endl;
                cout << "You used a Molotov!" << endl;
                itemusemolotov(Target);
                if (usetwoitemsquest == true) {
                    questfiveprogress += 1;
                }
            }
            else if (itemuse == "cipher key" && cipherkey == true && endlessmode == true) {
                cout << "------------------------------------------------" << endl;
                if (cipherblueprint >= 1) {
                    if (ciphertracker == 0) {
                        ciphertracker += 1;
                        cout << "You hear a distant roar, 18..." << endl;
                        cipherblueprint -= 1;
                        if (usetwoitemsquest == true) {
                            questfiveprogress += 1;
                        }
                    }
                    else if (ciphertracker == 1) {
                        ciphertracker += 1;
                        cout << "You hear another distant roar, 20..." << endl;
                        cipherblueprint -= 1;
                        if (usetwoitemsquest == true) {
                            questfiveprogress += 1;
                        }
                    }
                    else if (ciphertracker == 2) {
                        ciphertracker += 1;
                        cout << "You hear the last distant roar, 97..." << endl;
                        cipherblueprint -= 1;
                        if (usetwoitemsquest == true) {
                            questfiveprogress += 1;
                        }
                    }
                    else {
                        cout << "You've already heard all of the clues." << endl;
                    }
                }
                else {
                    cout << "You don't have a cipher blueprint to read." << endl;
                }
                attack(Target);
                break;
            }
            else if (itemuse == "riddle" && endlessmode == true && riddle == true) {
                string riddleanswer = "";
                cout << "In the heart of shadows, where secrets are born" << endl << "a creature of riddles, with wisdom adorned." << endl << "Its tongue is a puzzle, its voice a maze" << endl << "Speak its name, unlock the hidden ways." << endl;
                cin >> ws;
                getline(cin, riddleanswer);
                std::transform(riddleanswer.begin(), riddleanswer.end(), riddleanswer.begin(), ::tolower);
                if (riddleanswer == "troll") {
                    cout << "Thats correct. You have proven your worth and shown you deserve these ingredients. In order to make the Regenerative Mantle, you need 4 Radiant Gems, 2 Soulstone, a healing potion and 50 goldloom for the forgers hard work." << endl;
                    ciphertracker += 1;
                    if (usetwoitemsquest == true) {
                        questfiveprogress += 1;
                    }
                    attack(Target);
                    break;
                }
                else {
                    cout << "You are wrong, try again." << endl;
                    attack(Target);
                    break;
                }
            }
        }
        else if (yesnobackpack == "no" || yesnobackpack == "n") {
            cout << "Then we shall move on." << endl << endl;
        }
        else {
            cout << "Invalid Answer." << endl << endl;
        }
        attack(Target);
        break;
    case 11:
        if (questtracker == 0) {
            cout << "--Welcome to the Taskmaster's Plaza.--" << endl << "Which quest would you like?" << endl;
            questrandomizer = r() % 3 + 1;
            if (questrandomizer == 1) {
                cout << "-1-Kill 15 enemies." << endl;
            }
            else if (questrandomizer == 2) {
                cout << "-2-Craft an item.-" << endl;
            }
            else if (questrandomizer == 3) {
                cout << "-3-Forge an item.-" << endl;
            }
            questrandomizer2 = r() % 2 + 4;
            if (questrandomizer2 == 4) {
                cout << "-4-Use 2 items.-" << endl;
            }
            else if (questrandomizer2 == 5) {
                cout << "-5-Kill a Boss.-" << endl;
            }
            cin >> questpicker;
            if (questpicker == 1 && questrandomizer == 1) {
                cout << "The quest to kill 15 enemies has been started." << endl;
                killememiesquest = true;
            }
            else if (questpicker == 2 && questrandomizer == 2) {
                cout << "The quest to craft an item has been started." << endl;
                craftanitemquest = true;
            }
            else if (questpicker == 3 && questrandomizer == 3) {
                cout << "The quest to forge an item has been started." << endl;
                forgeanitemquest = true;
            }
            else if (questpicker == 4 && questrandomizer2 == 4) {
                cout << "The quest to use 2 items has been started." << endl;
                usetwoitemsquest = true;
            }
            else if (questpicker == 5 && questrandomizer2 == 5) {
                cout << "The quest to kill a boss has been started." << endl;
                killabossquest = true;
            }
            else {
                cout << "That wasn't an option. Try again." << endl;
                attack(Target);
                break;
            }
            questtracker = 1;
            attack(Target);
            break;
        }
        else if (questoneprogress >= 15) {
            int randomitem;
            cout << "Thank you for getting rid of those persky monsters!" << endl;
            questtracker = 0;
            questoneprogress = 0;
            questscompleted += 1;
            randomitem = r() % 2;
            if (randomitem == 0) {
                int randomamt;
                randomamt = r() % 3 + 1;
                soulstone += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Soulstone." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Soulstones." << endl;
                }
            }
            else if (randomitem == 1) {
                int randomamt;
                randomamt = r() % 3 + 1;
                radiantgem += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Radiant Gem." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Radiant Gems." << endl;
                }
            }
        }
        else if (questtwoprogress == 1) {
            int randomitem;
            cout << "That item looks pretty good!" << endl;
            questtracker = 0;
            questtwoprogress = 0;
            questscompleted += 1;
            randomitem = r() % 2;
            if (randomitem == 0) {
                int randomamt;
                randomamt = r() % 5 + 1;
                soulstone += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Soulstone." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Soulstones." << endl;
                }
            }
            else if (randomitem == 1) {
                int randomamt;
                randomamt = r() % 5 + 1;
                radiantgem += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Radiant Gem." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Radiant Gems." << endl;
                }
            }
        }
        else if (questthreeprogress == 1) {
            int randomitem;
            cout << "That looks much better now. Doesn't it?" << endl;
            questtracker = 0;
            questthreeprogress = 0;
            questscompleted += 1;
            randomitem = r() % 2;
            if (randomitem == 0) {
                int randomamt;
                randomamt = r() % 4 + 1;
                soulstone += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Soulstone." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Soulstones." << endl;
                }
            }
            else if (randomitem == 1) {
                int randomamt;
                randomamt = r() % 4 + 1;
                radiantgem += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Radiant Gem." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Radiant Gems." << endl;
                }
            }
        }
        else if (questfourprogress == 2) {
            int randomitem;
            cout << "You feel much stronger after those 2 items don't ya??" << endl;
            questtracker = 0;
            questfourprogress = 0;
            questscompleted += 1;
            randomitem = r() % 2;
            if (randomitem == 0) {
                int randomamt;
                randomamt = r() % 3 + 1;
                soulstone += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Soulstone." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Soulstones." << endl;
                }
            }
            else if (randomitem == 1) {
                int randomamt;
                randomamt = r() % 3 + 1;
                radiantgem += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Radiant Gem." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Radiant Gems." << endl;
                }
            }
        }
        else if (questfiveprogress == 1) {
            int randomitem;
            cout << "That boss didn't know what hit em!" << endl;
            questtracker = 0;
            questfiveprogress = 0;
            questscompleted += 1;
            randomitem = r() % 2;
            if (randomitem == 0) {
                int randomamt;
                randomamt = r() % 4 + 1;
                soulstone += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Soulstone." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Soulstones." << endl;
                }
            }
            else if (randomitem == 1) {
                int randomamt;
                randomamt = r() % 4 + 1;
                radiantgem += randomamt;
                if (randomamt == 1) {
                    cout << "I'm going to give you " << randomamt << " Radiant Gem." << endl;
                }
                else {
                    cout << "I'm going to give you " << randomamt << " Radiant Gems." << endl;
                }
            }
        }
        else {
            cout << "Come back when you're done with your quest to turn it in." << endl;
            attack(Target);
            break;
        }
    case 12:
        village(&enemy);
        attack(Target);
        break;
    case 13:
        if (DLC1tracker >= 10) {
            DLC1tracker -= 10;
            int amountneeded = r() % 50 + 1;
            int amount = 0;
            cout << "Input up to 8 letters and see if you can get " << amountneeded << " points!" << endl;
            cin >> ws;
            getline(cin, game);
            int points = calculatePoints(game);
            if (points >= amountneeded) {
                cout << "You did it!" << endl;
                amount = r() % 201 + 50;
                Goldloom += amount;
                cout << "You got " << amount << " Goldloom, ";
                amount = r() % 3 + 1;
                if (amount == 1) {
                    cout << amount << " Forgehammer and ";
                }
                else {
                    cout << amount << " Forgehammers and ";
                }
                amount = r() % 10 + 2;
                int random = r() % 7 + 1;
                if (random == 1) {
                    attackPower += amount;
                    cout << amount << " attack!" << endl;
                }
                else if (random == 2) {
                    health += amount;
                    cout << amount << " health!" << endl;
                }
                else if (random == 3) {
                    maxhealth += amount;
                    cout << amount << " maxhealth!" << endl;
                }
                else if (random == 4) {
                    defense += amount;
                    cout << amount << " defense!" << endl;
                }
                else if (random == 5) {
                    level += amount;
                    cout << amount << " levels!" << endl;
                }
                else if (random == 6) {
                    baselevel += amount;
                    cout << amount << " baselevels!" << endl;
                }
                else {
                    lives += 1;
                    cout << "one life!" << endl;
                }
                attack(Target);
                break;
            }
            else {
                cout << "You didn't meet the " << amountneeded << " point requirement. Try again next time." << endl;
                attack(Target);
                break;
            }
        }
        else {
            cout << "This is not ready for you yet. Come back later" << endl;
            attack(Target);
            break;
        }
    case 182097:
        if (ciphertracker == 3) {
            cout << "You've unlocked a secret blueprint to the Regenerative Mantle. Find some more clues to find the ingredients..." << endl;
        }
        else {
            cout << "Nice try bud, I knew you would try that." << endl;
        }
        break;
    default:
        cout << "-------------------------" << endl;
        cout << "Invalid Move, try again!" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
        attack(Target);
        break;
    }
}