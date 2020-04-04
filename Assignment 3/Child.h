#pragma once
#include <string>
#include <ioStream>

using namespace std;
class Child
{
public:
	Child();
	Child(string firstName, string lastName, int age);
	~Child();
	friend ostream& operator<<(ostream& outStream, const Child& other)
	{	
		outStream << other.firstName << other.lastName << other.age;
		return outStream;
	}
	bool operator < (const Child& other);
	bool operator <= (const Child& other);
	bool operator > (const Child& other);
	bool operator >= (const Child& other);
	bool operator == (const Child& other);
	bool operator != (const Child& other);


private:
	string firstName;
	string lastName;
	int age;
}
;

