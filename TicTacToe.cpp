#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::setBoard(char* board, int i, int num) { // Inserts values into board array
	for (i = 0; i < 9; i++) {
		board[i] = num;
		num++;
	}
}

void TicTacToe::drawBoard(char* board) { // Draws Board
	system("cls");
	cout << "Tic Tac Toe" << endl;
	cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
	cout << "        |     |     \n";
	cout << "     " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
	cout << "   _____|_____|_____\n";
	cout << "        |     |     \n";
	cout << "     " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
	cout << "   _____|_____|_____\n";
	cout << "        |     |     \n";
	cout << "     " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
	cout << "        |     |     \n\n";
}

char TicTacToe::TTTwinner(char* board) { // Checks to see if there is a winner
	//First Player
	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
		return 'X';
	if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
		return 'X';
	if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
		return 'X';

	if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
		return 'X';
	if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
		return 'X';
	if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
		return 'X';

	if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
		return 'X';
	if (board[6] == 'X' && board[4] == 'X' && board[2] == 'X')
		return 'X';
	//Second Player
	if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
		return 'O';
	if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
		return 'O';
	if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
		return 'O';

	if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
		return 'O';
	if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
		return 'O';
	if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
		return 'O';

	if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
		return 'O';
	if (board[6] == 'O' && board[4] == 'O' && board[2] == 'O')
		return 'O';
	// Check if tie
	if ((board[0] == 'O' || board[0] == 'X') &&
		(board[1] == 'O' || board[1] == 'X') &&
		(board[2] == 'O' || board[2] == 'X') &&
		(board[3] == 'O' || board[3] == 'X') &&
		(board[4] == 'O' || board[4] == 'X') &&
		(board[5] == 'O' || board[5] == 'X') &&
		(board[6] == 'O' || board[6] == 'X') &&
		(board[7] == 'O' || board[7] == 'X') &&
		(board[8] == 'O' || board[8] == 'X'))
		return 't';

	return '/';
}

void TicTacToe::tictactoe(char* board) // TicTacToe game
{
	int answer;
	setBoard(board, i, num);
	char player = 'X';
	while (1) {
		drawBoard(board);
		char mark;
		cout << "Enter the field where you want your mark" << endl;
		if (player == 'X') {
			cout << "Turn: " << Player1.name << ": ";
		}
		else {
			cout << "Turn: " << Player2.name << ": ";
		}
		cin >> mark;
		while (mark != 49 && mark != 50 && mark != 51 && mark != 52 && mark != 53 &&
			mark != 54 && mark != 55 && mark != 56 && mark != 57) { // User can not enter a value less than 1 or greater than 9
			cout << "Value must be a number between 1 - 9" << endl;
			cout << "Enter the field where you want your mark" << endl;
			if (player == 'X') {
				cout << "Turn: " << Player1.name << ": ";
			}
			else {
				cout << "Turn: " << Player2.name << ": ";
			}
			cin >> mark;
		}
		if (mark == '1') {
			if (board[0] != 'X' && board[0] != 'O')
				board[0] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '2') {
			if (board[1] != 'X' && board[1] != 'O')
				board[1] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '3') {
			if (board[2] != 'X' && board[2] != 'O')
				board[2] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '4') {
			if (board[3] != 'X' && board[3] != 'O')
				board[3] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '5') {
			if (board[4] != 'X' && board[4] != 'O')
				board[4] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '6') {
			if (board[5] != 'X' && board[5] != 'O')
				board[5] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '7') {
			if (board[6] != 'X' && board[6] != 'O')
				board[6] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '8') {
			if (board[7] != 'X' && board[7] != 'O')
				board[7] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		else if (mark == '9') {
			if (board[8] != 'X' && board[8] != 'O')
				board[8] = player;
			else {
				cout << "Choose a different field" << endl;
				continue;
			}
		}
		if (player == 'X') // Changes Player 
			player = 'O';
		else {
			player = 'X';
		}

		drawBoard(board);
		TTTwinner(board);
		if (TTTwinner(board) == 'X') {
			cout << "Player One '" << Player1.name << "' wins!" << endl << endl << endl;
			playerOneWin();
			cout << "Would you like to play again?\n1 = Yes\n2 = No\nEnter: ";
			cin >> answer;
			if (answer == 1) {
				setBoard(board, i, num);
				player = 'X';
				continue;
			}
			else
				break;
		}
		else if (TTTwinner(board) == 'O') {
			cout << "Player Two '" << Player2.name << "' wins!" << endl;
			playerTwoWin();
			cout << "Would you like to play again?\n1 = Yes\n2 = No\nEnter: ";
			cin >> answer;
			if (answer == 1) {
				setBoard(board, i, num);
				player = 'X';
				continue;
			}
			else
				break;
		}
		else if (TTTwinner(board) == 't') {
			cout << "It's a TIE!" << endl;
			tie();
			cout << "Would you like to play again?\n1 = Yes\n2 = No\nEnter: ";
			cin >> answer;
			if (answer == 1) {
				setBoard(board, i, num);
				player = 'X';
				continue;
			}
			else
				break;
		}
	}
	return;
}

void TicTacToe::playerOneWin() { // If Player one wins
	Player1.win += 1;
	Player1.gamesPlayed += 1;
	Player2.lose += 1;
	Player2.gamesPlayed += 1;
}

void TicTacToe::playerTwoWin() { // If player two wins
	Player2.win += 1;
	Player2.gamesPlayed += 1;
	Player1.lose += 1;
	Player1.gamesPlayed += 1;
}

void TicTacToe::tie() {			// If neither player one or two wins
	Player1.gamesPlayed += 1;
	Player2.gamesPlayed += 1;
}