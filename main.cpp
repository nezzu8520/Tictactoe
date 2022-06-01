#include <stdlib.h>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "TicTacToe.h"
using namespace std;

void welcome();
void setSpace(string, int, int, int);
int getSpaceNumber(string, int, int, int);
bool checkName(string);

int main() {
	
	char board[9]{};
	char* ptrBoard = board; 

	TicTacToe Game;
	welcome();
	system("pause");
	system("cls");
	cout << "Welcome To Tic-Tac-Toe" << endl;
	cout << "----------------------" << endl;
	cout << "Please Enter Your Names:" << endl;
	cout << "Player 1: ";
	getline(cin, Game.Player1.name);
	while (checkName(Game.Player1.name) == 0) {
		cout << "Name must be 15 characters or less" << endl;
		cout << "Player 1: ";
		getline(cin, Game.Player1.name);
	}
	cout << "Player 2: ";
	getline(cin, Game.Player2.name);
	while (checkName(Game.Player2.name) == 0) {
		cout << "Name must be 15 characters or less" << endl;
		cout << "Player 2: ";
		getline(cin, Game.Player2.name);
	}
	system("cls");
	Game.tictactoe(ptrBoard);
	system("cls");
	cout << endl << "Score" << endl;
	cout << fixed << right << "Name " << setw(13) << "Won" << setw(10) << "Loss" << setw(17) << "Games Played" << endl;
	cout << "-------------------------------------------------------" << endl;
	setSpace(Game.Player1.name, Game.Player1.win, Game.Player1.lose, Game.Player1.gamesPlayed);
	setSpace(Game.Player2.name, Game.Player2.win, Game.Player2.lose, Game.Player2.gamesPlayed);

	cout << endl << endl;
	int spaceP1 = getSpaceNumber(Game.Player1.name, Game.Player1.win, Game.Player1.lose, Game.Player1.gamesPlayed);
	int spaceP2 = getSpaceNumber(Game.Player2.name, Game.Player2.win, Game.Player2.lose, Game.Player2.gamesPlayed);

	
	fstream finalScore("FinalScore.txt", ios::out);  // fstream Object | Creates/Opens file "FinalScore.txt" in output mode
	cout << "Opening File : \"FinalScore.txt\"" << endl;
	cout << "Writing data to file..." << endl;
	finalScore << fixed << right << "Name " << setw(13) << "Won" << setw(10) << "Loss" << setw(17) << "Games Played\n";
	finalScore << Game.Player1.name << setw(spaceP1) << Game.Player1.win << setw(9) << Game.Player1.lose << setw(9) << Game.Player1.gamesPlayed << "\n";
	finalScore << Game.Player2.name << setw(spaceP2) << Game.Player2.win << setw(9) << Game.Player2.lose << setw(9) << Game.Player2.gamesPlayed << "\n";
	finalScore.close();
	cout << "Finished" << endl;
	system("pause");
	return 0;
}

void welcome() { // Draws Welcome board
	cout << " #############################################" << endl;
	cout << " #                                           #" << endl;
	cout << " #      TTTTTTTTTTT    IIII     CCCCCC       #" << endl;
	cout << " #          TTT         II     CC    CC      #" << endl;
	cout << " #          TTT         II    CC             #" << endl;
	cout << " #          TTT         II    CC             #" << endl;
	cout << " #          TTT         II     CC    CC      #" << endl;
	cout << " #         TTTTT       IIII     CCCCCC       #" << endl;
	cout << " #                                           #" << endl;
	cout << " #    TTTTTTTTTTT    AAAAAAAA     CCCCCC     #" << endl;
	cout << " #        TTT        AA    AA    CC    CC    #" << endl;
	cout << " #        TTT        AA    AA   CC           #" << endl;
	cout << " #        TTT        AAAAAAAA   CC           #" << endl;
	cout << " #        TTT        AA    AA    CC    CC    #" << endl;
	cout << " #       TTTTT       AA    AA     CCCCCC     #" << endl;
	cout << " #                                           #" << endl;
	cout << " #    TTTTTTTTTTT     OOOOOO    EEEEEEEEE    #" << endl;
	cout << " #        TTT        OO    OO   EE           #" << endl;
	cout << " #        TTT        OO    OO   EEEEEE       #" << endl;
	cout << " #        TTT        OO    OO   EE           #" << endl;
	cout << " #        TTT        OO    OO   EE           #" << endl;
	cout << " #       TTTTT        OOOOOO    EEEEEEEEE    #" << endl;
	cout << " #                                           #" << endl;
	cout << " #############################################" << endl;
}

void setSpace(string name, int win, int lose, int gamesPlayed) { // Puts the correct amount of space depending on name size (up to 15 characters)
	cout << right << name;
	int space = 2;
	for (int m = 15; m > 0; m--) {
		if (name.length() == m) {
			cout << setfill(' ') << setw(space);
		}
		space++;
	}
	cout << setprecision(3) << fixed << win;
	cout << setfill(' ') << setw(9) << lose;
	cout << setfill(' ') << setw(9) << gamesPlayed << "\n";
	return;
}

int getSpaceNumber(string name, int win, int lose, int gamesPlayed) { // Returns the number of spaces in between name and wins
	int space = 2;
	for (int m = 15; m > 0; m--) {
		if (name.length() == m) {
			return space;
		}
		space++;
	}
	return space;
}

bool checkName(string name) { // Checks if name length is less than 15 characters and greater than 0
	if (name.length() > 15 || name.length() == 0) {
		return 0;
	}
	else
		return 1;
}