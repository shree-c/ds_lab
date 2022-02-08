#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int pre(int op) {
	switch(op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
	return -1;
}

void in_po(char *inp_arr) {
	char stack[100];
	int stk_ptr = -1;
	for (int i = 0; inp_arr[i]; i++) {
		if (isalpha(inp_arr[i]))
			putchar(inp_arr[i]);
		else if (inp_arr[i] == '(')
			stack[++stk_ptr] = inp_arr[i]; //push
		else if (inp_arr[i] == ')') {
			while (stk_ptr >= 0 && stack[stk_ptr] != '(')
				putchar(stack[stk_ptr--]); //pop
			if (stack[stk_ptr] != '(') {
				printf("parenthesis mismatch!\n");
				exit(1);
			} else {
				stk_ptr--; //pop
			}
		} else {
			while(stk_ptr >= 0 && pre(stack[stk_ptr]) >= pre(inp_arr[i]))
				putchar(stack[stk_ptr--]);
			stack[++stk_ptr] = inp_arr[i]; //push
		}
	}
	while (stk_ptr >= 0)
		putchar(stack[stk_ptr--]);
}

int main() {
	char inp_exp[100];
        while (1) {
          scanf("%s", inp_exp);
          in_po(inp_exp);
          putchar('\n');
        }
        return 0;
}
