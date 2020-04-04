#include "Account.h"



Account::Account(string last, string first, int identification)
{
	if (to_string(identification).size() != 4) {
		throw "ERROR: ID must be 4 digits long";
	}
	this->id = identification;
	this->firstName = first;
	this->lastName = last;

	funds.push_back(Fund("Money Market"));
	funds.push_back(Fund("Prime Money Market"));
	funds.push_back(Fund("Long-Term Bond"));
	funds.push_back(Fund("Short-Term Bond"));
	funds.push_back(Fund("500 Index Fund"));
	funds.push_back(Fund("Capital Value Fund"));
	funds.push_back(Fund("Growth Equity Fund"));
	funds.push_back(Fund("Growth Index Fund"));
	funds.push_back(Fund("Value Fund"));
	funds.push_back(Fund("Value Stock Index"));
}

bool Account::deposit(int index, int total) 
{
	if (0 > index || index > 9) { //if index is incorrect, throw an error
		throw "Fund not found. Deposit cancelled!";
	}
	if (total > 0) { // if deposit is bigger than 0
		this->funds[index].add(total);
		this->funds[index].appendHistory("D " + to_string(id) + to_string(index) + " " + to_string(total));
		return true;
	}
	else { //if total is negative add error to fund history
		this->funds[index].appendHistory("D " + to_string(id) + to_string(index) + " " + to_string(total) + " (FAILED)");
		
		return false;
	}
}
bool Account::transfer(int index, int total, Account& other, int index2)
{
	if (0 > index || index > 9) { //checking first index
		throw "Fund not found. Transfer Cancelled!";
	}
	if (0 > index2 || index2 > 9) { //checking second index
		throw "Fund not found. Transfer Cancelled!";
	}
	if (total > 0) {
		if (index == 0 || index == 1) { //fund 0 and 1 are linked
			if (this->funds[0].getMoney() + this->funds[1].getMoney() < total) { //if there is enough money in both funds
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2) + " (FAILED)");

				other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2) + " (FAILED)");

				throw "ERROR: Not enough funds to transfer $" + to_string(total) + " from " + to_string(id) + to_string(index) + " to " + to_string(other.id) + to_string(index2);
			}
			if (this->funds[index].getMoney() >= total) { //if there is enough money in fund
				this->funds[index].remove(total); //removing from the fund
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2));

				other.funds[index2].add(total); //adding to the other accounts fund
				other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2));

				return true;
			}
			else {
				int amount = this->funds[0].getMoney() + this->funds[1].getMoney();
				if (index == 0) {
					this->funds[1].setMoney(amount - total); //remove leftover from second fund

					this->funds[0].appendHistory("T " + to_string(id) + to_string(0) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					this->funds[1].appendHistory("T " + to_string(id) + to_string(1) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					this->funds[0].setMoney(0); //emptied first account
					other.funds[index2].add(total);
				}
				else {
					this->funds[0].setMoney(amount - total);

					this->funds[1].appendHistory("T " + to_string(id) + to_string(1) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					this->funds[0].appendHistory("T " + to_string(id) + to_string(0) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					this->funds[1].setMoney(0);
					other.funds[index2].add(total);
				}
				return true;
			}
		}
		else if (index == 2 || index == 3) { //fund 2 and 3 are linked
			if (this->funds[2].getMoney() + this->funds[3].getMoney() < total) {//not enough money in both funds
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2) + " (FAILED)");

				other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2) + " (FAILED)");
				
				throw "ERROR: Not enough funds to transfer $" + to_string(total) + " from " + to_string(id) + to_string(index) + " to " + to_string(other.id) + to_string(index2);
			}
			if (this->funds[index].getMoney() >= total) { //if theres enough money in fund
				this->funds[index].remove(total); //removing from the fund
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2));

				other.funds[index2].add(total); //adding to the other accounts fund
				other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2));

				return true;
			}
			else {
				int amount = this->funds[2].getMoney() + this->funds[3].getMoney();
				if (index == 2) {
					this->funds[3].setMoney(amount - total); //remove leftover from second fund

					this->funds[2].appendHistory("T " + to_string(id) + to_string(2) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					this->funds[3].appendHistory("T " + to_string(id) + to_string(3) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					this->funds[2].setMoney(0); //emptied first account
					other.funds[index2].add(total);
				}
				else {
					this->funds[2].setMoney(amount - total);

					this->funds[3].appendHistory("T " + to_string(id) + to_string(3) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					this->funds[2].appendHistory("T " + to_string(id) + to_string(2) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));
					other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total - this->funds[index].getMoney()) + " " + to_string(other.id) + to_string(index2));

					this->funds[3].setMoney(0);
					other.funds[index2].add(total);
				}
				return true;
			}
		}
		else { //all other non-linked funds 
			if (this->funds[index].getMoney() < total) { //if there is not enough money in fund
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2) + " (FAILED)");

				other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2) + " (FAILED)");

				throw "ERROR: Not enough funds to transfer $" + to_string(total) + " from " + to_string(id) + to_string(index) + " to " + to_string(other.id) + to_string(index2);
			}
			this->funds[index].remove(total); 
			other.funds[index2].add(total);

			this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2));
			other.funds[index2].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " " + to_string(other.id) + to_string(index2));

			return true;
		}
	}
	else {
		throw "Not a valid amount. Transfer Failed!";
	}
}

