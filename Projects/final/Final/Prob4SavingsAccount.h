#pragma once
#include <iostream>

using namespace std;

class SavingsAccount {
public:
	SavingsAccount(float bal) {
		if (bal > 0)
			Balance = bal;
		else
			Balance = 0;
		
		FreqWithDraw = 0;
		FreqDeposit = 0;
	}
	void  Transaction(float amount) {
		if (amount > 0) {
			Balance = Deposit(amount);
			FreqDeposit++;
		}
			
		else {
			if (Balance + amount < 0) {
				cout << "Withdraw not Allowed.\n";
			}
			else {
				Balance = Withdraw(amount);
				FreqWithDraw++;
				
			}
				
		}
	}
	float Total(float sav, int time) {
		float amount = (1 + sav);
		for (int i = 0; i < time-1; i++) {
			amount *= (1 + sav);
		}
		return amount * Balance;
	}
	float TotalRecursive(float sav, int time) {
		if (time == 0)
			return Balance;
		return (1 + sav) * TotalRecursive(sav, time - 1);
	}
	void  toString() {
		cout << "Balance:\t" << Balance << endl;
		cout << "Frequency Withdrawl:\t" << FreqWithDraw << endl;
		cout << "Frequenc Deposit:\t" << FreqDeposit << endl;
	}
private:
	float Withdraw(float amount) {
		return Balance + amount;
	}
	float Deposit(float amount) {
		return Balance + amount;
	}
	float Balance;                       //Property
	int   FreqWithDraw;                  //Property
	int   FreqDeposit;                   //Property
};