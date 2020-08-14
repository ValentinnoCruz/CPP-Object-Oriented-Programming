#include <iostream>
#include <fstream>
#include "TicTacToe.h"
#include <math.h>

using namespace std;

//Default constructor
TicTacToe::TicTacToe()
{
	size = 3;
	board = new int[size*size];
	for (int i = 0; i < size*size; i++)
	{
		board[i] = 0;
	}
}

//Destructor
TicTacToe::~TicTacToe()
{
	delete[] board;
}

//parameterized constructor
TicTacToe::TicTacToe(int size)
{
	this->size = size;
	board = new int[this->size*this->size];
	for (int i = 0; i < this->size*this->size; i++)
	{
		board[i] = 0;
	}
}

int TicTacToe::get_moveNo()
{
	return move;
}

int TicTacToe::get_size()
{
	return size;
}

void TicTacToe::save_game()
{
	ofstream fout("tictactoe.txt");
	char delimiter = ',';
	for (int i = 0; i < size*size; i++)
	{
		fout << board[i] << delimiter;
	}
	fout.close();
}

void TicTacToe::load_game()
{
	ifstream fin("tictactoe.txt");
	int count = 0;
	int array[50];
	for (int i = 0; !fin.eof(); i++)
	{
		char temp[10];
		fin.getline(temp,10, ',');
		array[count] = atoi(temp);
		count++;
		//board[i] = atoi(temp);
	}
	size = sqrt(count - 1);
	for (int i = 0; i < size*size; i++)
	{
		board[i] = array[i];
	}
	fin.close();
}

int* TicTacToe::get_board()
{
	return board;
}

void TicTacToe::rules_screen()
{
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << " Player 1  vs  Player 2 " << endl;
	cout << endl;
	cout << " HOW TO PLAY: " << endl;
	cout << "1. Symbol of Player 1 is 1 and symbol of Player 2 is 2 " << endl;
	cout << endl;
	cout << "2. Two player select the number between 1-9 to plot their symbol in cell" << endl;
	cout << endl;
	cout << "3. Enter -1 to exit the game at any time " << endl;
	int temp[10] = { 1,2,3,4,5,6,7,8,9 };
	cout << endl;
	cout << "4. Cells number in the Tic Tac Toe(3*3) will be considered as below " << endl;
	cout << endl;
	cout << "   " << "|" << "   " << "|" << "   " << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << " " << temp[i];
		if (temp[i] == temp[8])
			cout << "\n   " << "|" << "   " << "|" << "   " << endl;
		if (temp[i] == temp[8])
			break;
		if ((i + 1) % 3 != 0)
			cout << " |";
		if ((i + 1) % 3 == 0)
		{
			cout << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "___";
				if ((i + 1) % 3 != 0)
					cout << "|";
				if ((i + 1) % 3 == 0)
				{
					cout << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << "   ";
						if ((i + 1) % 3 != 0)
							cout << "|";
						if ((i + 1) % 3 == 0)
							cout << endl;
					}
				}
			}
		}
	}
	//cout << "   " << "|" << "   " << "|" << "   " << endl;

}

void TicTacToe::Player1_move(int move_position)
{

	board[move_position - 1] = 1;
	move++;
}

void TicTacToe::Player2_move(int move_position)
{
	board[move_position - 1] = 2;
	move++;
}

int TicTacToe::check_window(int player1, int player2)
{
	if (player1 == size)
	{
		return 1;
	}
	if (player2 == size)
	{
		return 2;
	}
	if(check_fullboard() && player1 != size && player2 != size)
	{
		return 3;
	}
}

int TicTacToe::check_symbols(int i, int j, const char ch)
{
	int* Is = new int[size];
	int player1 = 0;
	int player2 = 0;
	for (int k = 0; k < size; k++)
	{
		if (ch == 'd')
		{
			Is[k] = size*(i + k) + (j + k); //Here size acts as a column number
		}
		if (ch == 'h')
		{
			Is[k] = size*(i)+(j + k);
		}
		if (ch == 'v')
		{
			Is[k] = size*(i + k) + (j);
		}
		if (ch == 's')
		{
			Is[k] = size*(i + k) + (j - k);
		}
		//cout << Is[k] << endl;
	}

	for (int l = 0; l < size; l++)
	{
		if (board[Is[l]] == 1 && board[Is[l]] != 2 && board[Is[l]] != 0)
		{
			player1++;
		}
		if (board[Is[l]] == 2 && board[Is[l]] != 1 && board[Is[l]] != 0)
		{
			player2++;
		}
	}
	if (player1 == size || player2 == size || check_fullboard())
	{
		return check_window(player1, player2);
	}
	else
	{
		return -1;
	}

	delete[] Is;
	Is = nullptr;
}

