#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>

using namespace std;

void statSheet();
void mainScreen();
void enemyOne();
void upgradeweap();
void potionshop();
void update();
void shop();

int inputmain = 0;
int input1 = 0;
int hp = 150;
int maxhp = 150;
int atk = 5;
int def = 1;
int exp = 0;
int atkboost;
int enemy1hp = 200;
int enemy1maxhp = 200;
int enemy1exp = 20;
int enemy1atk = 1;
int enemy1atkboost;
int expreq = 20;
int playerlevel = 1;
int coins = 10;
int wincoins;
int weaponlevel = 1;
int weaponlevelreq = 10;
int potioncost = 5;
int weaponselection = 0;
int daggerprice = 30;
int swordprice = 40;
string potion;
string weaponupgrade;
string playername;
string weapon = "Anchemacha";
string armor = "Greek Bronze Shield";
string enemy1 = "Trojan";

void shop()
{
    cout << "Welcome to my Shop!" << endl;
    cout << "Select the weapon that you want to buy: " << endl << endl;
    
    cout << "[1] Spartan Dagger < 30 coins >" << endl;
    cout << "[2] Cutter < 40 coins >" << endl;
    cout << ">";
    cin >> weaponselection;
    
    if ( coins < daggerprice && coins < swordprice)
    {
        cout << "\033[01;31mYou have no coins available to buy this item!" << endl << endl;
        
    }
    
    else if (weaponselection == 1)
    {
        weapon = "Spartan Dagger";
        coins -= 30;
        atk += 5;
        weaponlevel = 1;
        weaponlevelreq = 10;
        
        cout << "\033[01;32mCongratulations! You bought \"Dagger\"!!! " << endl << endl;
    }
    
    else if (weaponselection == 2)
    {
        weapon = "Cutter";
        coins -= 40;
        atk += 10;
        weaponlevel = 1;
        weaponlevelreq = 10;
        
        cout << "\033[01;32mCongratulations! You bought \"Cutter\"!!! " << endl << endl;
    }
    mainScreen();
}

void update()
{
    FILE* file = popen("git pull", "r");
// use fscanf to read:
char buffer[100];
fscanf(file, "%s", buffer);
pclose(file);

return;
}

void statSheet()
{
    cout << "\033[22;34mName: " << "\033[01;37m" << playername << endl;
    cout << "\033[22;34mLevel: " << "\033[01;37m" << playerlevel << endl;
    cout << "\033[22;34mHealth: " << "\033[01;37m" << hp << " / " << maxhp << endl;
    cout << "\033[22;34mWeapon: " << "\033[01;37m" << weapon << " Level " << weaponlevel << " <" << atk << " - " << atk + 8 << " damage>" << endl;
    cout << "\033[22;34mArmor: " << "\033[01;37m" << armor << " <" << def << " - " << def + 5 << " defence>" << endl;
    cout << "\033[22;34mExperience: " << "\033[01;37m" << exp << " / " << expreq << endl;
    cout << "\033[22;34mCoins: " << "\033[01;37m" << coins << endl << endl;

    mainScreen();
}

void upgradeweap()
{
    if (weaponlevel == 9)
    {
        cout << "\033[01;32mYou have reached level " << weaponlevel << ", your weapon is now master." << endl << endl;
        mainScreen();
    }
    
    
    cout << "\033[01;33mAre you sure you want to spent " << weaponlevelreq << " coins for weapon upgrade? [yes/no] " << endl;
    cout << "\033[01;33m>";
    cin >> weaponupgrade;
    if (coins < weaponlevelreq){
            cout << "\033[01;31mYou have no coins available for this upgrade!" << endl << endl;
            
    }
    else if (weaponupgrade == "yes"){
        coins -= 10;
        atk += 5;
        weaponlevel ++;
        weaponlevelreq += 10;
        cout << "\033[01;32mCongratulations! Your weapon is now level " << weaponlevel << endl << endl;
        
    }
    mainScreen();
}
void potionshop()
{
    cout << "\033[01;33mAre you sure you want to buy HP Potions for 5 coins? [yes/no]" << endl;
    cout << "\033[01;33m>";
    cin >> potion;
    if (hp == maxhp) 
    {
        cout << "\033[01;31mYour HP is full! You can't increase it more." << endl << endl;
    }
    else if (coins < potioncost)
    {
        cout << "\033[01;31mYou have no coins available for this upgrade!" << endl << endl;
       
    }
    else if (potion == "yes")
    {
        coins -= 5;
        hp += 5;
    if (hp >= maxhp)
        {
            hp = 150;
        }
        cout << "\033[01;32mCongratulations! Your HP now is " << hp << "." << endl << endl;
        
    }
    mainScreen();
}

