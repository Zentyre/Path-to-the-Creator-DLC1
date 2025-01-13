#pragma once
#include "Character.h"
#include "Enemy.h"
class Player : public Character {
public:
	Player(string n, int maxh, int hp, int atk, int def, int baselvl, int live);
	void attack(Character* Target) override;
	void takeDmg(int dmg) override {
		if (defense > dmg) {
			cout << "Your defense absorbed all " << dmg << " enemy damage!" << endl;
		}
		else if (defense > 0 && defense < dmg) {
			cout << "Your defense absorbed " << getdefense() << " damage!" << endl;
		}
		dmg -= defense;
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
	int incrementvillage(int amount) const {
		return villagetracker + amount;
	}
	int generateRandom(int min, int max) {
		return rand() % (max - min + 1) + min;
	}
	bool playLockpickingMinigame(int pins, int minRange, int maxRange, int attempts) {
		// Generate random lock combination
		vector<int> lockCombination;
		for (int i = 0; i < pins; ++i) {
			lockCombination.push_back(generateRandom(minRange, maxRange));
		}

		cout << "You encounter a locked chest. To open it, you must pick the lock." << endl;
		cout << "The lock has " << pins << " pins. Each pin requires a number between " << minRange << " and " << maxRange << "." << endl;

		for (int attempt = 1; attempt <= attempts; ++attempt) {
			cout << "Attempt " << attempt << "/" << attempts << ": Enter your guesses, separated by spaces: ";

			// Get player's guess
			vector<int> playerGuess(pins);
			for (int i = 0; i < pins; ++i) {
				cin >> playerGuess[i];
			}

			// Check player's guess
			bool correctGuess = true;
			for (int i = 0; i < pins; ++i) {
				if (playerGuess[i] != lockCombination[i]) {
					correctGuess = false;
					break;
				}
			}

			if (correctGuess) {
				int itemgive = 0;
				cout << "Congratulations! You successfully picked the lock." << endl;
				itemgive = r() % 5 + 1;
				wood += itemgive;
				cout << "-You got " << itemgive << " wood.-" << endl;
				itemgive = r() % 451 + 50;
				Goldloom += itemgive;
				cout << "-You got " << itemgive << " goldloom.-" << endl;
				itemgive = r() % 5 + 1;
				soulstone += itemgive;
				cout << "You got " << itemgive << " soulstone." << endl;
				itemgive = r() % 9 + 2;
				radiantgem += itemgive;
				cout << "You got " << itemgive << " radiant gems" << endl;
				break;
			}
			else if (attempts > 0) {
				cout << "Incorrect combination. Try again." << endl;
			}
			else {
				cout << "You failed to pick the lock." << endl;
			}
		}
	}
	int pins = 0;         // Number of pins in the lock
	int minRange = 0;     // Minimum value for each pin
	int maxRange = 0;     // Maximum value for each pin
	int attempts = 0;	  // Number of attempts
	void playGemstoneMining() {
		int attempts = 0;
		if (playercompanion == true) {
			attempts = 5;
		}
		else {
			attempts = 3;
		}
		int totalScore = 0;
		cout << "Welcome to the Gemstone Mining Minigame!" << endl;
		cout << "You have " << attempts << " attempts to mine for gemstones." << endl;

		for (int i = 0; i < attempts; ++i) {
			cout << "\nAttempt " << i + 1 << endl;
			cout << "Choose your mining tool:" << endl;
			cout << "1. Pickaxe" << endl;
			cout << "2. Chisel" << endl;
			cout << "3. Hammer" << endl;

			int choice;
			cin >> choice;
			int roll = r() % 5 + 1;

			switch (choice) {
			case 1:
				if (roll >= 4) {
					cout << "You found a ruby! Worth 50 goldloom." << endl;
					totalScore += 50;
				}
				else {
					cout << "You found nothing valuable." << endl;
				}
				break;
			case 2:
				if (roll >= 3) {
					cout << "You found an emerald! Worth 40 goldloom." << endl;
					totalScore += 40;
				}
				else {
					cout << "You found nothing valuable." << endl;
				}
				break;
			case 3:
				if (roll >= 2) {
					cout << "You found a sapphire! Worth 30 goldloom." << endl;
					totalScore += 30;
				}
				else {
					cout << "You found nothing valuable." << endl;
				}
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
			}
		}

		cout << "\nYou made it out with: " << totalScore << " goldloom." << endl << endl;
		Goldloom += totalScore;
	}
	int calculatePoints(const std::string& input) {
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
	int DLC1tracker = 0;
	int randommessage = 0;
	int villagetracker = 0;
	int trackvisits = 0;
	int villagerandomevent = 0;
	void village(Enemy* Target);
	void mysteriousquest();
	void setmaxhealth();
	void checkitems();
	void forgerestarting();
	void forgecrafting();
	void playerclassexecutioner();
	void playerclasssoulweaver();
	void playerclasswarforged();
	void playerclassdreadnought();
	void playerclasstrickster();
	void itemusehealthtonic();
	int stopremessaging = 0;
	int healthtonicitem = 0;
	int failedforge = 0;
	int cipherblueprint = 0;
	int ciphertracker = 0;
	int soulstone = 0;
	int radiantgem = 0;
	int questtracker = 0;
	int questpicker = 0;
	int questrandomizer = 0;
	int questrandomizer2 = 0;
	int food = 0;
	int wood = 0;
	int shop1 = 0;
	int shop2 = 0;
	int shop3 = 0;
	int storesave = 0;
	int bucketowater = 0;
	int medicine = 0;
	bool visitedbefore = false;
	bool riddle = false;
	bool cipherkey = false;
	bool horsemount = false;
	bool dragonmount = false;
	bool goldloomMagnet = false;
	bool regenerativemantle = false;
	bool fallen = false;
	bool Knife = false;
	bool Sword = false;
	bool Excalibur = false;
	bool upgradedexcalibur = false;
	bool lightningexcalibur = false;
	bool leveltonic = false;
	bool superiorleveltonic = false;
	bool superpotion = false;
	bool chestplate = false;
	bool helmet = false;
	bool boots = false;
	bool narsosArmor = false;
	bool lockhartsArmor = false;
	bool vladimirsArmor = false;
	bool upgradedgodarmor = false;
	bool lightningGodarmor = false;
	bool accuratesword = false;
	bool shield = false;
	bool fasttravel = false;
	bool trickstermove = false;
	bool soulweavermove = false;
	bool warforgedmove = false;
	bool knightmove = false;
	bool dreadnoughtmove = false;
	bool executionermove = false;
	bool maxhealthupgrade = false;
	bool defenseupgrade = false;
	bool levelupgrade = false;
	bool attackupgrade = false;
	bool armorupgrade = false;
	bool weaponupgrade = false;
	bool flaminglongsword = false;
	bool VoidshroudSlicer = false;
	bool upgradedvoidshroudslicer = false;
	bool lightningvoidshroudslicer = false;
	bool upgradedflaminglongsword = false;
	bool lightningflaminglongsword = false;
	bool healingpotionitem = false;
	bool lightningshard = false;
	bool glassshoes = false;
	bool upgradedglassshoes = false;
	bool lightningglassshoes = false;
	bool mystichelmet = false;
	bool upgradedmystichelmet = false;
	bool lightningmystichelmet = false;
	bool dragonscalechestplate = false;
	bool upgradedDragonscalechestplate = false;
	bool lightningdragonscalechestplate = false;
	bool travelersbackpack = false;
	bool playercompanion = false;
	bool killememiesquest = false;
	int questoneprogress = 0;
	bool craftanitemquest = false;
	int questtwoprogress = 0;
	bool forgeanitemquest = false;
	int questthreeprogress = 0;
	bool usetwoitemsquest = false;
	int questfourprogress = 0;
	bool killabossquest = false;
	bool isplayingvillage = false;
	int questfiveprogress = 0;
	int questscompleted = 0;
	int trackexcaliburmaxhealth = 0;
	int trackflamingmaxhealth = 0;
	int trackvoidshroudmaxhealth = 0;
	int forgehammer = 0;
	int excaliburtracker = 0;
	int knifetracker = 0;
	int swordtracker = 0;
	int helmtracker = 0;
	int chesttracker = 0;
	int boottracker = 0;
	int shieldtracker = 0;
	int godtracker = 0;
	int defenseupgradetracker = 0;
	int flamingtracker = 0;
	int dragontracker = 0;
	int shoetracker = 0;
	int mystictracker = 0;
	int lightningdragontracker = 0;
	int upgradeddragontracker = 0;
	int lightningexcaliburtracker = 0;
	int upgradedexcaltracker = 0;
	int lightninglongswordtracker = 0;
	int upgradedlongswordtracker = 0;
	int lightninggodtracker = 0;
	int upgradedgodtracker = 0;
	int upgradedmystictracker = 0;
	int lightningmystictracker = 0;
	int upgradedglasstracker = 0;
	int lightningglasstracker = 0;
	int voidshroudtracker = 0;
	int upgradedvoidshroudtracker = 0;
	int lightningvoidshroudtracker = 0;
	int tracklevelpotion = 0;
	int tracksuperpotion = 0;
	int tracksuperiorlevelpotion = 0;
	int lostartifact = 0;
	bool cursedheart = false;
	bool enchantedsachel = false;
	bool glowingglasses = false;
	bool fierynecklace = false;
	bool shinybelt = false;
	bool mysteriousstranger = false;
	bool mysteriousstrangerquestactive = false;
	bool mysteriousstrangerquest = false;
	bool mysteriousstrangerquest2 = false;
	bool mysteriousstrangerquest3 = false;
	bool mysteriousstrangerquest4 = false;
	bool mysteriousstrangerquest5 = false;
	int mysteriousstrangerquesttracker = 0;
	int mysteriousstrangerquesttracker2 = 0;
	int mysteriousstrangerquesttracker3 = 0;
	int mysteriousstrangerquesttracker4 = 0;
	int mysteriousstrangerquesttracker5 = 0;
	// reset knight function
	void resetKnight() {
		maxhealth = 50;
		health = 25;
		attackPower = 4;
		defense = 0;
		level = 0;
		baselevel = 0;
		lives = 1;
		int randommessage = 0;
		int villagetracker = 0;
		int trackvisits = 0;
		int villagerandomevent = 0;
		int stopremessaging = 0;
		int healthtonicitem = 0;
		int failedforge = 0;
		int cipherblueprint = 0;
		int ciphertracker = 0;
		int soulstone = 0;
		int radiantgem = 0;
		int questtracker = 0;
		int questpicker = 0;
		int questrandomizer = 0;
		int questrandomizer2 = 0;
		int food = 0;
		int wood = 0;
		int shop1 = 0;
		int shop2 = 0;
		int shop3 = 0;
		int storesave = 0;
		int bucketowater = 0;
		int medicine = 0;
		bool visitedbefore = false;
		bool riddle = false;
		bool cipherkey = false;
		bool horsemount = false;
		bool dragonmount = false;
		bool goldloomMagnet = false;
		bool regenerativemantle = false;
		bool fallen = false;
		bool Knife = false;
		bool Sword = false;
		bool Excalibur = false;
		bool upgradedexcalibur = false;
		bool lightningexcalibur = false;
		bool leveltonic = false;
		bool superiorleveltonic = false;
		bool superpotion = false;
		bool chestplate = false;
		bool helmet = false;
		bool boots = false;
		bool narsosArmor = false;
		bool lockhartsArmor = false;
		bool vladimirsArmor = false;
		bool upgradedgodarmor = false;
		bool lightningGodarmor = false;
		bool accuratesword = false;
		bool shield = false;
		bool fasttravel = false;
		bool trickstermove = false;
		bool soulweavermove = false;
		bool warforgedmove = false;
		bool knightmove = false;
		bool dreadnoughtmove = false;
		bool executionermove = false;
		bool maxhealthupgrade = false;
		bool defenseupgrade = false;
		bool levelupgrade = false;
		bool attackupgrade = false;
		bool armorupgrade = false;
		bool weaponupgrade = false;
		bool flaminglongsword = false;
		bool VoidshroudSlicer = false;
		bool upgradedvoidshroudslicer = false;
		bool lightningvoidshroudslicer = false;
		bool upgradedflaminglongsword = false;
		bool lightningflaminglongsword = false;
		bool healingpotionitem = false;
		bool lightningshard = false;
		bool glassshoes = false;
		bool upgradedglassshoes = false;
		bool lightningglassshoes = false;
		bool mystichelmet = false;
		bool upgradedmystichelmet = false;
		bool lightningmystichelmet = false;
		bool dragonscalechestplate = false;
		bool upgradedDragonscalechestplate = false;
		bool lightningdragonscalechestplate = false;
		bool travelersbackpack = false;
		bool playercompanion = false;
		bool killememiesquest = false;
		int questoneprogress = 0;
		bool craftanitemquest = false;
		int questtwoprogress = 0;
		bool forgeanitemquest = false;
		int questthreeprogress = 0;
		bool usetwoitemsquest = false;
		int questfourprogress = 0;
		bool killabossquest = false;
		bool isplayingvillage = false;
		int questfiveprogress = 0;
		int questscompleted = 0;
		int trackexcaliburmaxhealth = 0;
		int trackflamingmaxhealth = 0;
		int trackvoidshroudmaxhealth = 0;
		int forgehammer = 0;
		int excaliburtracker = 0;
		int knifetracker = 0;
		int swordtracker = 0;
		int helmtracker = 0;
		int chesttracker = 0;
		int boottracker = 0;
		int shieldtracker = 0;
		int godtracker = 0;
		int defenseupgradetracker = 0;
		int flamingtracker = 0;
		int dragontracker = 0;
		int shoetracker = 0;
		int mystictracker = 0;
		int lightningdragontracker = 0;
		int upgradeddragontracker = 0;
		int lightningexcaliburtracker = 0;
		int upgradedexcaltracker = 0;
		int lightninglongswordtracker = 0;
		int upgradedlongswordtracker = 0;
		int lightninggodtracker = 0;
		int upgradedgodtracker = 0;
		int upgradedmystictracker = 0;
		int lightningmystictracker = 0;
		int upgradedglasstracker = 0;
		int lightningglasstracker = 0;
		int voidshroudtracker = 0;
		int upgradedvoidshroudtracker = 0;
		int lightningvoidshroudtracker = 0;
		int tracklevelpotion = 0;
		int tracksuperpotion = 0;
		int tracksuperiorlevelpotion = 0;
		int lostartifact = 0;
		bool cursedheart = false;
		bool enchantedsachel = false;
		bool glowingglasses = false;
		bool fierynecklace = false;
		bool shinybelt = false;
		bool mysteriousstranger = false;
		bool mysteriousstrangerquestactive = false;
		bool mysteriousstrangerquest = false;
		bool mysteriousstrangerquest2 = false;
		bool mysteriousstrangerquest3 = false;
		bool mysteriousstrangerquest4 = false;
		bool mysteriousstrangerquest5 = false;
		int mysteriousstrangerquesttracker = 0;
		int mysteriousstrangerquesttracker2 = 0;
		int mysteriousstrangerquesttracker3 = 0;
		int mysteriousstrangerquesttracker4 = 0;
		int mysteriousstrangerquesttracker5 = 0;
	}
};
