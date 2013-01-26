/*
 *      gear.hpp
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

#ifndef __GEAR_HPP__
#define __GEAR_HPP__

#include "item.hpp"

class BattleGear: public Item {
private:
	int strength;
public:
	BattleGear() { name = "A Battle Item"; type = "Unknown Battle Item"; level = 0; cost = 0; strength = 0; }
	BattleGear(string n, string t, int l, int c, int s): strength(s) {
		name = n; type = t; level = l; cost = c;
	}
	int  Strength() const { return strength; }
	void Strength(int s) { strength = s; }
};

#endif //__GEAR_HPP__
