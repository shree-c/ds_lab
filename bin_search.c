#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int bin_search_rec(int *arr, int start, int end, int item) {
	if (start < end) {
		int mid = (start + end)/2;
		printf("%d\n", mid);
		if (item == arr[mid])
			return mid;
		else if (item < arr[mid]) {
			printf("called with %d %d\n", start, mid - 1);
			return bin_search_rec(arr, start, mid - 1, item);
		}
		else {
			printf("called with %d %d\n", mid + 1, end);
			return bin_search_rec(arr, mid + 1, end, item);
		}
	}
	return -1;
}

int main() {
  int arr[MAX];
  printf("enter array size: ");
  int siz;
  scanf("%d", &siz);
  for (int i = 0; i < siz; i++) {
    printf("enter element %d->", i);
    scanf("%d", &arr[i]);
  }
  printf("Enter the item you want to search: ");
  int item;
  scanf("%d", &item);
  int pos = bin_search_rec(arr, 0, siz - 1, item);
  if (pos != -1)
    printf("%d item found at %d position.\n", item, pos);
  else
	  printf("unsuccessful search\n");
  return 0;
}
