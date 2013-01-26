/*
 *      character.cpp
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


#include "character.hpp"

Character::Character() {
	name = "A Character";
	type = "An Unknown Character Type";
	strength = 1;
	agility = 1;
	hitpoints = 1;
	maxhitpoints = 1;
	experiencepoints = 1;
	expReqs = 10;
	expLevel = 1;
	coins = 0;
	yieldingWeapon.Name("Bare Hands");
	yieldingWeapon.Type("Bare Hands");
}

BattleGear Character::sellWeapon(int index) {
	BattleGear bg = stock.getWeapon(index);
	if (bg == yieldingWeapon)
		yieldingWeapon = BattleGear();
	stock.removeWeapon(index);
	return bg;
}

void Character::Stats() {
    cout << "\033[22;34mName: " << "\033[01;37m" << name << endl;
    cout << "\033[22;34mType: " << "\033[01;37m" << type << endl;
    cout << "\033[22;34mStrength: " << "\033[01;37m" << strength << endl;
    cout << "\033[22;34mAgility: " << "\033[01;37m" << agility << endl;
    cout << "\033[22;34mExperience Level: " << "\033[01;37m" << expLevel << endl;
    cout << "\033[22;34mHealth/Max: " << "\033[01;37m" << hitpoints << " / " << maxhitpoints << endl;
    cout << "\033[22;34myielding Weapon: " << "\033[01;37m" << yieldingWeapon.Name() <<
			"; Level: " << yieldingWeapon.Level() << " <" << attackPoints() << " damage>" << endl;
    cout << "\033[22;34myielding Armor: " << "\033[01;37m" << yieldingArmor.Name() << " <" << defensePoints() << " defense>" << endl;
    cout << "\033[22;34mExperience: " << "\033[01;37m" << experiencepoints << " / " << expReqs << endl;
    cout << "\033[22;34mCoins: " << "\033[01;37m" << coins << endl << endl;
}
