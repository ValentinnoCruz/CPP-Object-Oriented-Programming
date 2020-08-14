#include <time.h>
#include <stdlib.h>


class Prob1Random
{
private:
	char* set;      //The set of numbers to draw random numbers from
	char  nset;     //The number of variables in the sequence
	int* freq;     //Frequency of all the random numbers returned
	int   numRand;  //The total number of times the random number function is called
public:
	Prob1Random(const char n, const char* arr) {
		nset = n;
		numRand = 0;
		set = new char[nset];						//+1 for null
		freq = new int[nset];


		for (int i = 0; i < nset; i++) {				//copying data, deep copy
			set[i] = arr[i];
			freq[i] = 0;
		}

		
		
	}
	~Prob1Random(void) {
		nset = 0;
		if (freq)
			delete[] freq;

		if (set)
			delete[] set;
	
	}
	char randFromSet(void) {
		
		int num = rand() % 5;

		numRand++;
		freq[num]++;

		return set[num];
	
	}
	int* getFreq(void) const {
	
		return freq;
	}
	char* getSet(void) const {
	
		return set;
	}
	int getNumRand(void) const {
		return numRand;
	}
											  //been called
};