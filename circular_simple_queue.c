#include <stdio.h>
#define MAX 3
int fend = -1;
int rend = -1;
int arr[MAX];
void enqueue(int val) {
	if ((rend + 1) % MAX == fend) {
		printf("queue full\n");
		return;
	}
	if (rend == -1 && fend == -1) {
		fend = rend = 0;
		arr[rend] = val;
		return;
	}
	rend = (rend + 1) % MAX;
	arr[rend] = val;
	return;
}
void dequeue() {
	if (fend == -1) {
		printf("queue empty\n");
		return;
	}
	printf("removed %d\n", arr[fend]);
	if (fend == rend) {
		fend = rend = -1;
		return;
	}
	fend = (fend + 1) % MAX;
	return;
}
void display() {
	if (fend == -1) {
		printf("queuen empty\n");
		return;
	}
	printf("begin-->\n");
	int i = fend;
	for (; i != rend; i = (i + 1) % MAX) {
		printf("%d->%d\n", arr[i], i);
	}
	printf("%d->%d\n", arr[i], i);
	printf("end-->\n");
	return;
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
