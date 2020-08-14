#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include "TicTacToe.h"
#include "Ultimate.h"

using namespace std;


int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	system("mode 750");
	{
		TicTacToe temp;
		temp.rules_screen();
	}
	_getch();
	system("CLS");

	int which = 0;
	cout << "WHICH Tic-Tac-Toe YOU WANNA PLAY ? " << endl;
	cout << "1. Simple Tic-Tac-Toe " << endl;
	cout << "2. Ultimate Tic-Tac-Toe " << endl;
	cout << "3. Exit " << endl;
	cin >> which;
	if (which != 1 && which != 2 && which != 3)
	{
		cout << "Invalid selection!! Enter again " << endl;
		cin >> which;
	}
	system("CLS");

	if (which == 3)
	{
		return 0;
	}

	cin.ignore();
	char player1[15] = "\0";
	char player2[15] = "\0";
	cout << "Enter the name of player 1 " << endl;
	cin.getline(player1, 15);
	cout << "Enter the name of player 2 " << endl;
	cin.getline(player2, 15);
	system("CLS");

	int move = 0;
	bool win = false;
	bool full_board = false;
	bool draw = false;
	int player = 1;
	bool Continue = true;

	if (which == 1)
	{
		cout << "Do You Want to Retrieve the Previous State of the Game ?" << endl;
		int opt = 0;
		cout << "1.YES " << endl;
		cout << "2.NO " << endl;
		cin >> opt;
		TicTacToe t;
		if (opt == 1)
		{
			t.load_game();
			system("CLS");
		}
		if (opt == 2)
		{
			int size;
			cout << "Enter size of Simple Tic-Tac-Toe " << endl;
			cin >> size;
			TicTacToe t(size);
			system("CLS");
		}

		int size = t.get_size();

		cout << t << endl;
		for (int i = 0; i < t.get_size()*t.get_size() && !win && !full_board; i++)
		{
			if (player == 1)
			{
				cout << "It's " << player1 << "'s turn " << endl << endl;
				cout << "Enter the move ";
				cin >> move;
				system("CLS");

				if (move == -1)
				{
					cout << "Do you want to exit the game ? " << endl;
					cout << "1. YES " << endl;
					cout << "2. NO " << endl;
					int exit = 0;
					cin >> exit;
					while (exit != 1 && exit != 2)
					{
						cout << "invalid input!! Enter again " << endl;
						cin >> exit;
					}
					if (exit == 1)
					{
						t.save_game();
						Continue = false;
						return 0;
					}
					if (exit == 2)
					{
						Continue = true;
					}

				}

				if (Continue)
				{
					while (!t.check_move(move) && !full_board)
					{
						cout << t << endl;
						cout << "Your move is invalid!! Enter again " << endl;
						cin >> move;
						system("CLS");
					}

					if (t.check_move(move))
					{
						t.Player1_move(move);
						if (t.check_fullboard())
						{
							full_board = true;
							if (t.get_moveNo() == size*size)
								if (t.check_WinningState() == 3 && t.check_WinningState() != -1)
									draw = true;
						}
						if (t.check_WinningState() == 1 && t.get_moveNo() > 2 && !draw && t.check_WinningState() != -1)
						{
							cout << "CONGRATULATIONS! " << player1 << " wins " << endl;
							win = true;
							cout << t;
							_getch();
						}
						else if (t.check_WinningState() == 2 && t.get_moveNo() > 2 && !draw && t.check_WinningState() != -1)
						{
							cout << "CONGRATULATIONS! " << player2 << " wins " << endl;
							win = true;
							cout << t;
							_getch();
						}
						else
						{
							player = 2;
							i++;
							cout << t;
						}

					}
				}
			}

			if (player == 2)
			{
				cout << "It's " << player2 << "'s turn " << endl << endl;
				cout << "Enter the move ";
				cin >> move;
				system("CLS");

				if (move == -1)
				{
					cout << "Do you want to exit the game ? " << endl;
					cout << "1. YES " << endl;
					cout << "2. NO " << endl;
					int exit = 0;
					cin >> exit;
					while (exit != 1 && exit != 2)
					{
						cout << "invalid input!! Enter again " << endl;
						cin >> exit;
					}
					if (exit == 1)
					{
						t.save_game();
						Continue = false;
						return 0;
					}
					if (exit == 2)
					{
						Continue = true;
					}
				}

				if (Continue)
				{
					while (!t.check_move(move) && !full_board)
					{
						cout << t << endl;
						cout << "Your move is invalid!! Enter again " << endl;
						cin >> move;
						system("CLS");
					}

					if (t.check_move(move))
					{
						t.Player2_move(move);
						if (t.check_fullboard())
						{
							full_board = true;
							if (t.get_moveNo() == size*size)
								if (t.check_WinningState() == 3 && t.check_WinningState() != -1)
									draw = true;
						}
						if (t.check_WinningState() == 1 && t.get_moveNo() > 2 && !draw && t.check_WinningState() != -1)
						{
							cout << "CONGRATULATIONS! " << player1 << " wins " << endl;
							win = true;
							cout << t;
							_getch();
						}
						else if (t.check_WinningState() == 2 && t.get_moveNo() > 2 && !draw && t.check_WinningState() != -1)
						{
							cout << "CONGRATULATIONS! " << player2 << " wins " << endl;
							win = true;
							cout << t;
							_getch();
						}
						else
						{
							player = 1;
							cout << t;
						}
					}
				}
			}
			if (draw)
			{
				cout << "Match draws " << endl;
				_getch();
			}
		}
	}

	if (which == 2)
	{
		int size;
		cout << "Enter size of Ultimate Tic-Tac-Toe " << endl;
		cin >> size;
 		Ultimate u(size);
		system("CLS");

		cout << u << endl;
		int which_block = 0; //initial block input by player to start game with
		bool random_block = false;

		while (!win && !draw)
		{
			if (player == 1)
			{
				cout << "It's " << player1 << "'s turn " << endl << endl;
				if (u.getmove_no() == 0 && player == 1) //this if execute first time only
				{
					cout << "You can select any random block at first " << endl;
					cin >> which_block;
					while (!u.check_block(which_block))
					{
						cout << "Your block is invalid!! Enter again " << endl;
						cin >> which_block;
					}
					cout << "Enter the move ";
					cin >> move;
					system("CLS");
					while (!u.check_move(which_block,move))
					{
						cout << u << endl;
						cout << "Your move is invalid!! Enter again " << endl;
						cin >> move;
						system("CLS");
					}
					if (u.check_move(which_block, move))
					{
						u.player1_move(which_block, move);
						cout << u << endl;
					}
					which_block = move;
					player = 2;
				}
				else
				{
					if (u.getwin_status(which_block) == 1 || u.getwin_status(which_block) == 2 || u.getwin_status(which_block) == 3)
					{
						random_block = true;
					}
					if (random_block)
					{
						cout << "You can select any block " << endl;
						cout << "Enter the block ";
						cin >> which_block;
						while (!u.check_block(which_block))
						{
							cout << u << endl;
							cout << "Your block is invalid!! Enter again " << endl;
							cin >> which_block;
						}
						random_block = false;
					}
					cout << "Enter the move (" << which_block <<"th block only) ";
					cin >> move;
					system("CLS");
					while (!u.check_move(which_block, move))
					{
						cout << u << endl;
						cout << "Your move is invalid!! Enter again " << endl;
						cin >> move;
						system("CLS");
					}
					if (u.check_move(which_block, move))
					{
						u.player1_move(which_block, move);
						cout << u << endl;
					}
					if (u.getmove_no() > u.getsize())
					{
						if (u.check_winningstate(which_block) == 1)
						{
							u.setwin_status(which_block, 1);
							cout << u << endl;
						}
						if (u.check_winningstate(which_block) == 2)
						{
							u.setwin_status(which_block, 2);
							cout << u << endl;
						}
						if (u.check_winningstate(which_block) == 3)
						{
							u.setwin_status(which_block, 3);
							cout << u << endl;
						}
					}
					if (u.checkwin_status() == 1)
					{
						cout << "CONGRATULATIONS!! " << player1 << " has won " << endl;
						cout << u << endl;
						win = true;
					}
					if (u.checkwin_status() == 2)
					{
						cout << "CONGRATULATIONS!! " << player2 << " has won " << endl;
						cout << u << endl;
						win = true;
					}
					if (u.checkwin_status() == 3)
					{
						cout << "Match draws" << endl;
						cout << u << endl;
						draw = true;
					}
					which_block = move;
					player = 2;
					
				}
				if (player == 2 && !win && !draw)
				{
					cout << "It's " << player2 << "'s turn " << endl << endl;
					if (u.getwin_status(which_block) == 1 || u.getwin_status(which_block) == 2 || u.getwin_status(which_block) == 3)
					{
						random_block = true;
					}
					if (random_block)
					{
						cout << "You can select any block " << endl;
						cout << "Enter the block ";
						cin >> which_block;
						while (!u.check_block(which_block))
						{
							cout << "Your block is invalid!! Enter again " << endl;
							cin >> which_block;
						}
						random_block = false;
					}
					cout << "Enter the move (" << which_block << "th block only) ";
					cin >> move;
					system("CLS");
					while (!u.check_move(which_block, move))
					{
						cout << u << endl;
						cout << "Your move is invalid!! Enter again " << endl;
						cin >> move;
						system("CLS");
					}
					if (u.check_move(which_block, move))
					{
						u.player2_move(which_block, move);
						cout << u << endl;
					}
					if (u.getmove_no() > u.getsize())
					{
						if (u.check_winningstate(which_block) == 1)
						{
							u.setwin_status(which_block, 1);
							cout << u << endl;
						}
						if (u.check_winningstate(which_block) == 2)
						{
							u.setwin_status(which_block, 2);
							cout << u << endl;
						}
						if (u.check_winningstate(which_block) == 3)
						{
							u.setwin_status(which_block, 3);
							cout << u << endl;
						}
					}
					if (u.checkwin_status() == 1)
					{
						cout << "CONGRATULATIONS!! " << player1 << " has won " << endl;
						cout << u << endl;
						win = true;
					}
					if (u.checkwin_status() == 2)
					{
						cout << "CONGRATULATIONS!! " << player2 << " has won " << endl;
						cout << u << endl;
						win = true;
					}
					if (u.checkwin_status() == 3)
					{
						cout << "Match draws" << endl;
						cout << u << endl;
						draw = true;
					}
					which_block = move;
					player = 1;
				}
			}
		}
	}

	

	_getch();
}