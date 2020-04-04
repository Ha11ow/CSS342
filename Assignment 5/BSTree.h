#pragma once
#include "Account.h"

class BSTree
{

	private:
	struct Node {
		int key;
		Account* value;
		Node* leftChild = NULL;
		Node* rightChild = NULL;
		bool isLeaf() {
			if (this->leftChild == NULL && this->rightChild == NULL) {
				return true;		
			}
			return false;
		}
	};
	
	int size;
	Node* root;

public:
	BSTree();
	~BSTree();
	
	bool Insert(Account* input);


	bool Retrieve(const int& key, Account*& output);

	//Account& Retrieve(const int key);


	bool Contains(int key);
	void Display() const;
	void InOrderTraversal(Node* temp) const;
	void Empty();
	bool isEmpty() const;
	void destroyer(Node* temp);
	int getSize();
};


/*
int main() {

	try {
		Account mAc = Account("ahmad", "hamed", 1111);
		Account mAc2 = Account("boo", "bee", 1234);
		Account mAc3 = Account("Ball", "Sack", 4321);

		BSTree myT = BSTree();
		myT.Insert(&mAc);
		myT.Insert(&mAc2);
		myT.Insert(&mAc3);


		cout << myT.getSize() << " SIZE " << endl;

		Account Max = myT.Retrieve(1111);
		cout << Max << endl;

		Max.deposit(0, 100);
		Max.deposit(0, 100);
		cout << Max << endl;


		//myT.Display();

	}
	
	*

	

	try {
		Account mAc = Account("ahmad", "hamed", 1111);
		Account mAc2 = Account("boo", "bee", 1234);
		Account mAc3 = Account("Ball", "Sack", 4321);

		BSTree myT = BSTree();
		myT.Insert(&mAc);
		myT.Insert(&mAc2);
		myT.Insert(&mAc3);

		cout << myT.getSize() << " SIZE " << endl;


		Account* Max = NULL;
		myT.Retrieve(1111, Max);
		cout << *Max << endl;

		Max->deposit(0, 100);

		cout << Max->getFirstName();

		myT.Display();


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

*/