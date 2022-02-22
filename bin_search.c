#include <stdio.h>
#include <stdlib.h>

int b_s(int *arr, int lo, int hi, int ele) {
    if (lo <= hi) {
        int mid = (lo + hi)/2;
        if (arr[mid] == ele) {
            return mid;
        } else if (ele < arr[mid])
            return b_s(arr, lo, mid - 1, ele);
        else
            return b_s(arr, mid + 1, hi, ele);
    }
    return -1;
}

int i_bs(int *arr, int lo, int hi, int ele) {
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (arr[mid] == ele)
            return mid;
        else if (arr[mid] > ele) {
            hi = mid - 1;
        } else
            lo = mid + 1;
    }
    return -1;
}

int main() {
    int *arr, n;
    printf("number of items: ");
    scanf("%d", &n);
    arr = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("--->\n");
    int item;
    scanf("%d", &item);
    printf("%d\n", i_bs(arr, 0, n - 1, item));
    return 0;
}