void mainScreen()
{

if (exp == expreq)
    {
    cout << "\033[01;32mCongratulations! You have gained a level!" << endl << endl;
    playerlevel++;
    exp = 0;
    expreq += 20;
    hp = 150;
    enemy1atk += 2;
    }

    cout << "\033[01;35m[1] Battle" << endl;
    cout << "\033[01;35m[2] Character" << endl;
    cout << "\033[01;35m[3] Upgrade Weapon" << endl;
    cout << "\033[01;35m[4] Buy HP Potion" << endl;
    cout << "\033[01;35m[5] Weapon Shop" << endl;
    cout << "\033[01;35m[6] Update" << endl;
    cout << "\033[01;35m[7] Quit" << endl;
    cout << "\033[01;35m>";
    cin >> inputmain;
	switch(inputmain){
		case 1:
			enemyOne();
			break;
		case 2:
			statSheet();
			break;
		case 3:
			upgradeweap();
			break;
		case 4:
			potionshop();
			break;
		case 5:
                        shop();
                        break;
                case 6:
                        update();
			break;
                case 7:
			cout << "\033[01;36mThanks for playing!" << endl;
			return;
		default:
			cout << "\033[01;31mInvalid input, please retry." << endl << endl;
			mainScreen();
			break;
	}
}

void enemyOne()
{
    if (playerlevel == 9) {
    cout << "\033[01;32mCongratulations! You have FINISHED the game!!!!" << endl << endl;
    return;
}
    cout << "\033[01;32m" << enemy1 << " \033[01;32m<" << enemy1hp << " / " << enemy1maxhp << ">" << " is ready for battle!" << endl;
    cout << "---" << endl;
    while (enemy1hp > 0)
    {
    cout << "\033[01;35m[1] Attack" << endl;
    cout << "\033[01;35m[2] Run" << endl;
    cout << "\033[01;35m>";
    cin >> input1;
        if (input1 == 1)
        {
        atkboost = (rand () % 8);
            if (atkboost >= 7)
            {
                atkboost += 8;
                cout << "\033[01;32m>Critical Hit! You hit " << enemy1 << " for " << atk + atkboost << " damage." << endl << endl;

            }
            else
        cout << "\033[01;32m> You hit " << enemy1 << " for " << atk + atkboost << " damage." << endl << endl;
        enemy1hp -= atk + atkboost;
        cout << enemy1 << "\033[01;32m: " << enemy1hp << " / " << enemy1maxhp << endl << endl;

        enemy1atkboost = (rand () % 5) - def;
        cout << "\033[01;32m> " << enemy1 << " hit you for " << enemy1atk + enemy1atkboost << " damage." << endl << endl;
        hp -= enemy1atk + enemy1atkboost;
        cout << playername << "\033[01;32m: " << hp << " / " << maxhp << endl << endl;
        if (hp < 0)
            {
                cout << "\033[01;31mYou are dead!" << endl << endl;
                return;
            }
        }
        else if (input1 == 2)
        {
        cout << "\033[01;31m>You have ran away from the " << enemy1 << "." << endl << endl;
        mainScreen();
        return;
        }
        else
        {
        cout << "\033[01;31mInvalid input, please retry." << endl << endl;
        }
    
    }
    cout << "\033[01;32mYou have slain the " << enemy1 << "!" << endl << endl;
            exp += enemy1exp;
            wincoins = coins += (rand () % 28);
            enemy1hp = 200;
            mainScreen();
}




int main()
{

cout << "\033[01;35m=====================================" << endl;
cout << "\033[01;35mWelcome to Reapers Battleship v3.1.1" << endl;
cout << "\033[01;35m=====================================" << endl;
cout << "\033[01;36mPlease write here your player name: ";
getline(cin,playername);

mainScreen();

return 0;
}
