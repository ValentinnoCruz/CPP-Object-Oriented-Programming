#pragma once
#include <iostream>
#include "TicTacToe.h"

using namespace std;

class Ultimate
{
public:
	Ultimate();
	Ultimate(int);
	~Ultimate();
	friend ostream& operator <<(ostream&, Ultimate&);
	//friend ofstream& operator <<(ofstream&, Ultimate&);
	//friend ifstream& operator <<(ifstream&, Ultimate&);
	void printUnit(TicTacToe&, int, int);
	void player1_move(int which_block, int move);
	void player2_move(int which_block, int move);
	bool check_move(int which_block, int move);
	bool check_block(int block);
	int check_winningstate(int which_block);
	int getmove_no();
	void setmove_no();
	void setwin_status(int which_block ,const int which_player);
	int getwin_status(int which_block);
	int checkwin_status();
	int getsize();
	bool check_fullwinstatus();
	
private:
	TicTacToe** ultimate;
	int size;
	int move_no;
	int* win_status;
	int checksymbols_winstatus(int i, int j, const char ch);
	int check_window(int, int);
};