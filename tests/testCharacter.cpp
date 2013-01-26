/*
 *      testCharacter.cpp
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

#include "../character.hpp"
#include "../character.cpp"

int main(int argc, char **argv) {
	Character Player;
	Player.maxHitPoints(200);
	Player.hitPoints(150);
	cout << "Character Name: " << Player.Name() << endl;
	cout << "Character Type: " << Player.Type() << endl;
	cout << "Character Strength: " << Player.Strength() << endl;
	cout << "Character Agility: " << Player.Agility() << endl;
	cout << "Character hitPoints: " << Player.hitPoints() << endl;
	cout << "Character maxHitPoints: " << Player.maxHitPoints() << endl;
	cout << "Character attackPoints: " << Player.attackPoints() << endl;
	cout << "Character defensePoints: " << Player.defensePoints() << endl;
	cout << "Character experiencePoints: " << Player.experiencePoints() << endl;

	cout << "Character weaponName: " << Player.weaponName() << endl;
	cout << "Character armorName: " << Player.armorName() << endl;
	cout << "Character experiencePoints: " << Player.experiencePoints() << endl;
	cout << "Character experiencePoints: " << Player.experiencePoints() << endl;
	exit(EXIT_SUCCESS);
}
