#pragma once
#include <iostream>


template<class T>
class Prob2Sort
{
private:
	int* index;                                 //Index that is utilized in the sort
public:
	Prob2Sort() { index = NULL; };                   //Constructor
	~Prob2Sort() {if (index)delete[]index;}
	T* sortArray(const T*, int, bool);           //Sorts a single column array
	
	void swap(T* arr, int r1, int r2, int c) {
		T* temp = new T[c];
		int index = r1 * c;
		int index2 = r2 * c;

		//putting r1 data to temp
		for (int i = 0; i < c; i++) {
			temp[i] = arr[index];
			index++;
		}
		index = r1 * c;
		//putting r2 data to r1
		for (int i = 0; i < c; i++) {
			arr[index] = arr[index2];
			index++;
			index2++;
		}

		index2 = r2 * c;
		//putting temp data to r2
		for (int i = 0; i < c; i++) {
			arr[index2] = temp[i];
			index2++;
		}

	}
	T* sortArray(T* arr, int r, int c, int col, bool asc) {
		if (col >= c) {
			std::cout << "Sorting not possible as invalid column.\n";
		}
		else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < r - 1; j++) {
					int index1 = (j * c) + col - 1 ;
					int index2 = ((j + 1) * c) + col -1;
					if (asc) {
						
						if (arr[index1] > arr[index2]) {
							swap(arr, j, j + 1, c);
						}
					}
					else {
						if (arr[index1] < arr[index2]) {
							swap(arr, j, j + 1, c);
						}
					}
				}
			}
		}
		return arr;
	}
};