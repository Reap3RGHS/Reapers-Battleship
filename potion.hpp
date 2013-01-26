/*
 *      potion.hpp
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

#ifndef __POTION_HPP__
#define __POTION_HPP__

#include "item.hpp"

class Potion: public Item {
private:
	int power;
public:
	Potion() { name = "A Potion Item"; type = "Unknown Potion Item"; level = 0; cost = 0; power = 0; }
	Potion(string n, string t, int l, int c, int p): power(p) {
		Item(n, t, l, c);
	}
	int  Power() const { return power; }
	void Power(int p) { power = p; }
};

#endif //__POTION_HPP__
