/*
 *      main.cpp
 *
 *      Copyright 2013 	Alexandros Iliopoulos
 *						Marc Sylvestre <marc.sylvestre@manhydra.com>
 */

#include "main.hpp"

/*
void statSheet();
void mainScreen();
void enemyOne();
void upgradeweap();
void potionshop();
void update();

int inputmain = 0;
int input1 = 0;
int hp = 150;
int maxhp = 150;
int atk = 5;
int def = 15;
int exp = 0;
int atkboost;
int enemy1hp = 200;
int enemy1maxhp = 200;
int enemy1exp = 20;
int enemy1atk = 2;
int enemy1atkboost;
int expreq = 20;
int playerlevel = 1;
int coins = 10;
int wincoins;
int weaponlevel = 1;
int weaponlevelreq = 10;
int potioncost = 5;
string potion;
string weaponupgrade;
string playername;
string weapon = "Anchemacha";
string armor = "Greek Bronze Shield";
string enemy1 = "Trojan";
*/

/*
void update(Character &player, Character &enemy)
{
    FILE* file = popen("git pull", "r");
	// use fscanf to read:
	char buffer[100];
	fscanf(file, "%s", buffer);
	pclose(file);
	mainScreen(player, enemy);
}
*/

void statSheet(Character &player, Character &enemy)
{
    cout << "\033[22;34mName: " << "\033[01;37m" << player.Name() << "\033[00m" << endl;
    cout << "\033[22;34mLevel: " << "\033[01;37m" << player.characterLevel() << "\033[00m" << endl;
    cout << "\033[22;34mHealth: " << "\033[01;37m" << player.hitPoints() << " / " << player.maxHitPoints() << "\033[00m" << endl;
    cout << "\033[22;34mWeapon: " << "\033[01;37m" << player.WeaponName() << " Level " << player.WeaponLevel() << " <" << player.attackPoints() << " - " << player.attackPoints() + 8 << " damage>" << "\033[00m" << endl;
    cout << "\033[22;34mArmor: " << "\033[01;37m" << player.ArmorName() << " <" << player.defensePoints() << " - " << player.defensePoints() + 5 << " defence>" << "\033[00m" << endl;
    cout << "\033[22;34mExperience: " << "\033[01;37m" << player.experiencePoints() << " / " << player.expRequirements() << "\033[00m" << endl;
    cout << "\033[22;34mCoins: " << "\033[01;37m" << player.Coins() << "\033[00m" << endl << endl;

    mainScreen(player, enemy);
}

void upgradeweap(Character &player, Character &enemy)
{
	char input;

    cout << "\033[01;33mAre you sure you want to spent " << player.WeaponCost() << " coins for weapon upgrade? [y/n]\033[00m" << endl;
    cout << "\033[01;33m>";
    cin >> input;
    if (input == 'y')
    {
		if (player.Coins() < player.WeaponCost())
			cout << "\033[01;31mYou have no coins available for this upgrade!\033[00m" << endl << endl;
		else
		{
	        player.decreaseCoins(10);
	        player.increaseAttackPoints(5);
	        player.increaseWeaponLevel();
	        player.increaseWeaponCost(10);
	        cout << "\033[01;32mCongratulations! Your weapon is now level " << player.WeaponLevel() << "\033[00m" << endl << endl;
		}
    }
    mainScreen(player, enemy);
}
void potionshop(Character &player, Character &enemy)
{
	char input;
    cout << "\033[01;33mAre you sure you want to buy HP Potions for 5 coins? [y/n]\033[00m" << endl;
    cout << "\033[01;33m> ";
    cin >> input;
    if (input == 'y')
    {
		if (player.Coins() < player.PotionCost())
			cout << "\033[01;31mYou have no coins available for this upgrade!" << endl << endl;
		else
		{
	        player.decreaseCoins(5);
	        player.increaseHitPoints(25);
	        cout << "\033[01;32mCongratulations! Your HP now is " << player.hitPoints() << "." << endl << endl;
		}
    }
    mainScreen(player, enemy);
}

