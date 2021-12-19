#include <stdio.h>
#define MAX 3
int fend = -1;
int rend = -1;
int arr[MAX];
void enqueue_back(int val) {
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
void enqueue_front(int val) {
	if (fend == 0) {
		printf("queue full!\n");
		return;
	} else {
		if (fend == -1) {
			fend = fend + 1;
			rend = rend + 1;
			arr[fend] = val;
		} else {
			fend = fend - 1;
			arr[fend] = val;
		}
		return;
	}
}

void dequeue_front() {
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

void dequeue_back() {
	if (fend == -1) {
		printf("queue empty!\n");
		return;
	} else {
		printf("removed %d\n", arr[rend]);
		rend = rend - 1;
		if (fend < rend) {
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
		printf("1. enqueue_back\n2. enqueue_front\n3. dequeue_front\n4. dequeue_back\n5. display\n6. exit\n:: ");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				{
					printf("Enter a value: ");
					int val;
					scanf("%d", &val);
					enqueue_back(val);
				}
				break;
			case 2:
				{
					printf("Enter a value: ");
					int val;
					scanf("%d", &val);
					enqueue_front(val);
				}
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_back();
				break;
			case 5: 
				display();
				break;
			case 6:
				printf("byee\n");
				break;
			default:
				printf("invalid option\n");
				break;
		}
	} while (opt != 6);
	return 0;
}
