#include "BSTree.h"



BSTree::BSTree()
{
	this->size = 0;
	this->root = NULL;
}


BSTree::~BSTree()
{
	this->Empty();
}

bool BSTree::Insert(Account* input)
{
	Node* temp = new Node; //creating a new node
	temp->value = input;
	temp->key = input->getId();

	if (this->isEmpty()) { //if empty make it the root
		this->root = temp;
		this->size++;
		return true;
	}
	Node* currentNode = this->root;
	while (currentNode != NULL) {
		if (temp->key == currentNode->key) {
			currentNode->value = input;
			return true;
		}
		else if (temp->key < currentNode->key) { //left child is less
			if (currentNode->leftChild == NULL) { //if empty set it
				currentNode->leftChild = temp;
				break;
			}
			else {
				currentNode = currentNode->leftChild;
			}
		}
		else { //right child is more and the only thing left
			if (currentNode->rightChild == NULL) {//if empty set
				currentNode->rightChild = temp;
				break;
			}
			else {
				currentNode = currentNode->rightChild;
			}
		}
	}

	this->size++;
	return true;
}

/*
Account& BSTree::Retrieve(const int key)
{
	Node* currentNode = this->root;
	while (currentNode != NULL) {
		if (currentNode->key == key) {
			cout << *currentNode->value << endl;

			return *(currentNode->value);


		}
		if (currentNode->key > key) {
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = currentNode->rightChild;
		}
	}
	throw "Not found";
}
*/

bool BSTree::Retrieve(const int& key, Account*& output)
{
	Node* currentNode = this->root;
	while (currentNode != NULL) {
		if (currentNode->key == key) {
			cout << *currentNode->value << endl;

			output = currentNode->value;  

			cout << *output << endl;

			return true;
		}
		if (currentNode->key > key) {
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = currentNode->rightChild;
		}
	}
	return false;
}

bool BSTree::Contains(int key)
{
	Node* currentNode = this->root;
	while (currentNode != NULL) {
		if (currentNode->key == key) {
			return true;
		}
		if (currentNode->key > key) {
			currentNode = currentNode->leftChild;
		}
		else {
			currentNode = currentNode->rightChild;
		}
	}
	return false;
}

void BSTree::Display() const
{
	Node* temp = this->root;
	InOrderTraversal(temp);
}

void BSTree::InOrderTraversal(Node* temp) const
{
	if (temp != NULL && size > 0) {
		this->InOrderTraversal(temp->leftChild);
		cout << *temp->value << endl;
		this->InOrderTraversal(temp->rightChild);
	}
}

void BSTree::Empty()
{
	if (root != NULL) {
		destroyer(root);
	}
	return;
}

bool BSTree::isEmpty() const
{
	return (this->size == 0);
}

void BSTree::destroyer(Node* temp)
{
	if (temp != NULL && size >= 1) {
		destroyer(temp->leftChild);
		destroyer(temp->rightChild);
		
		temp->value = NULL;
		delete(temp);
		temp = NULL;
		size--;
	}
	return;
}

int BSTree::getSize()
{
	return this->size;
}



