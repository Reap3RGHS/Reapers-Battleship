/*
 *      testBattleGear.cpp
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

#include "../gear.hpp"

int main(int argc, char **argv) {
	BattleGear bg;
	bg = BattleGear("Anchemacha", "Spear", 1, 25, 4);
	cout << "BattleGear Name: " << bg.Name() << endl;
	cout << "BattleGear Type: " << bg.Type() << endl;
	cout << "BattleGear Level: " << bg.Level() << endl;
	cout << "BattleGear Cost: " << bg.Cost() << endl;
	cout << "BattleGear Strength: " << bg.Strength() << endl;
	exit(EXIT_SUCCESS);
}
