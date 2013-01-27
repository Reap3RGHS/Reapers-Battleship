/*
 *      game.cpp
 *
 *      Copyright 2013 Alexandros Iliopoulos <reaperghs@gmail.com>
 *					   Marc Sylvestre <marc.sylvestre@manhydra.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, see <http://www.gnu.org/licenses/>,
 *      or if prefer good old fashion postal mail, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#include "game.hpp"

Character Game::Player;
vector<Character> Game::Enemies;
vector<BattleGear> Game::Weapons;
vector<BattleGear> Game::Armor;
vector<Potion> Game::Potions;
vector<Item> Game::MiscItems;
Shop Game::rbShop;

void Game::init(string newPlayerName) {
	// Generating Environment Items
	loadGameWeapons();
	loadGameArmor();
	loadGamePotions();
	loadGameMiscItems();
	loadGameShop();
	loadGameEnemies();

	// Generating Main Player
	Player.Name(newPlayerName);
	Player.Type("Human");
	Player.Strength(1);
	Player.Agility(1);
	Player.maxHitPoints(150);
	Player.hitPoints(150);
	Player.addWeaponToStock(Weapons[0], true);
	Player.addArmorToStock(Armor[0], true);
}

void Game::loadGameWeapons() {
	Weapons.push_back(BattleGear("Anchemacha", "Spear", 1, 25, 4));
	Weapons.push_back(BattleGear("Spartan Dagger", "Dagger", 1, 30, 5));
	Weapons.push_back(BattleGear("Cutter", "Dagger", 1, 40, 6));
}

void Game::loadGameArmor() {
	Armor.push_back(BattleGear("Greek Bronze Shield", "Shield", 1, 25, 5));
}

void Game::loadGamePotions() {
	Potions.push_back(Potion("Healing", "Heal", 1, 5, 5));
}

void Game::loadGameMiscItems() {
}

void Game::loadGameShop() {
	for (int i = 0; i < Weapons.size(); i++)
		rbShop.addWeapon(Weapons[i]);
	for (int i = 0; i < Potions.size(); i++)
		rbShop.addPotion(Potions[i]);
}

void Game::loadGameEnemies() {
	Enemies.push_back(Character());
	Enemies[0].Name("Trojan");
	Enemies[0].Type("Human");
	Enemies[0].Strength(1);
	Enemies[0].Agility(1);
	Enemies[0].maxHitPoints(200);
	Enemies[0].hitPoints(200);
	Enemies[0].addWeaponToStock(Weapons[1], true);
}

void Game::mainGame() {
	int select;
	while (true) {
		if (Player.expReached()) {
		    cout << "\033[01;32mCongratulations! You have gained a level!" << endl << endl;
		    Player.increaseCharacterLevel();
		    Player.experiencePoints(0);
		    Player.increaseExpRequirements(20);
		    Player.hitPoints(150);
		    Enemies[0].increaseStrength(2);
		}

	    cout << "\033[01;35m[1] Battle" << endl;
	    cout << "\033[01;35m[2] Character" << endl;
	    cout << "\033[01;35m[3] Upgrade Weapon" << endl;
	    cout << "\033[01;35m[4] Buy Weapons and Potions" << endl;
	    cout << "\033[01;35m[5] Quit" << endl;
	    cout << "\033[01;35m>";
	    cin >> select;
		switch(select){
			case 1:
				enterBattle();
				break;
			case 2:
				Player.Stats();
				break;
			case 3:
				upgradeweap();
				break;
			case 4:
				rbShop.Shopping(Player);
				break;
			case 5:
				cout << "\033[01;36mThanks for playing!\033[00;00m" << endl;
				return;
			default:
				cout << "\033[01;31mInvalid selection, please retry." << endl << endl;
				break;
		}
	}
}

void Game::enterBattle() {
	int select, atkboost, enemy1atkboost;
    if (Player.characterLevel() == 9) {
	    cout << "\033[01;32mCongratulations! You have FINISHED the game!!!!" << endl << endl;
	    return;
	}
    cout << "\033[01;32m" << Enemies[0].Name() << " \033[01;32m<" << Enemies[0].hitPoints() << " / " << Enemies[0].maxHitPoints() << ">" << " is ready for battle!" << endl;
    cout << "---" << endl;
    while (Enemies[0].hitPoints() > 0) {
	    cout << "\033[01;35m[1] Attack" << endl;
	    cout << "\033[01;35m[2] Run" << endl;
	    cout << "\033[01;35m>";
	    cin >> select;
	    switch (select) {
			case 1:
				atkboost = (rand () % 8) - Enemies[0].defensePoints();
	            if (atkboost >= 7) {
	                atkboost += 8;
	                cout << "\033[01;32m>Critical Hit! You hit " << Enemies[0].Name() << " for " << Player.attackPoints() + atkboost << " damage." << endl << endl;

	            } else cout << "\033[01;32m> You hit " << Enemies[0].Name() << " for " << Player.attackPoints() + atkboost << " damage." << endl << endl;

		        Enemies[0].decreaseHitPoints(Player.attackPoints() + atkboost);
		        cout << Enemies[0].Name() << "\033[01;32m: " << Enemies[0].hitPoints() << " / " << Enemies[0].maxHitPoints() << endl << endl;

		        enemy1atkboost = (rand () % 5) - Player.defensePoints();
		        cout << "\033[01;32m> " << Enemies[0].Name() << " hit you for " << Enemies[0].attackPoints() + enemy1atkboost << " damage." << endl << endl;

		        Player.decreaseHitPoints(Enemies[0].attackPoints() + enemy1atkboost);
		        cout << Player.Name() << "\033[01;32m: " << Player.hitPoints() << " / " << Player.maxHitPoints() << endl << endl;
		        if (Player.hitPoints() <= 0) {
	                cout << "\033[01;31mYou are dead!" << endl << endl;
	                return;
	            }
			break;
			case 2:
				cout << "\033[01;31m>You have ran away from the " << Enemies[0].Name() << "." << endl << endl;
		        return;
			break;
			default:
				cout << "\033[01;31mInvalid input, please retry." << endl << endl;
		}
    }
    cout << "\033[01;32mYou have slain the " << Enemies[0].Name() << "!" << endl << endl;
	Player.increaseExperiencePoints(Enemies[0].experiencePoints());
	Player.increaseCoins(rand () % 28);
	Enemies[0].hitPoints(200);
}

void Game::upgradeweap()
{
/*
    if (weaponlevel == 9)
    {
        cout << "\033[01;32mYou have reached level " << weaponlevel << ", your weapon is now master." << endl << endl;
        mainScreen();
    }


    cout << "\033[01;33mAre you sure you want to spent " << weaponlevelreq << " coins for weapon upgrade? [yes/no] " << endl;
    cout << "\033[01;33m>";
    cin >> weaponupgrade;
    if (coins < weaponlevelreq){
            cout << "\033[01;31mYou have no coins available for this upgrade!" << endl << endl;

    }
    else if (weaponupgrade == "yes"){
        coins -= 10;
        atk += 5;
        weaponlevel ++;
        weaponlevelreq += 10;
        cout << "\033[01;32mCongratulations! Your weapon is now level " << weaponlevel << endl << endl;

    }
    mainScreen();
*/
}
