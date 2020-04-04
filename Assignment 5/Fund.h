#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <istream>
using namespace std;
class Fund
{
public:
	Fund(string nm);
	void add(int amount);
	void remove(int money);
	string getName();
	void setMoney(int money);
	const int getMoney();
	void appendHistory(string input);
	string display();


	friend ostream& operator<<(ostream& output, const Fund& temp) {
		output << temp.name << ": $" << to_string(temp.money) << endl;
		return output;
	}

	~Fund();
private:
	string name;
	int money;
	vector<string> history;
};
