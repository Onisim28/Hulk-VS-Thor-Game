#include <iostream>
#include <conio.h>
#include "Header.h"
#include <ctime>

using namespace std;



int main() {

	srand(time(NULL));
	
	Warrior Hulk("Hulk", 120, 20, 20);
   Warrior Thor("Thor", 100, 25, 25);
   Battle :: BattleStarts(Hulk,Thor);
	

	system("pause");
	
}