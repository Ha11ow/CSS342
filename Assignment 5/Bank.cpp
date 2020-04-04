
#include "Bank.h"


Bank::Bank(string fileName)
{
	tree = BSTree();
	lilQ = queue<Transaction>();


	lilQ.push(Transaction("O Cash Johnny 1001"));
	//lilQ.push(Transaction("O Cash Johnny 1001"));
	try {
		Transaction temp = Transaction("D 10010 500");
		lilQ.push(temp);
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
	
	//lilQ.push(Transaction("D 10010 100"));


	/*
	try {
		ifstream in("BankTransIn.txt");
		string str;
		if (!in) {
			cerr << "ERROR: Could not open the file!";
		}
		while (getline(in, str)) {
			Transaction temp = Transaction(str);
			lilQ.push(temp);
		}
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
	*/
	this->execute();
}

void Bank::execute()
{
	while (lilQ.empty() != true) {
		try {
			if (lilQ.front().getType() == "O") { //opening new acc
				if (tree.Contains(lilQ.front().getId())) { //error if exists
					string error = "ERROR: Account " + to_string(lilQ.front().getId()) + " is already open. Transaction refused.";

					lilQ.pop();
					throw error;
				}
				else {
					Account temp = Account(lilQ.front().getLastName(), lilQ.front().getLastName(), lilQ.front().getId());
					tree.Insert(&temp);

					lilQ.pop();
				}
			}
			else if (lilQ.front().getType() == "D") { //deposit
				if (!(tree.Contains(lilQ.front().getId()))) {
					string error = "ERROR: Account " + to_string(lilQ.front().getId()) + " not found. Transaction refused.";

					lilQ.pop();
					throw error;
				}
				else {
					Account* temp = NULL;
					tree.Retrieve(lilQ.front().getId(), temp);
					cout << temp;
					temp->deposit(lilQ.front().getFund(), lilQ.front().getMoney());

					lilQ.pop();
				}
			}
			else if (lilQ.front().getType() == "W") { //withdraw




			}
			else if (lilQ.front().getType() == "T") { //tranfer



			}
			else if (lilQ.front().getType() == "H") { //history

			}
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
}


Bank::~Bank()
{
}
