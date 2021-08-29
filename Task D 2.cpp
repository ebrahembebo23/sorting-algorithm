#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	// call time libirary
#include<time.h>
	// initialization size 
#define size_of_arr 100000
	// declaration a global array
int val[size_of_arr];
	// make function to make random value of array
void rand(int val[]) {
	srand(time(NULL));
	for (int i = 0; i < size_of_arr; i++) {
		val[i] = rand() % 100000 + 1;
	}
}
	// make insertion sort function
void insertion_sort(int* arr, int length) {
	for (int i = 1; i < length; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
		// print time that take of excution
	printf("The array is sorted using insertion sort in %u seconds\n", clock());
}

	// make function to swabed value
void swap(int* x, int* z) {
	int temp = *x;
	*x = *z;
	*z = temp;
}

	// make quick sort function
void quick_sort(int start, int end) {
	if (start >= end)return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && val[i] <= val[key]) i++;
		while (j > start && val[j] >= val[key])j--;
		if (i > j) swap(&val[key], &val[j]);
		else swap(&val[i], &val[j]);
	}
	quick_sort(start, j - 1);
	quick_sort(j + 1, end);
}


int main() {
	int arr[size_of_arr];
	srand(time(NULL));
	for (int i = 0; i < size_of_arr; i++) {
		arr[i] = rand() % 100000 + 1;
	}
	printf("Array of 100,000 random numbers is initialized\n");
	rand(val);
	quick_sort(0, size_of_arr - 1);
	printf("The array is sorted using quick sort in %u seconds\n", clock());
	insertion_sort(arr, size_of_arr);
	return 0;
}
