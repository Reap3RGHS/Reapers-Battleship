/*
 *      character.hpp
 *
 *      Copyright 2013  Alexandros Iliopoulos <reaperghs@gmail.com>
 *						Marc Sylvestre <marc.sylvestre@manhydra.com>
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

#ifndef __CHARAC_HPP__
#define __CHARAC_HPP__

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

//A Character is the main player and the various enemies it combats.
class Character {
private:
	string name;
	string type;
	int strength;
	int agility;
	int hitpoints;
	int maxhitpoints;
	int experiencepoints;
	int expReqs;
	int expLevel;
	int coins;
	BattleGear yieldingWeapon;
	BattleGear yieldingArmor;
	Potion yieldingPotion;
	Item yieldingMiscItem;
	Inventory stock;
public:
	Character();

	string Name() const { return name; }
	void   Name(string n) { name = n; }

	string Type() const { return type; }
	void   Type(string t) { type = t; }

	int  Strength() const { return strength; }
	void Strength(int s) { strength = s; }
	void increaseStrength() { strength++; }
	void increaseStrength(int s) { strength += s; }

	int  Agility() const { return agility; }
	void Agility(int ag) { agility = ag; }
	void increaseAgility() { agility++; }
	void increaseAgility(int ag) { agility += ag; }

	int  hitPoints() const { return hitpoints; }
	void hitPoints(int points) { if (points > maxhitpoints) hitpoints = maxhitpoints; else hitpoints = points; }

	void increaseHitPoints() { if (++hitpoints > maxhitpoints) hitpoints--; }
	void increaseHitPoints(int points) { if ( (hitpoints + points) > maxhitpoints) hitpoints = maxhitpoints; else hitpoints += points; }
	void decreaseHitPoints() { if (--hitpoints < 0) hitpoints++; }
	void decreaseHitPoints(int points) { if ( (hitpoints - points) < 0) hitpoints = 0; else hitpoints -= points; }

	int  maxHitPoints() const { return maxhitpoints; }
	void maxHitPoints(int points) { maxhitpoints = points; }

	void increaseMaxHitPoints() { maxhitpoints++; }
	void increaseMaxHitPoints(int points) { maxhitpoints += points; }

	int  attackPoints() const { return strength + yieldingWeapon.Strength(); }
	void attackEnemy(Character *e) { e->decreaseHitPoints(attackPoints()); }
	int  defensePoints() const { return agility + yieldingArmor.Strength(); }

	int  experiencePoints() const { return experiencepoints; }
	void experiencePoints(int points) { experiencepoints = points; }
	void increaseExperiencePoints(int points) { experiencepoints += points; }

	int  expRequirements() const { return expReqs; }
	void expRequirements(int points) { expReqs = points; }

	void increaseExpRequirements() { expReqs++; }
	void increaseExpRequirements(int points) { expReqs += points; }

	bool expReached() const { return (experiencepoints == expReqs); }

	int  characterLevel() const { return expLevel; }
	void characterLevel(int lv) { expLevel = lv; }
	void increaseCharacterLevel() { expLevel++; }

	int  Coins() const { return coins; }
	void Coins(int c) { coins = c; }

	void increaseCoins() { coins++; }
	void increaseCoins(int c) { coins += c; }

	void decreaseCoins() { coins--; }
	void decreaseCoins(int c) { coins -= c; }

	string weaponName() const { return yieldingWeapon.Name(); }
	void weaponName(string n) { yieldingWeapon.Name(n); }

	int weaponLevel() const { return yieldingWeapon.Level(); }
	void weaponLevel(int lv) { yieldingWeapon.Level(lv); }

	void increaseWeaponLevel() { yieldingWeapon.Level(yieldingWeapon.Level() + 1); }
	void increaseWeaponLevel(int lv) { yieldingWeapon.Level(yieldingWeapon.Level() + lv); }

	int weaponCost() const { return yieldingWeapon.Cost(); }
	void weaponCost(int ct) { yieldingWeapon.Cost(ct); }

	void increaseWeaponCost() { yieldingWeapon.Cost(yieldingWeapon.Cost() + 1); }
	void increaseWeaponCost(int ct) { yieldingWeapon.Cost(yieldingWeapon.Cost() + ct); }

	void addWeaponToStock(BattleGear bg, bool equip) { stock.addWeapon(bg); if (equip) yieldingWeapon = bg; }
	void removeWeaponToStock(int index) { if (stock.getWeapon(index) == yieldingWeapon) yieldingWeapon = BattleGear(); stock.removeWeapon(index); }
	void buyWeapon(BattleGear bg);
	BattleGear sellWeapon(int index);

	string armorName() const { return yieldingArmor.Name(); }
	void armorName(string n) { yieldingArmor.Name(n); }

	int armorLevel() const { return yieldingArmor.Level(); }
	void armorLevel(int lv) { yieldingArmor.Level(lv); }

	void increaseArmorLevel() { yieldingArmor.Level(yieldingArmor.Level() + 1); }
	void increaseArmorLevel(int lv) { yieldingArmor.Level(yieldingArmor.Level() + lv); }

	int armorCost() const { return yieldingArmor.Cost(); }
	void armorCost(int ct) { yieldingArmor.Cost(ct); }

	void increaseArmorCost() { yieldingArmor.Cost(yieldingArmor.Cost() + 1); }
	void increaseArmorCost(int ct) { yieldingArmor.Cost(yieldingArmor.Cost() + ct); }

	void addArmorToStock(BattleGear bg, bool equip) { stock.addArmor(bg); if (equip) yieldingArmor = bg; }

	string potionName() const { return yieldingPotion.Name(); }
	void potionName(string n) { yieldingPotion.Name(n); }

	int potionCost() const { return yieldingPotion.Cost(); }
	void potionCost(int ct) { yieldingPotion.Cost(ct); }

	void increasePotionCost() { yieldingPotion.Cost(yieldingPotion.Cost() + 1); }
	void increasePotionCost(int ct) { yieldingPotion.Cost(yieldingPotion.Cost() + ct); }

	void addPotionToStock(Potion p, bool equip) { stock.addPotion(p); if (equip) yieldingPotion = p; }

	string miscItemName() const { return yieldingMiscItem.Name(); }
	void miscItemName(string n) { yieldingMiscItem.Name(n); }

	int miscItemCost() const { return yieldingMiscItem.Cost(); }
	void miscItemCost(int ct) { yieldingMiscItem.Cost(ct); }

	void increaseMiscItemCost() { yieldingMiscItem.Cost(yieldingMiscItem.Cost() + 1); }
	void increaseMiscItemCost(int ct) { yieldingMiscItem.Cost(yieldingMiscItem.Cost() + ct); }

	void addMiscItemToStock(Item i, bool equip) { stock.addMiscItem(i); if (equip) yieldingMiscItem = i; }

	void Stats();
};

#endif //__CHARAC_HPP__
