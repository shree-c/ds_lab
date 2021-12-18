#include <stdio.h>
#define MAX 3
int fend = -1;
int rend = -1;
int arr[MAX];
void enqueue(int val) {
	if (rend == MAX - 1) {
		printf("queue full!\n");
		return;
	} else {
		if (fend == -1) {
			fend = fend + 1;
			rend = rend + 1;
			arr[fend] = val;
		} else {
			rend = rend + 1;
			arr[rend] = val;
		}
		return;
	}
}
void dequeue() {
	if (rend == -1) {
		printf("queue empty!\n");
		return;
	} else {
		printf("removed %d\n", arr[fend]);
		fend = fend + 1;
		if (fend > rend) {
			fend = rend = -1;
		}
		return;
	}
}
void display() {
	if (fend == -1) {
		printf("queue empty\n");
		return;
	} else {
		printf("begin-->\n");
		for (int i = fend; i <= rend; i++) {
			printf("%d\n", arr[i]);
		}
		printf("end-->\n");
		return;
	}
}
int main() {
	int opt = 0;
	do {
		printf("1. enqueue\n2. dequeue\n3. display\n4. exit\n:: ");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("Enter a value: ");
				int val;
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("byee\n");
				break;
			default:
				printf("invalid option\n");
				break;
		}
	} while (opt != 4);
	return 0;
}
