#include "Catalan.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Catalan::Catalan()
{}
Catalan::Catalan(int input) // paramter requires 1 input 
{
	std::cout << this->catalan(input) << endl; //calls recursive function
}

int Catalan::catalan(int input)
{	
	if (input < 0) //invalid value checker
		return 0;
	else if (input == 0) //base case
		return 1;
	else //recursive calls
	{
		int n = input - 1;
		int i = 0;
		int subtotal = 0;
		while (n >= 0) {
			subtotal += this->catalan(i) * this->catalan(n);
			i++;
			n--;
		}
		return subtotal;
	}
}

//just in case you wanna input some stuff 
istream& operator>>(istream& inStream, Catalan& cat)
{
	int input;
	inStream >> input;

	std::cout << "The Catalan for " << input << " is " << cat.catalan(input) << endl;

	return inStream;
}


Catalan::~Catalan()
{
}

int main(int argc, char* argv[]) {
	if (argc > 1)
	{
		std::cout << "The Catalam for " << atoi(argv[1]) << " is " << endl;
		Catalan cat = Catalan(atoi(argv[1]));
	}
	else
	{
		Catalan cat;
		
		std::cout << "please print the number you would like to use: " << endl;
		std::cin >> cat;
	}
	

}