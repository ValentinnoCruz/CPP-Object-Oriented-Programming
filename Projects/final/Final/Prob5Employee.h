#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Employee {

public:
	Employee(const char* name,const char* title, float rate) {
		strcpy(MyName, name);
		strcpy(JobTitle, title);
		setHourlyRate(rate);
		NetPay = GrossPay = HoursWorked = 0;
	}
	float  CalculatePay(float x, int y) {
		NetPay =  getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
		return NetPay;
	}
	float  getGrossPay(float rate, int hours) {
		if (hours < 40) {
			GrossPay = rate;
		}
		else if (hours > 40 && hours < 50){
			GrossPay = rate * 1.5;
		}
		else {
			GrossPay = rate * 2.0;
		}
		return GrossPay;
	}
	float  getNetPay(float amount) {
		return GrossPay - Tax(amount);
	}
	void   toString() {
		cout << "Name = " << MyName << " Job Title = " << JobTitle << " Hourly Rate = " << HourlyRate << " Hours Worked = " << HoursWorked << " Gross Play = " << GrossPay << " Net Pay = " << NetPay << endl;
	}
	int    setHoursWorked(int data) {
		HoursWorked = 0;
		if (data > 0 && data < 84) {
			HoursWorked = data;
		}
		else
			cout << "Unacceptable Hours Worked\n";
		return HoursWorked;
	}
	float  setHourlyRate(float data) {
		HourlyRate = 0;
		if (data > 0 && data < 200) {
			HourlyRate = data;
		}
		else
			cout << "Unacceptable Hourly Rate\n";
		
		return HourlyRate;
	}
private:
	double Tax(float amount) {
		if (amount < 500)
			return 0.1 * amount;
		else if (amount > 500 && amount < 1000)
			return 0.2 * amount;
		else
			return 0.3 * amount;

	}
	char   MyName[20];      //Property
	char   JobTitle[20];    //Property
	float  HourlyRate;      //Property
	int    HoursWorked;     //Property
	float  GrossPay;        //Property
	float  NetPay;          //Property
};