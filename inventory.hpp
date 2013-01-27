/*
 *      inventory.hpp
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

#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "gear.hpp"
#include "potion.hpp"

class Inventory {
private:
	vector<BattleGear> weapons;
	vector<BattleGear> armor;
	vector<Potion> potions;
	vector<Item> miscItems;
public:
	int numWeapons() const { return weapons.size(); }
	void addWeapon(BattleGear w) { weapons.push_back(w); }
	void removeWeapon(int index) { weapons.erase(weapons.begin() + index); }

	BattleGear getWeapon(int index) const { return weapons.at(index); }
	vector<BattleGear> getWeaponsList() const { return weapons; }

	void WeaponInfo();
	void WeaponInfo(int index);
	void WeaponInfo(const string name);

	int numAmor() const { return armor.size(); }
	void addArmor(BattleGear ar) { armor.push_back(ar); }
	void removeArmor(int index) { armor.erase(armor.begin() + index); }

	BattleGear getArmor(int index) const { return armor.at(index); }
	vector<BattleGear> getArmorList() const { return armor; }

	void ArmorInfo();
	void ArmorInfo(int index);
	void ArmorInfo(const string name);

	int numPotions() const { return potions.size(); }
	void addPotion(Potion p) { potions.push_back(p); };
	void removePotion(int index) { potions.erase(potions.begin() + index); }

	Potion getPotion(int index) const { return potions.at(index); }
	vector<Potion> getPotionsList() const { return potions; }

	void PotionInfo();
	void PotionInfo(int index);
	void PotionInfo(const string name);

	int numMiscItems() const { return miscItems.size(); }
	void addMiscItem(Item i) { miscItems.push_back(i); };
	void removeMiscItem(int index) { potions.erase(potions.begin() + index); }
	Item getMiscItem(int index) const { return miscItems.at(index); }
	void MiscItemInfo();
	void MiscItemInfo(int index);
	void MiscItemInfo(const string name);

	int totalNumItems() const { return weapons.size() + armor.size() + potions.size() + miscItems.size(); }
	void increaseCost(Item *i) { i->Cost(i->Cost() + 1); }
	void increaseCost(Item *i, int cost) { i->Cost(i->Cost() + cost); }
};

#endif //__INVENTORY_HPP__
