/*
 *      testShop.cpp
 *
 *      Copyright 2013 Marc Sylvestre <marc.sylvestre@manhydra.com>
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
#include <cstdlib>
#include <vector>
using namespace std;

#include "../character.cpp"
#include "../shop.hpp"
#include "../shop.cpp"

int main(int argc, char **argv) {
	Shop testShop;
	Character Player;
	Player.Coins(50);
	Player.addWeaponToStock(BattleGear("Anchemacha", "Spear", 1, 25, 4), false);
	Player.addPotionToStock(Potion("Healing", "Heal", 1, 5, 5), false);

	testShop.addWeapon(BattleGear("Anchemacha", "Spear", 1, 25, 4));
	testShop.addWeapon(BattleGear("Spartan Dagger", "Dagger", 1, 30, 5));
	testShop.addWeapon(BattleGear("Cutter", "Dagger", 1, 40, 6));
	testShop.addArmor(BattleGear("Greek Bronze Shield", "Shield", 1, 25, 5));
	testShop.addPotion(Potion("Healing", "Heal", 1, 5, 5));

	testShop.Shopping(Player);

	exit(EXIT_SUCCESS);
}
