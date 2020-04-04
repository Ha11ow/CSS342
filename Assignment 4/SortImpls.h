#pragma once

#include<vector>
#include<string>
#include<iostream>
using namespace std;

void swap(int* start, int* second) {
	int temp = *start;
	*start = *second;
	*second = temp;
}

void BubbleSort(vector<int>& array, int start, int end) {
	for (int i = 0; i < end; i++) {
		for (int j = 0; j < end - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void InsertionSort(vector<int> & array, int start, int end) {
	for (int i = 1; i <= end; i++) {
		int j = i - 1;
		int temp = array[i];
		while ((j >= 0) && (array[j] > temp)) {
			array[j+1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}

void QuickSort(vector<int>& array, int start, int end)
{
	if (end - start < 6) {
		InsertionSort(array, start, end);
		return; 
	}

	int mid = (start + end) / 2;
	if (array[start] > array[end]) {
		swap(array[start], array[end]);
	}
	if (array[start] > array[mid]) {
		swap(array[start], array[mid]);
	}
	if (array[mid] > array[end]) {
		swap(array[mid], array[end]);
	}

	int pivot = array[mid];
	swap(array[mid], array[end - 1]);
	int left = start + 1;
	int right = end - 2;
	bool done = false;
	while (!done) {
		while (array[left] < pivot) {
			left++;
		}
		while (array[right] > pivot) {
			right--;
		}
		if (right > left) {
			swap(array[left], array[right]);
			left++;
			right--;
		}
		else {
			done = true;
		}
	}

	swap(array[left], array[end - 1]);
	QuickSort(array, start, left - 1);
	QuickSort(array, left + 1, end);
}

void ShellSort(vector<int> & array, int start, int end)
{
	int j, temp;
	for (int gap = end / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < end + 1; i += 1)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
	}
}

void Merger(vector<int>& array, int start, int mid, int end) {
	int* tempArr;
	int size = end - start + 1;
	tempArr = new int[size];
	int start1 = start;
	int start2 = mid + 1;
	int end1 = mid;
	int end2 = end;
	int index = 0;

	while ((start1 <= end1) && (start2 <= end2)) {
		if (array[start1] < array[start2]) {
			tempArr[index] = array[start1];
			start1++;
		}
		else {
			tempArr[index] = array[start2];
			start2++;
		}
		index++;
	}
	while (start1 <= end1) {
		tempArr[index] = array[start1];
		start1++;
		index++;
	}
	while (start2 <= end2) {
		tempArr[index] = array[start2];
		start2++;
		index++;
	}
	for (index = 0; index < size; index++) {
		array[start] = tempArr[index];
		start++;
	}
	delete[] tempArr;
}

void MergeSort(vector<int>& array, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);
		Merger(array, start, mid, end);
	}
}

int min(int x, int y) { return (x < y) ? x : y; }

void IterativeMerger(vector<int>& array, int*& array2, int start, int mid, int end){

	int size = end - start + 1;
	int start1 = start;
	int start2 = mid + 1;
	int end1 = mid;
	int end2 = end;
	int index = 0;

	while ((start1 <= end1) && (start2 <= end2)) {
		if (array[start1] < array[start2]) {
			array2[index] = array[start1];
			start1++;
		}
		else {
			array2[index] = array[start2];
			start2++;
		}
		index++;
	}
	while (start1 <= end1) {
		array2[index] = array[start1];
		start1++;
		index++;
	}
	while (start2 <= end2) {
		array2[index] = array[start2];
		start2++;
		index++;
	}
	for (index = 0; index < size; index++) {
		array[start] = array2[index];
		start++;
	}
}

void IterativeMergeSort(vector<int>& array, int start, int end) {
	int currentSize;
	int LS;
	int* tempArray = new int[end + 1];
	for (currentSize = 1; currentSize <= end; currentSize = 2 * currentSize) {
		for (LS = 0; LS < end; LS += 2 * currentSize) {
			int mid = min(LS + currentSize - 1, end);
			int RE = min(LS + 2 * currentSize - 1, end);
			IterativeMerger(array, tempArray, LS, mid, RE);
		}
	}
}


void printArray(const vector<int>& array)
{
	int size = array.size();
	for (int i = 0; i < size; i++) {
		std::cout << array[i];
	}
	std::cout << endl;
}





