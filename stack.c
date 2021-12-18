#include <stdio.h>
#define MAX 5
int top = -1;
int arr[MAX];
void push(int val) {
	if (top == MAX - 1) {
		printf("stack full!!\n");
		return;
	} else {
		top = top + 1;
		arr[top] = val;
		return;
	}
}

void pop() {
	if (top == -1) {
		printf("stack empty!!\n");
		return;
	} else {
		printf("popped %d\n", arr[top]);
		top = top - 1;
		return;
	}
}
void display() {
	if (top == -1) {
		printf("stack empty!!\n");
		return;
	} else {
		printf("begin-->\n");
		for(int i = top; i >= 0; i--) {
			printf("%d\n", arr[i]);
		}
		printf("end-->\n");
		return;
	}
}

int main() {
	int opt = 0;
	do {
		printf("1. push\n2. pop\n3. display\n4. exit\n:: ");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("Enter a value: ");
				int val;
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				pop();
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
