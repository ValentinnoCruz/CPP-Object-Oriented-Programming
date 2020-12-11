/* 
 * File:   Why.h
 * Author: Cruz, Valentinno 
<<<<<<< HEAD
=======
 * Created on July 20, 2021, 03:04 AM
>>>>>>> 09da2ad3b493ac25c605f1db11b18726f81eb20e
 */

#ifndef WHY_H
#define	WHY_H
#include "Game.h"
#include "AI.h"
#include "Table.h"
#include <iostream>
using namespace std;
template <class T>
class why{
public:
  why(int num){
    this->num=num;
    t = new T(num);
  }
  int num;
  ~why(){
    delete t;
  }
private:
  T *t;
};
class test{
public:
  test(int num){
    Game p(num);
    Game ai(num, 'c');
    p.Place(ai);
    p.start(ai);
  }
  ~test(){}
};

#endif	/* WHY_H */

