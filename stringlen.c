#include <stdio.h>
#define MAX 1000

int str_len(char *str) {
	int len = 0;
	while (*str) {
		str++;
		len++;
	}
	return len;
}

int main() {
	printf("enter a string: ");
	char str[MAX];
	fgets(str, MAX, stdin);
	int length = str_len(str);
	printf("string length is : %d\n", length - 1);
	return 0;
}
