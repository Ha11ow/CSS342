#include <iostream>
#include "TimeSpan.h"
using namespace std;

int main()
{
	std::cout << "Testing Decimals: " << endl;
	TimeSpan time = TimeSpan(1.1, 90.22, 0.789);
	std::cout << time << "2:36:16" << endl;

	std::cout << "Testing operatives: " << endl;
	TimeSpan time2 = -time;
	std::cout << "opposite: " << time << time2 << endl;

	TimeSpan time3 = time + time2;
	std::cout << "adding the two " << time3 << endl;

	time3 = time - time2;
	std::cout << "reducing the two " << time3 << endl;

	if (time3 == time + time)
	{
		std::cout << "equal works" << endl;
	}
	else
	{
		std::cout << "you failed" << endl;
	}

	if (time2 != time)
	{
		std::cout << "not equal works" << endl;
	}
	else {
		std::cout << "you failed" << endl;
	}

	time3 -= time;
	if (time3 == time)
	{
		std::cout << "-= works" << endl;

	}
	else {
		std::cout << "you failed -= " << endl;
	}

	time3 += time;
	if (time3 == time + time) {
		std::cout << "+= works" << endl;
	}
	else {
		std::cout << "you failed += " << endl;
	}


	TimeSpan time4;
	std::cout << "Type in this time -123.45:65.789:0" << endl;
	std::cin >> time4;

	std::cout << "expected output => -122:-21:-13" << endl;
	std::cout << time4 << endl;




}
