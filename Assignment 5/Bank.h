
#pragma once
#include "BSTree.h"
#include <queue>
#include "Transaction.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Bank
{
public:
	Bank(string fileName);
	void execute();
	~Bank();

private: 
	BSTree tree;
	queue<Transaction> lilQ;
};


int main() {
	try {
		Bank jollyBank = Bank("temp");
	}
	catch (const char* msg) {
		cerr << "Error: " << msg << endl;
	}
	catch (const string msg) {
		cerr << msg << endl;
	}
	catch (...) {
		cerr << "shitzzzzuuuuu" << endl;
	}
}

