/* 
 * File:   Game.h
 * Author: Cruz, Valentinno 
 */

//add abstract class game change functions to virtual
#include <iostream>
#include "Table.h"
#include "AI.h"
using namespace std;
#ifndef GAME_H
#define	GAME_H

class abstractGame{
public:
  virtual void check()=0;
};
class Game:public Table, public AI, public abstractGame{
public:
  //Player object
  Game(int num);
  //ai object with place
  Game(int num, char c);
  //print table
  void print(Game &) const;
  //player place
  void Place(Game &);
  //game start
  void start(Game &);
  //overloading iostream for debug
  friend ostream &operator << (ostream &, const Game &);
  ~Game();
private:
  void placeCheck();
  void tableCheck(int);
  //Player Fire
  void fire(Game &);
  //ai fire
  void fire(Game &, int);
  //check player table
  void check();
  //check ai table
  void check(Game &);
  int x1, x2, y1, y2;
  int unit[5];
  bool over;
  bool valid;
  float hit, miss;
  bool win;
  string place;
};
#endif	/* GAME_H */