/*
 *      inventory.cpp
 *
 *      Copyright 2013 Alexandros Iliopoulos
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


#include "inventory.hpp"

void Inventory::WeaponInfo() {
	if (weapons.size() == 0)
		cout << "There are no weapons in this inventory." << endl;
	else {
		cout << "-- Weapons Collection" << endl;
		for (int i = 0; i < weapons.size(); i++) {
			cout << "Name: " << weapons[i].Name() << "; ID: " << i << endl;
			cout << "Type: " << weapons[i].Type() << endl;
			cout << "Strength: " << weapons[i].Strength() << endl;
			cout << "Cost: " << weapons[i].Cost() << endl;
			if (i > 0 && i < (weapons.size() - 1)) cout << "----" << endl;
		}
		cout << "----------------------------" << endl;
	}
}

void Inventory::WeaponInfo(int index) {
	if (weapons.size() == 0)
		cout << "There are no weapons in this inventory." << endl;
	else if (index >= weapons.size())
		cout << "There is no such weapon in this inventory." << endl;
	else {
		cout << "-- Weapon: ID " << index << endl;
		cout << "Name: " << weapons[index].Name() << endl;
		cout << "Type: " << weapons[index].Type() << endl;
		cout << "Strength: " << weapons[index].Strength() << endl;
		cout << "Cost: " << weapons[index].Cost() << endl;
		cout << "----------------------------" << endl;
	}
}

void Inventory::WeaponInfo(const string name) {
	bool found = false;
	int index;
	for (int i = 0; i < weapons.size(); i++) {
		if (weapons[i].Name() == name) {
			found = true;
			index = i;
			break;
		}
	}
	if (!found) cout << "There is no such weapon in this inventory." << endl;
	else {
		cout << "-- Weapon: " << name << endl;
		cout << "Type: " << weapons[index].Type() << endl;
		cout << "Strength: " << weapons[index].Strength() << endl;
		cout << "Cost: " << weapons[index].Cost() << endl;
		cout << "----------------------------" << endl;
	}
}

void Inventory::ArmorInfo() {
	if (armor.size() == 0)
		cout << "There are no weapons in this inventory." << endl;
	else {
		cout << "-- Weapons Collection" << endl;
		for (int i = 0; i < weapons.size(); i++) {
			cout << "Name: " << weapons[i].Name() << "; ID: " << i << endl;
			cout << "Type: " << weapons[i].Type() << endl;
			cout << "Strength: " << weapons[i].Strength() << endl;
			cout << "Cost: " << weapons[i].Cost() << endl;
			if (i > 0 && i < (weapons.size() - 1)) cout << "----" << endl;
		}
		cout << "----------------------------" << endl;
	}
}