void mainScreen(Character &player, Character &enemy)
{
	int input;
	if (player.expReached())
    {
	    cout << "\033[01;32mCongratulations! You have gained a level!" << endl << endl;
	    player.increaseCharacterLevel();
	    player.experiencePoints(0);
	    player.increaseExpRequirements(20);
	    player.hitPoints(150);
	    enemy.increaseAttackPoints(5);
    }

    cout << "\033[01;35m[1] Battle" << endl;
    cout << "\033[01;35m[2] Character" << endl;
    cout << "\033[01;35m[3] Upgrade Weapon" << endl;
    cout << "\033[01;35m[4] Buy HP Potion" << endl;
    cout << "\033[01;35m[5] Update" << endl;
    cout << "\033[01;35m[6] Quit" << endl;
    cout << "\033[01;35m>";
    cin >> input;
	switch(input){
		case 1:
			Battle(player, enemy);
			break;
		case 2:
			statSheet(player, enemy);
			break;
		case 3:
			upgradeweap(player, enemy);
			break;
		case 4:
			potionshop(player, enemy);
			break;
		case 5:
			//update(player, enemy);
			break;
		case 6:
			cout << "\033[01;36mThanks for playing!" << endl;
			return;
		default:
			cout << "\033[01;31mInvalid input, please retry." << endl << endl;
			mainScreen(player, enemy);
			break;
	}
}

void Battle(Character &player, Character &enemy)
{
	int input;
    cout << "\033[01;32m" << enemy.Name() << " \033[01;32m<" << enemy.hitPoints() << " / " << enemy.maxHitPoints() << ">" << " is ready for battle!" << endl;
    cout << "---" << endl;
    while (enemy.hitPoints() > 0)
    {
	    cout << "\033[01;35m[1] Attack" << endl;
	    cout << "\033[01;35m[2] Run" << endl;
	    cout << "\033[01;35m> ";
	    cin >> input;
        if (input == 1)
        {
			player.adjustAttackBoost();
            if (player.attackBoost() >= 7)
            {
                player.increaseAttackBoost(8);
                cout << "\033[01;32m> Critical Hit!!" << endl;
                cout << "\033[01;32m> You hit " << enemy.Name() << " for " << player.attackPoints() + player.attackBoost() << " damage." << endl << endl;
            }
            else
				cout << "\033[01;32m> You hit " << enemy.Name() << " for " << player.attackPoints() + player.attackBoost() << " damage." << endl << endl;

	        enemy.decreaseHitPoints(player.attackPoints() + player.attackBoost());
	        cout << enemy.Name() << "\033[01;32]m: " << enemy.hitPoints() << " / " << enemy.maxHitPoints() << endl << endl;

	        enemy.adjustAttackBoost();
	        cout << "\033[01;32m> " << enemy.Name() << " hit you for " << enemy.attackPoints() + enemy.attackBoost() << " damage." << endl << endl;
	        player.decreaseHitPoints(enemy.attackPoints() + enemy.attackBoost());
	        cout << player.Name() << "\033[01;32m: " << player.hitPoints() << " / " << player.maxHitPoints() << endl << endl;
			if (player.hitPoints() <= 0)
            {
                cout << "\033[01;31mYou are dead!" << endl << endl;
                return;
            }
        }
        else if (input == 2)
        {
	        cout << "\033[01;31m>You have ran away from the " << enemy.Name() << "." << endl << endl;
	        mainScreen(player, enemy);
        }
        else
        {
			cout << "\033[01;31mInvalid input, please retry." << endl << endl;
        }

    }
    cout << "\033[01;32mYou have slain the " << enemy.Name() << "!" << endl << endl;
	player.increaseExperiencePoints(enemy.experiencePoints());
	player.increaseCoins((rand() % 28) + 1);
	enemy.hitPoints(200);
	mainScreen(player, enemy);
}

int main()
{
	cout << "\033[01;35m=====================================" << endl;
	cout << "\033[01;35mWelcome to Reapers Battleship v1.5.2" << endl;
	cout << "\033[01;35m=====================================" << endl;
	cout << "\033[01;36mWhat's your player name: ";

	string playername;
	getline(cin, playername);

	Character Player(playername, 150, 150, 5, 15, 0, 20, 1, 10);
	Character Enemy("Trojan", 200, 200, 2, 10, 20, 20, 1, 10);

	mainScreen(Player, Enemy);

	return 0;
}
