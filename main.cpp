/*
 *      main.cpp
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

#include "game.hpp"

int main(void) {
	cout << "\033[01;35m=====================================" << endl;
	cout << "\033[01;35mWelcome to Reapers Battleship v1.5.2" << endl;
	cout << "\033[01;35m=====================================" << endl;
	cout << "\033[01;36mWhat's your player name: ";

	string playername;
	getline(cin, playername);

	Game::init(playername);
	Game::mainGame();

	return 0;
}
