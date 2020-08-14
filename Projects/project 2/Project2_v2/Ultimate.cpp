#include <iostream>
#include "TicTacToe.h"
#include "Ultimate.h"
#include <Windows.h>

using namespace std;

Ultimate::Ultimate()
{
	size = 3;
	ultimate = new TicTacToe*[size*size];
	for (int i = 0; i < size*size; i++)
	{
		ultimate[i] = new TicTacToe();
	}
	win_status = new int[size*size];
	for (int i = 0; i < size*size; i++)
	{
		win_status[i] = 0;
	}
}

Ultimate::Ultimate(int size)
{
	this->size = size;
	ultimate = new TicTacToe*[size*size];
	for (int i = 0; i < size*size; i++)
	{
		ultimate[i] = new TicTacToe(size);
	}
	win_status = new int[size*size];
	for (int i = 0; i < size*size; i++)
	{
		win_status[i] = 0;
	}

}

Ultimate::~Ultimate()
{
	//for (int i = 0; i < size*size; i++)
	//{
	//	delete[] ultimate[i];
	//}
	delete[] ultimate;
	delete[] win_status;
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void Ultimate::printUnit(TicTacToe& t, int x, int y)
{
	int k = 1;
	int* board = t.get_board();
	for (int i = 0; i < t.get_size(); i++)
	{
		cout << "  ";
		if ((i + 1) % t.get_size() != 0)
			cout << " |";
		if ((i + 1) % t.get_size() == 0)
			gotoxy(x, y + k);

	}
	k++;
	for (int i = 0; i < t.get_size()*t.get_size(); i++)
	{
		if (board[i] != 0)
			cout << " " << board[i];
		if (board[i] == 0)
			cout << "  ";

		if (i == (t.get_size()*t.get_size()) - 1)
		{
			gotoxy(x, y + k);
			k++;
			for (int i = 0; i < t.get_size(); i++)
			{

				cout << "  ";
				if ((i + 1) % t.get_size() != 0)
					cout << " |";
				if ((i + 1) % t.get_size() == 0)
					gotoxy(x, y + k);

			}
			break;
		}
		if ((i + 1) % t.get_size() != 0)
			cout << " |";
		if ((i + 1) % t.get_size() == 0)
		{
			gotoxy(x, y + k);
			k++;
			for (int i = 0; i < t.get_size(); i++)
			{
				cout << "___";
				if ((i + 1) % t.get_size() != 0)
					cout << "|";
				if ((i + 1) % t.get_size() == 0)
				{
					gotoxy(x, y + k);
					k++;
					for (int i = 0; i < t.get_size(); i++)
					{
						cout << "   ";
						if ((i + 1) % t.get_size() != 0)
							cout << "|";
						if ((i + 1) % t.get_size() == 0)
							gotoxy(x, y + k);
					}
					k++;
				}
			}
		}
	}


}

void Ultimate::player1_move(int which_block, int move)
{
	ultimate[which_block - 1]->Player1_move(move);
	move_no++;
}

void Ultimate::player2_move(int which_block, int move)
{
	ultimate[which_block - 1]->Player2_move(move);
	move_no++;
}

bool Ultimate::check_move(int which_block, int move)
{
	//can utilize the check move of function of simpel tic tac toe here
	return ultimate[which_block - 1]->check_move(move);
}

bool Ultimate::check_block(int block)
{
	//i need to check here that the new move is in that block according to the previous move ??
	//yahan pr check block krny ki zarort ni hai... ma player ko min ma bta dunga k ab is block ma tumhara next move ana ha
	if (block < 1 || block > size*size)
		return false;
	else if (win_status[block - 1] == 1 || win_status[block - 1] == 2 || win_status[block - 1] == 3)
		return false;
	else
		return true;

}

int Ultimate::check_winningstate(int which_block)
{

	return ultimate[which_block - 1]->check_WinningState();
}

int Ultimate::getmove_no()
{
	return move_no;
}

void Ultimate::setmove_no()
{
	move_no = 0;
}

void Ultimate::setwin_status(int which_block, const int which_player)
{
	if(which_player == 1)
		win_status[which_block - 1] = 1;
	if(which_player == 2)
		win_status[which_block - 1] = 2;
	if (which_player == 3) //draw
		win_status[which_block - 1] = 3;
	if(which_player != 1 && which_player != 2 && which_player != 3)
		win_status[which_block - 1] = 0;
	
}

int Ultimate::getwin_status(int which_block)
{
	return win_status[which_block - 1];
}

int Ultimate::checkwin_status()
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
				if (checksymbols_winstatus(i, j, 'd') == 1)
				{
					player1 = true;
				}
				if (checksymbols_winstatus(i, j, 'd') == 2)
				{
					player2 = true;
				}
				if (checksymbols_winstatus(i, j, 'd') == 3)
				{
					draw = true;
				}

			}
			if (i == 0 && j == size - 1) //checking secondary diagonal
			{
				if (checksymbols_winstatus(i, j, 's') == 1)
				{
					player1 = true;
				}
				if (checksymbols_winstatus(i, j, 's') == 2)
				{
					player2 = true;
				}
				if (checksymbols_winstatus(i, j, 's') == 3)
				{
					draw = true;
				}
			}
			for (int l = 0; l < size && flag; l++)
			{
				//checking horizontal lines 
				if (i == l && j == 0)
				{
					if (checksymbols_winstatus(i, j, 'h') == 1)
					{
						player1 = true;
					}
					if (checksymbols_winstatus(i, j, 'h') == 2)
					{
						player2 = true;
					}
					if (checksymbols_winstatus(i, j, 'h') == 3)
					{
						draw = true;
					}

				}

				//checking vertical lines
				if (j == l && i == 0)
				{
					if (checksymbols_winstatus(i, j, 'v') == 1)
					{
						player1 = true;
					}
					if (checksymbols_winstatus(i, j, 'v') == 2)
					{
						player2 = true;
					}
					if (checksymbols_winstatus(i, j, 'v') == 3)
					{
						draw = true;
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
}

int Ultimate::getsize()
{
	return size;
}

bool Ultimate::check_fullwinstatus()
{
	bool flag = false; //assuming board is not full

	int cells = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int I = size*i + j;
			if (win_status[I] != 0)
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

int Ultimate::checksymbols_winstatus(int i, int j, const char ch)
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
		if (win_status[Is[l]] == 1 && win_status[Is[l]] != 2 && win_status[Is[l]] != 0)
		{
			player1++;
		}
		if (win_status[Is[l]] == 2 && win_status[Is[l]] != 1 && win_status[Is[l]] != 0)
		{
			player2++;
		}
	}
	if (player1 == size || player2 == size || check_fullwinstatus())
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

int Ultimate::check_window(int player1, int player2)
{
	if (player1 == size)
	{
		return 1;
	}
	if (player2 == size)
	{
		return 2;
	}
	if(check_fullwinstatus() && player1 != size && player2 != size)
	{
		return 3;
	}
}

ostream & operator<<(ostream &out, Ultimate &u)
{
	int x = 0, y = 0;

	for (int i = 0; i < u.size*u.size; i++)
	{
		gotoxy(x, y);
		u.printUnit(*u.ultimate[i], x, y);
		x = x + (u.size*4) + 1;
		if ((i + 1) % u.size == 0)
		{
			y = y + (u.size*3) + 1;
			x = 0;
		}
	}
	out << endl;
	out << endl;
	out << "Winning Status " << endl;
	for (int i = 0; i < u.size*u.size; i++)
	{
		out << u.win_status[i] << " ";
		if ((i + 1) % u.size == 0)
			out << endl;
	}

	return out;
}

//ofstream & operator<<(ofstream &out, Ultimate &u)
//{
//	u.ultimate[0]->load_game();
//}

//ifstream & operator<<(ifstream &in, Ultimate &u)
//{
//	
//}
