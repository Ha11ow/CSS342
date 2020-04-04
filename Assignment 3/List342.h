#pragma once
#include <string>
#include <ostream>
#include <iostream>
#include "Child.h"
#include <fstream>
using namespace std;
template<class T>
class List342
{
private:
	struct Node { //inner struct with pointer to val and pointer to next Node
		T* value;
		Node* next = NULL;
	};
	Node* head;


public:
	List342() {
		head = NULL; //initilized head
	}

	List342(const List342& other) { //copy constructor basically adds values 
		head = NULL;
		if (other.head == NULL) {
			return;
		}
		Node* temp = other.head;
		while (temp != NULL) {
			this->Insert(temp->value);
			temp = temp->next;
		}
	}

	bool BuildList(string fileName) {
		ifstream inFile;

		inFile.open(fileName);
		if (inFile.is_open()) {
			while (!inFile.eof()) {
				T item;
				inFile >> item;
				this->Insert(&item);
			}
			inFile.close();
		}
		else {
			cout << "File: " << fileName << " not found" << endl;
			return false;
		}
		return true;
	}

	bool Insert(T* data) {
		Node* insNode;
		insNode = new Node;
		insNode->value = new T(*data);
		if (head == NULL) {
			head = insNode;
			return true;
		}
		else if (*data < *head->value) {
			insNode->next = head;
			head = insNode;
			return true;
		}
		else {
			Node* temp = head;
			while ((temp->next != NULL) && (*(temp->next->value) <= *data)) {
				temp = temp->next;
			}
			if (*(temp->value) != *data) { //stoping reused values
				insNode->next = temp->next;
				temp->next = insNode;
				return true;
			}
			return false;
		}
	}

	bool Remove(T target, T& result) {
		Node* rmvNode;
		if (head == NULL) {
			return false;
		}
		else if (*(head->value) == target) { //removes head
			rmvNode = head;
			head = head->next;
			result = *rmvNode->value; 
			delete rmvNode->value; //value ptr deleted
			rmvNode->value = NULL;
			delete rmvNode; //node ptr deleted
			rmvNode = NULL;
			std::cout << "\n\n " << result << "/n/n" << endl;
			return true;
		}
		else {
			Node* temp = head;
			while ((temp->next != NULL) && (*(temp->next->value) != target)) {
				temp = temp->next;
			}
			if (temp->next == NULL) {
				return false;
			}
			else {
				rmvNode = temp->next;
				result = *(rmvNode->value);
				temp->next = (temp->next)->next;
				delete rmvNode->value;
				rmvNode->value = NULL;
				delete rmvNode;
				rmvNode = NULL;
				return true;
			}
		}
	}

	bool Peek(T target, T& result) { //basically remove without leak concern
		if (head == NULL) {
			return false;
		}
		else if (*(head->value) == target) {
			result = *(head->value);
			return true;
		}
		else {
			Node* temp = head;
			while ((temp->next != NULL) && (*(temp->next->value) != target)) {
				temp = temp->next;
			}
			if (temp->next == NULL) {
				return false;
			}
			else {
				result = *(temp->next->value);
				return true;
			}
		}
	}

