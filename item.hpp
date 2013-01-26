/*
 *      item.hpp
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

#ifndef __ITEM_HPP__
#define __ITEM_HPP__

class Item {
protected:
	string name;
	string type;
	int level;
	int cost;
public:
	Item() { name = "An Item"; type = "Unknown Item"; level = 0; cost = 0; }
	Item(string n, string t, int l, int c): name(n), type(t), level(l), cost(c) {}
	bool operator ==(const Item &i) { return this == &i; }

	string Name() const { return name; }
	void Name(string n) { name = n; }

	string Type() const { return type; }
	void Type(string n) { type = n; }

	int  Level() const { return level; }
	void Level(int l) { level = l; }

	int  Cost() const { return cost; }
	void Cost(int ct) { cost = ct; }
};

#endif //__ITEM_HPP__
