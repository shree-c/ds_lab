#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void printarray(int *arr, int max) {
	printf("printing array: [ ");
	for (int i = 0; i < max; i++) {
		printf("%d ", arr[i]);
	}
	printf(" ]\n");
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void nbubble(int *arr, int lo, int hi) {
	int swapped = 0;
	do {
		swapped = 0;
		for (int i = lo; i < hi; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
		}
		hi--;
	} while (swapped);
}
int main() {
	srand(time(0));
	int upper = 100, lower = 0;
	int arr[MAX];
	for (int i = 0; i < MAX; i++) {
		arr[i] = (rand() % (upper - lower + 1)) + lower;
	}
	printarray(arr, MAX);
	nbubble(arr, 0, MAX-1);
	printarray(arr, MAX);
}

