/*
 *      game.hpp
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

#ifndef __GAME_HPP__
#define __GAME_HPP__

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

class Game {
private:
	int numEnemies;
	int numShops;
	int numWeapons;
	int numArmor;
	int numPotions;
	int numMiscItems;
public:
	static Character Player;
	static vector<Character> Enemies;
	static vector<BattleGear> Weapons;
	static vector<BattleGear> Armor;
	static vector<Potion> Potions;
	static vector<Item> MiscItems;
	static Shop rbShop;

	static void init(string newPlayerName);
	static void loadGameWeapons();
	static void loadGameArmor();
	static void loadGamePotions();
	static void loadGameMiscItems();
	static void loadGameShop();
	static void loadGameEnemies();

	static void mainGame();
	static void enterBattle();
	static void upgradeweap();
};

#endif //__GAME_HPP__
