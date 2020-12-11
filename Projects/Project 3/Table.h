/* 
 * File:   Table.h
<<<<<<< HEAD
 * Author: Cruz, Valentinno
=======
 * Author: Cruz, Valentinno 
 * Created on July 20, 2021, 03:04 AM
>>>>>>> 09da2ad3b493ac25c605f1db11b18726f81eb20e
 */

#ifndef TABLE_H
#define	TABLE_H
#include <iostream>
using namespace std;
struct table{
  char **fake;
  char **real;
};
class Table {
public:
  //Constructor
  Table(int);
  int getNum() const{
    return num;
  }
  //return one element of table
  char getTable(int x, int y){
    return t->real[x][y];
  }
  void setTable(int x, int y, char i){
    t->fake[x][y]=i;
    t->real[x][y]=i;
  }
  //Destructor
  virtual ~Table();
protected:
  int num;
  table *t;
};
#endif	/* TABLE_H */