	bool isEmpty() const {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	void DeleteList() {

		if (head != NULL) { //deletes head till theres none
			Node* temp;
			while (head != NULL) {
				temp = head;
				delete temp->value;
				temp->value = NULL;
				head = head->next;
				delete temp;
				temp = NULL;
			}
		}
	}
	
	bool Merge(List342& other) { //good luck figuring this out, I was high on preworkout
		if (*this == other) {
			return true;
		}
		if (other.head == NULL) {
			return true;
		}
		if (head == NULL) {
			head = other.head;
			other.head = NULL;
			return true;
		}
		else {
			if (*(head->value) > * (other.head->value)) {
				Node* temp = head;
				head = other.head;
				other.head = other.head->next;
				head->next = temp;
			}
			else if (*(head->value) == *(other.head->value)) {
				Node* temp = other.head;
				other.head = other.head->next;
				delete temp;
				temp = NULL;
			}
			else { //if it has to go after the head, travese to right location
				Node* traverse = head;
				while ((traverse->next != NULL) && (*((traverse->next)->value) <= *(other.head->value))) {
					traverse = traverse->next;
				}
				if (*(traverse->value) != *(other.head->value)) {
					Node* temp = other.head;
					other.head = other.head->next;
					temp->next = traverse->next;
					traverse->next = temp;
				}
				else {
					Node* temp = other.head;
					other.head = other.head->next;
					delete temp;
					temp = NULL;
				}
			}
		}
		Node* head1 = head;
		while (other.isEmpty() != true) {
			if (head1 == NULL) {
				head1 = other.head;
				other.head = NULL;
				return true;
			}
			else {
				if (*(head1->next->value) > * (other.head->value)) {
					Node* temp = head1->next;
					head1->next = other.head;
					other.head = other.head->next;
					head1->next->next = temp;
				}
				else if (*(head1->next->value) == *(other.head->value)) {
					Node* temp = other.head;
					other.head = other.head->next;
					delete temp;
					temp = NULL;
				}
				else {//.next.next because this compares two values ahead to edit the next value
					while ((head1->next->next != NULL) && (*(head1->next->next->value) <= *(other.head->value))) {
						head1 = head1->next;
					}
					if (*(head1->next->value) != *(other.head->value)) {
						Node* temp = other.head;
						other.head = other.head->next;
						temp->next = head1->next->next;
						head1->next->next = temp;
					}
					else {
						Node* temp = other.head;
						other.head = other.head->next;
						delete temp;
						temp = NULL;
					}
				}
			}

		}

		return true;
	}


	friend ostream& operator<<(ostream& outStream, const List342& stack)
	{
		List342::Node* temp;
		temp = stack.head;
		while (temp != nullptr) {

			T crap = *temp->value;
			outStream << crap;
			temp = temp->next;
		}
		return outStream;
	}



	List342 operator + (const List342& other) const {
		List342 temp1 = *this;
		List342 temp2 = other;
		temp1.Merge(temp2);
		return temp1;
	}

	bool operator == (const List342& other) const {
		Node* head1 = head;
		Node* head2 = other.head;
		while (head1 != NULL && head2 != NULL) {
			if (*(head1->value) == *(head2->value)) {
				head1 = head1->next;
				head2 = head2->next;
			}
			else {
				break;
			}
		}
		if (head1 != NULL && head2 != NULL) {
			if (*(head1->value) == *(head2->value)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (head1 == NULL && head2 == NULL) {
				return true;
			}
			else return false;
		}
	}

	bool operator != (const List342& other) const { //oposite of ==
		Node* head1 = head;
		Node* head2 = other.head;
		while (head1 != NULL && head2 != NULL) {
			if (*(head1->value) == *(head2->value)) {
				head1 = head1->next;
				head2 = head2->next;
			}
			else {
				return true;
			}
		}
		if (head1 != NULL && head2 != NULL) {
			if (*(head1->value) == *(head2->value)) {
				return false;
			}
			else return true;
		}
		else {
			if (head1 == NULL && head2 == NULL) {
				return false;
			}
			else return true;
		}
	}

	List342& operator+=(const List342 other) {
		List342<T> temp = other;
		this->Merge(temp);
		return *this;
	}

	List342& operator = (const List342& other) {
		if (other.head != NULL) {
			this->DeleteList();
			head = new Node;
			*(head->value) = *(other.head->value);

			Node* head1 = head;
			Node* head2 = other.head->next;

			while (head2 != NULL) { //copy all nodes from other to the next value of head1
				Node* temp = new Node;
				*(temp->value) = *(head2->value);
				head1->next = temp;
				head1 = head1->next;
				head2 = head2->next;
			}
			return *this;
		}
		else { //when other is empty
			this->DeleteList();
			head = NULL;
			return *this;
		}
	}

	~List342() {
		DeleteList();
	}
}
;


