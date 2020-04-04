#include "List342.h"
using namespace std;
/*

template<class T>
List342<T>::List342()
{
	head = NULL;
}

template<class T>
List342<T>::List342(const List342& other)
{
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

template<class T>
bool List342<T>::BuildList(string fileName)
{
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


template<class T>
bool List342<T>::Insert(T* data)
{
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
		if (*(temp->value) != *data) {
			insNode->next = temp->next;
			temp->next = insNode;
			return true;
		}
		return false;
	}
}

template<class T>
bool List342<T>::Remove(T target, T& result)
{
	Node* rmvNode;
	if (head == NULL) {
		return false;
	}
	else if (*(head->value) == target) {
		rmvNode = head;
		head = head->next;
		result = *rmvNode->value; //might leak
		delete rmvNode;
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
			result = *(rmvNode->value); //might leak
			temp->next = (temp->next)->next;
			delete rmvNode;
			rmvNode = NULL;
			return true;
		}
	}
}

template<class T>
bool List342<T>::Peek(T target, T& result)
{
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

template<class T>
bool List342<T>::isEmpty() const
{
	if (head == NULL) {
		return true;
	}
	return false;
}

template<class T>
void List342<T>::DeleteList()
{

	if (head != NULL) {
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






template<class T>
bool List342<T>::Merge(List342& other)
{
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
		if (*(head->value) > *(other.head->value)) {
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
		else {
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
				other.head = other.head-> next;
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
			if (*(head1->next->value) > *(other.head->value)) {
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
			else {
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

template<class T>
List342<T> List342<T>::operator+(const List342& other) const
{
	List342 temp1 = *this;
	List342 temp2 = other;
	temp1.Merge(temp2);
	return temp1;
}

template<class T>
bool List342<T>::operator==(const List342& other) const
{
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

template<class T>
bool List342<T>::operator!=(const List342& other) const
{
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


template<class T>
List342<T>& List342<T>::operator+=(const List342 other) //ask teacher if this is okay to keep
{
	List342<T> temp = other;
	this->Merge(temp);
	return *this;
}



template<class T>
List342<T>& List342<T>::operator=(const List342& other)
{
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

template<class T>
List342<T>::~List342()
{
	DeleteList();
}


/*
int main() {
	/*
	while (true) {
		List342 test = List342();
		test.insert(1);
		test.insert(2);
		test.insert(3);

		List342 test2 = List342();
		test2.insert(1);
		test2.insert(5);
		test2.insert(6);
		int temp;
		test.Remove(2,temp);
		 
		List342 test3 = List342();
		test3 = test2;
		test.Merge(test3);

		test.DeleteList();
		test2.DeleteList();
		test3.DeleteList()

	}
	
	
	List342<int> test = List342<int>();
	int a = 1;
	int b = 3;
	int c = 5;
	test.insert(&a);
	test.insert(&b);
	test.insert(&c);

	int d;
	test.Remove(b, d);

	cout << test << endl;

	List342<int> test2 = List342<int>();

	int e = 4;
	int f = 4;
	test2.insert(&e);
	test2.insert(&f);

	cout << test2 << endl;
	test.Merge(test2);

	test.Merge(test);

	cout << test << endl;

	
	List342<int> test3 = List342<int>();
	test3.insert(1);
	test3.insert(3);
	test3.insert(5);

	List342<int> test4 = List342<int>();

	
	std::cout << "test = " <<  test << endl;
	
	std::cout << "test 2 = " << test2 << endl;
	std::cout << "test 4 = " << test4 << endl;

	


	cout << "\n\ntesting +=: " << endl;
	test3 += test2;
	cout << "test 3 = " << test3 << endl;


	cout << "\n\ntesting merge" << endl;

	
	test.Merge(test2);


	test4 = test;

	std::cout << "test = " << test << endl;
	std::cout << "test 2 = " << test2 << endl;
	std::cout << "test 4 = " << test4 << endl;

	if (test == test4) {
		cout << "Nice they are equal!" << endl;
	}
	else {
		cout << "You done goofed, they arenet equal!" << endl;
	}
	int tar = 0;
	test.Remove(4, tar);
	std::cout << "test = " << test << "\nRemoved: " << tar << endl;
	std::cout << "test 4 = " << test4 << endl;

	if (test != test4) {
		cout << "nice they arent equal " << endl;
	}
	else {
		cout << "they are equal and you fucked != " << endl;
	}

	cout << "\n\n testing + " << endl;
	List342<int> test5 = List342<int>();
	test5.insert(12);
	test5.insert(10);

	cout << "test 3 before = " << test3 << endl;
	test3 = test4 + test5;

	cout << "test 3 = " << test3 << endl;
	
}
*/

/*
int main() {
	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
		c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),
		c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;

	List342<Child> class1, class2, soccer, chess;
	int a = 1, b = -1, c = 13;
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class1.Insert(&c4);
	class1.Insert(&c5);
	class1.Insert(&c6);
	class1.Insert(&c5);

	//class2 = class1;
	cout << class1 << "        " << class2 << endl;



	cout << "class1: " << class1 << endl;

	if (class1.Insert(&c1))
	{
		cout << "ERROR::: Duplicate" << endl;
	}
	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	class2.Insert(&c10);
	cout << "Class2: " << class2 << endl;
	class1.Merge(class2);
	class2.Merge(class1);
	class1.Merge(class2);
	class1.Merge(class1);
	cout << "class1 and 2 Merged: " << class1 << endl;
	if (!class2.isEmpty())
	{
		cout << "ERROR:: Class2 should be empty empty" << endl;
	}


	class1.Remove(c4, c11);
	class1.Remove(c5, c11);
	class1.Remove(c11, c11);
	if (class1.Remove(c1, c11))
	{
		cout << "Removed from class1, student " << c11 << endl;
	}
	cout << "class1: " << class1 << endl;
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	cout << "soccer: " << soccer << endl;
	soccer += class1;
	cout << "soccer += class1 : " << soccer << endl;
	List342<Child> football = soccer;
	if (football == soccer)
	{
		cout << "football: " << football << endl;
	}
	if (football.Peek(c6, c11))
	{
		cout << c11 << " is on the football team" << endl;
	}
	soccer.DeleteList();
	if (!soccer.isEmpty())
	{
		cout << "ERROR: soccer should be empty" << endl;
	}
	List342<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: " << numbers << endl;
	numbers.DeleteList();
	return 0;

}
*/

