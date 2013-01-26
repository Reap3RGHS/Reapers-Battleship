/*
 *      testItem.cpp
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

#include "../item.hpp"

int main(int argc, char **argv) {
	vector<Item> vItem;
	vItem.push_back(Item("stick", "wood", 1, 1));
	vItem.push_back(Item("stick", "wood", 1, 1));
	vItem.push_back(Item("bat", "wood", 1, 2));
	cout << "Test Item[0]: " << vItem[0].Name() << endl;

	cout << "Is vItem[0] = vItem[0]? " << ((vItem[0] == vItem[0]) ? "Yes" : "No") << endl;
	cout << "Is vItem[0] = vItem[1]? " << ((vItem[0] == vItem[1]) ? "Yes" : "No") << endl;
	cout << "Is vItem[0] = vItem[2]? " << ((vItem[0] == vItem[2]) ? "Yes" : "No") << endl;
	exit(EXIT_SUCCESS);
}

