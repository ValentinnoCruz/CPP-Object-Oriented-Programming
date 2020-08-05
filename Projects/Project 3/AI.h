/* 
 * File:   AI.h
 * Author: Cruz, Valentinno 
 * Created on August 05, 2021, 11:27 AM
 */

#ifndef AI_H
#define	AI_H

class AI {
public:
  AI();
  void delay();
protected:
  bool done;
  bool cross[4];
  bool crossdone;
  bool goback;
  int hx, hy, x, y;
  bool finish;
  int oppcombo;
  int combo;
  char cx, cy;
  bool oneend;
  bool combohit;
  bool bhit;
};

#endif	/* AI_H */

