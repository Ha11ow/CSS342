#include "Fund.h"

Fund::Fund(string nm)
{
	this->name = nm;
	this->money = 0;
}

void Fund::add(int amount)
{
	if (amount > 0) {
		this->money += amount;
	}
	else {
		this->history.push_back("Couldnt add");
	}
}

void Fund::remove(int amount)
{
	if (amount >= 0 && amount <= this->money) {
		this->money -= amount;
	}
	else {
		this->history.push_back("Cannot Remove Money");
	}
}

string Fund::getName()
{
	string retVal = "" + name;
	return "NAME";
}

void Fund::setMoney(int amount)
{
	if (amount >= 0) {
		this->money = amount;
	}
	else {
		this->history.push_back("Couldnt set money");
	}
}

const int Fund::getMoney()
{
	return money;
}

void Fund::appendHistory(string input)
{
	this->history.push_back(input);
}

string Fund::display()
{
	string retVal = "";
	for (int i = 0; i < history.size(); i++) {
		retVal += this->history[i] + "\n";
	}
	return retVal;
}

Fund::~Fund()
{
}
