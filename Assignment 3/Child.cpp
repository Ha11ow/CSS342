#include "Child.h"



Child::Child()
{
}

Child::Child(string firstName, string lastName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}


Child::~Child()
{
}

bool Child::operator<(const Child& other)
{
	if (lastName < other.lastName) {
		return true;
	}
	else if (lastName == other.lastName) {
		if (firstName < other.firstName) {
			return true;
		}
		else if (firstName == other.firstName) {
			if (age < other.age) {
				return true;
			}
		}
	}
	return false;
}

bool Child::operator<=(const Child& other)
{
	if (lastName < other.lastName) {
		return true;
	}
	else if (lastName == other.lastName) {
		if (firstName < other.firstName) {
			return true;
		}
		else if (firstName == other.firstName) {
			if (age <= other.age) {
				return true;
			}
		}
	}
	return false;
}

bool Child::operator>(const Child& other)
{
	if (lastName > other.lastName) {
		return true;
	}
	else if (lastName == other.lastName)
	{
		if (firstName > other.firstName) {
			return true;
		}
		else if (age > other.age) {
			return true;
		}
	}
	return false;
}

bool Child::operator>=(const Child& other)
{
	if (lastName > other.lastName) {
		return true;
	}
	else if (lastName == other.lastName) {
		if (firstName > other.firstName) {
			return true;
		}
		else if (firstName == other.firstName) {
			if (age >= other.age) {
				return true;
			}
		}
		return false;
	}
}

bool Child::operator==(const Child& other)
{
	if (lastName == other.lastName) {
		if (firstName == other.firstName) {
			if (age == age) {
				return true;
			}
		}
	}
	return false;
}

bool Child::operator!=(const Child& other)
{
	if (lastName == other.lastName) {
		if (firstName == other.firstName) {
			if (age == age) {
				return false;
			}
		}
	}
	return true;
}
