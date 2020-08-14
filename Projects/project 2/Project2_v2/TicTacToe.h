#pragma once
#include <iostream>
using namespace std;

class TicTacToe
{
public:
	TicTacToe(); //default constructor
	~TicTacToe(); //destructor
	TicTacToe(int size); //parameterized constructor
	void Player1_move(int move_position);
	void Player2_move(int move_position);
	bool check_move(int move);
	bool check_fullboard();
	int check_WinningState(); //if return 1 then player 1 wins , if returns 2 then player 2 wins and return 3 to continue
	void rules_screen();
	friend ostream& operator <<(ostream&, const TicTacToe&);
	int get_moveNo();
	int* get_board();
	int get_size();
	void save_game();
	void load_game();
private:
	int* board;
	int size;
	int check_window(int, int); //Assist in checking the winning state
	int check_symbols(int i, int j, const char); // Also Assist in checking the winning state
	int move;
};