int TicTacToe::check_WinningState()
{
	bool player1 = false;
	bool player2 = false;
	bool draw = false;
	bool flag = true; //check whether to continue checking other states or not
	bool stop = false;
	for (int i = 0; i < size && !stop; i++)
	{
		for (int j = 0; j < size && !stop; j++)
		{
			if (i == j) //checking principle diagonal
			{
				if (check_symbols(i, j, 'd') == 1)
				{
					player1 = true;
				}
				if (check_symbols(i, j, 'd') == 2)
				{
					player2 = true;
				}
				if (check_symbols(i, j, 'd') == 3)
				{
					if (check_fullboard())
					{
						draw = true;
					}
				}

			}
			if (i == 0 && j == size - 1) //checking secondary diagonal
			{
				if (check_symbols(i, j, 's') == 1)
				{
					player1 = true;
				}
				if (check_symbols(i, j, 's') == 2)
				{
					player2 = true;
				}
				if (check_symbols(i, j, 's') == 3)
				{
					if (check_fullboard())
					{
						draw = true;
					}
				}
			}
			for (int l = 0; l < size && flag; l++)
			{
				//checking horizontal lines 
				if (i == l && j == 0)
				{
					if (check_symbols(i, j, 'h') == 1)
					{
						player1 = true;
					}
					if (check_symbols(i, j, 'h') == 2)
					{
						player2 = true;
					}
					if (check_symbols(i, j, 'h') == 3)
					{
						if (check_fullboard())
						{
							draw = true;
						}
					}

				}

				//checking vertical lines
				if (j == l && i == 0)
				{
					if (check_symbols(i, j, 'v') == 1)
					{
						player1 = true;
					}
					if (check_symbols(i, j, 'v') == 2)
					{
						player2 = true;
					}
					if (check_symbols(i, j, 'v') == 3)
					{
						if (check_fullboard())
						{
							draw = true;
						}
					}

				}
			}

		}
	}
	if (player1)
		return 1;
	if (player2)
		return 2;
	if (draw)
		return 3;
	if (!player1)
		return -1;
	if (!player2)
		return -1;
	if (!draw)
		return -1;
}

bool TicTacToe::check_fullboard()
{
	bool flag = false; //assuming board is not full

	int cells = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int I = size*i + j;
			if (board[I] != 0)
			{
				cells++;
			}
		}
	}
	if (cells == size*size)
	{

		flag = true; //board is full
	}
	return flag;

}

bool TicTacToe::check_move(int move)
{
	bool flag = true; //move is valid

	if (board[move - 1] == 1 || board[move - 1] == 2) //already occupied cell
	{
		//occupied = 1;
		flag = false;
	}
	if (move < 1 || move > size*size) //range of move
	{
		flag = false;
	}


	return flag;
}

ostream & operator<<(ostream & out , const TicTacToe &t)
{
	
		for (int i = 0; i < t.size; i++)
		{
			out << "  ";
			if ((i + 1) % t.size != 0)
				out << " |";
			if ((i + 1) % t.size == 0)
				out << endl;

		}
		for (int i = 0; i < t.size*t.size; i++)
		{
			if(t.board[i] != 0)
				out << " " << t.board[i];
			if (t.board[i] == 0)
				out << "  ";
			
			if (i == (t.size*t.size) - 1)
			{
				out << endl;
				for (int i = 0; i < t.size; i++)
				{

					out << "  ";
					if ((i + 1) % t.size != 0)
						out << " |";
					if ((i + 1) % t.size == 0)
						out << endl;

				}
				break;
			}
			if ((i + 1) % t.size != 0)
				out << " |";
			if ((i + 1) % t.size == 0)
			{
				out << endl;
				for (int i = 0; i < t.size; i++)
				{
					out << "___";
					if ((i + 1) % t.size != 0)
						out << "|";
					if ((i + 1) % t.size == 0)
					{
						out << endl;
						for (int i = 0; i < t.size; i++)
						{
							out << "   ";
							if ((i + 1) % t.size != 0)
								out << "|";
							if ((i + 1) % t.size == 0)
								out << endl;
						}
					}
				}
			}
		}


		return out;
	

}
