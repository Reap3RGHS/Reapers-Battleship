/*
 *      shop.hpp
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


#ifndef __SHOP_HPP__
#define __SHOP_HPP__

#include "item.hpp"
#include "gear.hpp"
#include "potion.hpp"
#include "inventory.hpp"
#include "character.hpp"

class Shop {
private:
	Inventory merchandise;
	float sellingrate;
public:
	Shop() { sellingrate = 0.75; }

	void addWeapon(BattleGear w) { merchandise.addWeapon(w); }
	void removeWeapon(int index) { merchandise.removeWeapon(index); }
	void addArmor(BattleGear w) { merchandise.addArmor(w); }
	void removeArmor(int index) { merchandise.removeArmor(index); }
	void addPotion(Potion p) { merchandise.addPotion(p); }
	void removePotion(int index) { merchandise.removePotion(index); }
	void addMiscItem(Item i) { merchandise.addMiscItem(i); }
	void removeMiscItem(int index) { merchandise.removeMiscItem(index); }

	void buyWeapon(Character &Player, int index);
	void sellWeapon(Character &Player, int index);

	void sellArmor(Character &Player, int index);

	void sellPotion(Character &Player, int index);

	void sellMiscItem(Character &Player, int index);

	void Shopping(Character &Player);

	float Rate() const { return sellingrate; }
	void  Rate(float r) { sellingrate = r; }
};

#endif // __SHOP_HPP__
