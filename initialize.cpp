#include <iostream>
#include "Snake.h"

using namespace std;

int main() {
	
	char ans = 'N';
	do {
		
		Snake snakeObj;
		snakeObj.snakeSetUp();
		snakeObj.fruitSetUp();
		while (!snakeObj.done()) {
			snakeObj.draw();
			snakeObj.logic();
		}

		cout << "Do you want to play again? (Y/N)?\n";
		cout << "You must type a 'Y' or an 'N' :";
		cin >> ans;
	} while ((ans == 'Y') || (ans == 'y'));

	return 0;
}