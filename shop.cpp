/*
 *      shop.cpp
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

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "item.hpp"
#include "gear.hpp"
#include "potion.hpp"
#include "inventory.hpp"
#include "character.hpp"
#include "shop.hpp"

void Shop::buyWeapon(Character &Player, int index) {
	BattleGear w = Player.getWeapon(index);
	Player.removeWeaponFromStock(index);
	Player.increaseCoins(int(w.Cost() * sellingrate));
	merchandise.addWeapon(w);
}

void Shop::sellWeapon(Character &Player, int index) {
	BattleGear w = merchandise.getWeapon(index);
	Player.addWeaponToStock(w, false);
	Player.decreaseCoins(w.Cost());
	merchandise.removeWeapon(index);
}

void Shop::sellArmor(Character &Player, int index) {
	BattleGear w = merchandise.getArmor(index);
	Player.addArmorToStock(w, false);
	Player.decreaseCoins(w.Cost());
	merchandise.removeArmor(index);
}

void Shop::sellPotion(Character &Player, int index) {
	Potion p = merchandise.getPotion(index);
	Player.addPotionToStock(p, false);
	Player.decreaseCoins(p.Cost());
	merchandise.removePotion(index);
}

void Shop::sellMiscItem(Character &Player, int index) {
	Item i = merchandise.getPotion(index);
	Player.addMiscItemToStock(i, false);
	Player.decreaseCoins(i.Cost());
	merchandise.removeMiscItem(index);
}

void Shop::Shopping(Character &Player) {
	size_t itemselect, weaponselect, potionselect;
	int transtype;
	bool madeTrans = false;
	vector<BattleGear> weaponsList;
	vector<Potion> potionsList;
	cout << "Welcome to RB Shop!" << endl;
	while (true) {
	    cout << "You have " << Player.Coins() << " remaining." << endl;
	    cout << "Select Item Type: " << endl;
	    cout << "[1] Weapon" << endl;
	    cout << "[2] Potion" << endl;
	    cout << "[3] Leave Shop" << endl;
	    cout << "> ";
	    cin >> itemselect;

	    switch(itemselect) {
			case 1:
				cout << "Buying or Selling a Weapon? " << endl;
			    cout << "[1] Buying" << endl;
			    cout << "[2] Selling" << endl;
			    cout << "[3] Neither" << endl;
			    cout << "> ";
			    cin >> transtype;
				switch (transtype) {
					case 1:
						weaponsList = merchandise.getWeaponsList();
						if (!weaponsList.size()) {
							cout << "Sorry. We're completely out of weapons :(" << endl;
							break;
						}
						cout << "Select the weapon you want to purchase:" << endl;
						for (size_t i = 0; i < weaponsList.size(); i++)
							cout << "[" << i+1 << "] " << weaponsList[i].Name() << " < " << weaponsList[i].Cost() << " coins >" << endl;
						cout << "[" << weaponsList.size()+1 << "] Nothing" << endl;
					    cout << "> ";
						cin >> weaponselect;
						if (weaponselect >= weaponsList.size()+1) {
							if (weaponselect > weaponsList.size()+1)
								cout << "I don't have such a weapon, so I will assume you meant to select nothing at this time." << endl;
							break;
						}
						if (Player.Coins() < weaponsList[weaponselect-1].Cost()) {
							cout << "You have no coins available to buy " << weaponsList[weaponselect-1].Name() << "!" << endl;
							break;
						}
						cout << "You have purchased " <<  weaponsList[weaponselect-1].Name() << endl;
						sellWeapon(Player, weaponselect-1);
						madeTrans = true;
					break;
					case 2:
						weaponsList = Player.getWeaponsList();
						if (!weaponsList.size()) {
							cout << "Sorry. You have no weapon to sell :(" << endl;
							break;
						}
						cout << "Select the weapon you want to sell:" << endl;
						for (size_t i = 0; i < weaponsList.size(); i++)
							cout << "[" << i+1 << "] " << weaponsList[i].Name() << " < " << int(weaponsList[i].Cost() * sellingrate) << " coins >" << endl;
						cout << "[" << weaponsList.size()+1 << "] Nothing" << endl;
					    cout << "> ";
						cin >> weaponselect;
						if (weaponselect >= weaponsList.size()+1) {
							if (weaponselect > weaponsList.size()+1)
								cout << "You don't appear to have such a weapon, so I will assume you meant to select nothing at this time." << endl;
							break;
						}
						cout << "You have sold " <<  weaponsList[weaponselect-1].Name() << endl;
						buyWeapon(Player, weaponselect-1);
						madeTrans = true;
					break;
					case 3:
					break;
					default:
					break;
				}
			break;
			case 2:
				potionsList = merchandise.getPotionsList();
				if (!potionsList.size()) {
					cout << "Sorry. We're completely out of potions :(" << endl;
					break;
				}
				cout << "Select the potion you want to purchase:" << endl;
				for (size_t i = 0; i < potionsList.size(); i++)
					cout << "[" << i+1 << "] " << potionsList[i].Name() << " < " << potionsList[i].Cost() << " coins >" << endl;
			    cout << "[" << potionsList.size()+1 << "] Nothing" << endl;
			    cout << "> ";
				cin >> potionselect;
				if (potionselect >= potionsList.size()+1) {
					cout << "I don't have such a potion, so I will assume you meant to select nothing at this time." << endl;
					break;
				}
				if (Player.Coins() < potionsList[potionselect-1].Cost()) {
					cout << "You have no coins available to buy " << potionsList[potionselect-1].Name() << "!" << endl;
					break;
				}
				cout << "You have purchased " <<  potionsList[potionselect-1].Name() << endl;
				sellPotion(Player, potionselect-1);
				madeTrans = true;
			break;
			case 3:
				if (madeTrans)
					cout << "Thank you for your purchase. Please come again." << endl;
				else
					cout << "Haven't decided yet? No worries. Take your time and come again." << endl;
				return;
			break;
			default:
			break;
		}
	}
}
