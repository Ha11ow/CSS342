#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include "Fund.h"
using namespace std;

class Account
{
public:
	Account(string last, string first, int identification);
	bool deposit(int index, int total);
	bool transfer(int index, int total, Account& other, int index2);
	bool withdraw(int index, int total);
	int getId();
	string getFirstName();
	string getLastName();
	string getHistory(int index);
	string getFullHistory();

	friend ostream& operator<<(ostream& output, const Account& temp) {
		output << temp.firstName << " " << temp.lastName << " Account ID: " << to_string(temp.id) << endl;
		for (int i = 0; i < temp.funds.size(); i++) {
			output << temp.funds[i];
		}
		return output;
	}

	~Account();

private:
	int id;
	vector<Fund> funds;
	string firstName;
	string lastName;
};

