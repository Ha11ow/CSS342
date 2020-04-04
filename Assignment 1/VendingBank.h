#pragma once
#include <string>
using namespace std;
class VendingBank
{
public:
	VendingBank();
	VendingBank(int id);
	~VendingBank();
	int getVendingBankID() const;
	bool setVendingBankID(const int ID);
	int getQuarters() const;
	bool setQuarters(const int quarters);
	int getDollarBills() const;
	bool setDollarBills(const int dollarBills);
	int getFiveDillarBills() const;
	bool setFiveDollarBills(const int fiveDollarBills);
	void insert(const int quarters, const int dollarBills, const int fiveDollarBills);
	int refundInQuarters() const;
	VendingBank operator+(const VendingBank other);
	VendingBank operator=(const VendingBank other);
	bool operator==(const VendingBank other);
	bool operator>=(const VendingBank other);
	bool operator<= (const VendingBank other);
	bool operator!= (const VendingBank other);
	bool operator < (const VendingBank other);
	bool operator > (const VendingBank other);
	//dont need divide or multiply since it doenst make sense to have them

private:
	const int ID;
	int quarters;
	int dollarBills;
	int fiveDollarBills;




}