bool Account::withdraw(int index, int total)
{
	if (index < 0 || index > 9) {
		throw "Fund not found. Withdraw cancelled!";
	}
	if (total > 0) {
		if (index == 0 || index == 1) {
			if (this->funds[0].getMoney() + this->funds[1].getMoney() < total) {
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " (FAILED)");

				throw "ERROR: Not enough funds to transfer $" + to_string(total) + " from " + to_string(id) + to_string(index);
			}
			if (this->funds[index].getMoney() >= total) {
				this->funds[index].remove(total);

				this->funds[index].appendHistory("W " + to_string(id) + to_string(index) + " " + to_string(total));
				return true;
			}
			else {
				int amount = (this->funds[0].getMoney() + this->funds[1].getMoney());
				if (index == 0) {
					this->funds[1].setMoney(amount - total);

					this->funds[0].appendHistory("W " + to_string(id) + to_string(0) + " " + to_string(this->funds[index].getMoney()));
					this->funds[1].appendHistory("W " + to_string(id) + to_string(1) + " " + to_string(total - this->funds[index].getMoney()));

					this->funds[0].setMoney(0);
				}
				else {
					this->funds[0].setMoney(amount - total);

					this->funds[1].appendHistory("W " + to_string(id) + to_string(1) + " " + to_string(this->funds[index].getMoney()));
					this->funds[0].appendHistory("W " + to_string(id) + to_string(0) + " " + to_string(total - this->funds[index].getMoney()));

					this->funds[1].setMoney(0);
				}
				return true;
			}
		}
		else if (index == 2 || index == 3) {
			if (this->funds[2].getMoney() + this->funds[3].getMoney() < total) {
				this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total) + " (FAILED)");

				throw "ERROR: Not enough funds to transfer $" + to_string(total) + " from " + to_string(id) + to_string(index);
			}
			if (this->funds[index].getMoney() >= total) {
				this->funds[index].remove(total);

				this->funds[index].appendHistory("W " + to_string(id) + to_string(index) + " " + to_string(total));
				return true;
			}
			else {
				int amount = (this->funds[2].getMoney() + this->funds[3].getMoney());
				if (index == 2) {
					this->funds[3].setMoney(amount - total);

					this->funds[2].appendHistory("W " + to_string(id) + to_string(2) + " " + to_string(this->funds[index].getMoney()));
					this->funds[3].appendHistory("W " + to_string(id) + to_string(3) + " " + to_string(total - this->funds[index].getMoney()));

					this->funds[2].setMoney(0);
				}
				else {
					this->funds[2].setMoney(amount - total);

					this->funds[3].appendHistory("W " + to_string(id) + to_string(3) + " " + to_string(this->funds[index].getMoney()));
					this->funds[2].appendHistory("W " + to_string(id) + to_string(2) + " " + to_string(total - this->funds[index].getMoney()));

					this->funds[3].setMoney(0);
				}
				return true;
			}
		}
		else {
			if (this->funds[index].getMoney() < total) { //if there is not enough money in fund
				this->funds[index].appendHistory("W " + to_string(id) + to_string(index) + " " + to_string(total) + " (FAILED)");

				throw "ERROR: Not enough funds to transfer $" + to_string(total) + " from " + to_string(id) + to_string(index);
			}
			this->funds[index].remove(total);

			this->funds[index].appendHistory("T " + to_string(id) + to_string(index) + " " + to_string(total));

			return true;
		}
	}
	else {
		throw "Not a valid amount. Transfer Failed!";
	}
}

int Account::getId()
{
	return this->id;
}

string Account::getFirstName()
{
	return string(firstName);
}

string Account::getLastName()
{
	return string(this->lastName);
}

string Account::getHistory(int index)
{
	string retVal = "Transaction history for " + this->firstName + " " + this->lastName + " ";
	retVal += this->funds[index].getName() + ": $" + to_string(this->funds[index].getMoney()) + "\n" + this->funds[index].display();
	
	return retVal;
}

string Account::getFullHistory()
{
	string retVal = "Transaction history for " + this->firstName + this->lastName + " by fund.\n";

	for (int i = 0; i < this->funds.size(); i++) { //looping through all funds
		if (this->funds[i].display() != "") {
			retVal += (this->funds[i].getName() + ": $" + to_string(this->funds[i].getMoney()) + "\n" + this->funds[i].display());
		}
	}
	return retVal;
}

Account::~Account()
{
}

/*
int main() {
	Account myAccount = Account("Dick", "Moby", 1111);
	try {

		myAccount.deposit(0, 1000);
		myAccount.deposit(1, -1000);
		myAccount.deposit(3, 1000);
		myAccount.transfer(5, 1500, myAccount, 2);
		myAccount.transfer(1, 1000, myAccount, 5);
		myAccount.transfer(1, -1000, myAccount, 5);
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
	Account urAccount = Account("Test", "Last", 1212);
	cout << urAccount << endl;
	cout << myAccount << endl;
	return 0;

}
*/