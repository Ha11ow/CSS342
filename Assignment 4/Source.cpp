/*
#include<iostream>
#include<vector>
#include<string>
#include"SortImpls.h"
int main()
{
	vector<int> pool(10);
	for (int i = 0; i < 10; i++) {
		pool[i] = i;
	}
	int spot;
	vector<int> arr(10);
	for (int i = 0; i < 10; i++) {
		spot = rand() % (pool.size());
		arr[i] = pool[spot];
		pool.erase(pool.begin() + spot);
	}

	printArray(arr);
	insertionSort(arr, 0, 9);
	printArray(arr);

	return 0;
}

*/


#include <iostream>
#include <vector>
#include <string>
#include "SortImpls.h"
#include <windows.h>
#include <cstdlib>

using namespace std;
void InitArray(vector<int>&, int);
void PrintArrayDetails(const vector<int>&, string);


int main(int argc, char* argv[])
{
	int size = 0;
	string sort_name = "";
	bool printOut = true;
	if ((argc != 3) && (argc != 4))
	{
		cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
		return -1;
	}
	sort_name = string(argv[1]);
	size = atoi(argv[2]);
	if (size <= 0)
	{
		cerr << "Array size must be positive" << endl;
		return -1;
	}
	if (argc == 4)
	{
		string printArr = string(argv[3]);
		if (printArr == "NO")
		{
			printOut = false;
		}
		else if (printArr == "YES")
		{
			printOut = true;
		}
		else
		{
			cerr << "Usage: Sorter SORT_TYPE ARRAY_SIZE [YES|NO]" << endl;
			return -1;
		}
	}
	srand(1);
	vector<int> items(size);
	InitArray(items, size);
	if (printOut)
	{
		cout << "Initial:" << endl;
		PrintArrayDetails(items, string("items"));
	}

	int begin = GetTickCount();
	if (sort_name == "QuickSort")
	{
		QuickSort(items, 0, size - 1);
	}
	else if (sort_name == "BubbleSort")
	{
		BubbleSort(items, 0, size - 1);
	}
	else if (sort_name == "InsertionSort") {
		InsertionSort(items, 0, size - 1);
	}
	else if (sort_name == "MergeSort") {
		MergeSort(items, 0, size - 1);
	}
	else if (sort_name == "ShellSort") {
		ShellSort(items, 0, size - 1);
	}
	else if (sort_name == "IterativeMergeSort") {
		IterativeMergeSort(items, 0, size - 1);
	}
	else {
		cerr << "USAGE: Invalid Sort Type" << endl;
		return -1;
	}
	int end = GetTickCount();

	if (printOut)
	{
		cout << "Sorted:" << endl;
		PrintArrayDetails(items, string("item"));
	}
	int elapsed_secs = end - begin;
	cout << "Time (ms): " << elapsed_secs << endl;
	return 0;
}
void InitArray(vector<int> & array, int randMax)
{
	
	if (randMax < 0)
	{
		return;
	}
	vector<int> pool(randMax);
	for (int i = 0; i < randMax; i++)
	{
		pool[i] = i;
	}
	int spot;
	for (int i = 0; i < randMax; i++)
	{
		spot = rand() % (pool.size());
		array[i] = pool[spot];
		pool.erase(pool.begin() + spot);
	}
	/*				//custom and faster way to fill arrays (allows for repetitions)
	for (int i = 0; i < randMax; i++) {
		int temp = rand() % randMax;
		array[i] = temp;
	}
	*/
}
void PrintArrayDetails(const vector<int> & array, string name)
{
	int size = array.size();
	for (int i = 0; i < size; i++)
		cout << name << "[" << i << "] = " << array[i] << endl;
}