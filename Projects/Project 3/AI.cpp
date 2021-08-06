/* 
 * File:   AI.cpp
 * Author: Cruz, Valentinno 
 * Created on July 20, 2021, 03:04 AM
 */

#include "AI.h"
#include <ctime>
using namespace std;
AI::AI(){
  crossdone=true;
  finish=true;
  goback=true;
  done=false;
  oppcombo=0;
  combo=0;
  bhit=true;
  for(int i=0;i<4;i++)
        cross[i]=true;
}
void AI::delay(){
  time_t tstart, tend;
    tstart=time(0);
    do{
      tend=time(0);
    }while(difftime(tend, tstart)<1);
}
