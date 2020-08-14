#pragma once

#include <fstream>
#include <iostream>

using namespace std;

template<class T>
class Prob3Table
{
protected:
	int rows;                                 //Number of rows in the table
	int cols;                                 //Number of cols in the table
	T* rowSum;                                //RowSum array
	T* colSum;                                //ColSum array
	T* table;                                 //Table array
	T grandTotal;                             //Grand total
	void calcTable(void);                     //Calculate all the sums
public:
	Prob3Table() {

	}
	Prob3Table(const char* name, int r, int c) { 
		ifstream fin(name);

		rows = r;
		cols = c;
		table = new T[r * c+1];
		grandTotal = 0;
		
		int i = 0;
		while (!fin.eof()) {
			fin >> table[i++];
		}

		rowSum = new T[r+1];
		T sum = 0;
		int index = 0;
		for (int i = 0; i < rows * cols; i++) {
			
			if (i % cols == 0 && i != 0) {
				rowSum[index++] = sum;
				grandTotal += sum;
				sum = 0;
			}		
			sum += table[i];
		}
		rowSum[index] = sum;


		colSum = new T[c+1];
		for (int i = 0; i < c; i++)
			colSum[i] = 0;


		index = 0;
		sum = 0;
		for (int i = 0; i < rows * cols; i++) {
			colSum[i % cols] += table[i];

			
		}

	}
	~Prob3Table()
	{
		if(table)
			delete[] table;
		if(rowSum)
			delete[] rowSum; 
		if(colSum)
			delete[] colSum; 
	};
	const T* getTable(void) { return table; };
	const T* getRowSum(void) { return rowSum; };
	const T* getColSum(void) { return colSum; };
	T getGrandTotal(void) { return grandTotal; };
};

template<class T>
class Prob3TableInherited :public Prob3Table<T>
{
protected:
	T* augTable;										//Augmented Table with sums
public:
	Prob3TableInherited(const char* name, int r, int c) : Prob3Table<T>(name, r, c) {
		
		augTable = new T[(r + 1) * (c + 1)];
		int rowIndex = 0;
		int colIndex = 0;
		int tableIndex = 0;
		for (int i = 0; i <= this->rows; i++) {
			for (int j = 0; j <= this->cols; j++) {
				if (j == this->cols && i == this->rows) {
					augTable[i * this->cols + j] = this->grandTotal;
				}
				else if (j == this->cols) {
					augTable[i * this->cols + j] = this->rowSum[rowIndex++];
				}
				else if (i == this->rows) {
					augTable[i * this->cols + j] = this->colSum[colIndex++];
				}
				else {
					augTable[i * this->cols + j] = this->table[tableIndex++];
				}
				
			}
		}
		
	
	}
	~Prob3TableInherited() { delete[] augTable; };		//Destructor
	const T* getAugTable(void) { return augTable; };
};