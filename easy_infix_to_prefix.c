#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* algorithm:
 * reverse the expression
 * replace '(' with ')' and vice versa
 * call infix to postfix
 * reverse what you get
 * output it
 */
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
char *reverse(char *arr) {
  int len = strlen(arr), j = 0;
  char temparr[len + 1];
  for (int i = len - 1; i >= 0; i--) {
    temparr[j++] = arr[i];
  }
  temparr[j] = 0;
  strcpy(arr, temparr);
  return arr;
}
char* in_po(char *inp_arr) {
	char stack[100];
	int stk_ptr = -1;
	char *retarr = (char *) calloc(100, sizeof(char));
	int retarr_pos = -1;
	for (int i = 0; inp_arr[i]; i++) {
		if (isalpha(inp_arr[i]))
			retarr[++retarr_pos] = inp_arr[i];
		else if (inp_arr[i] == '(')
			stack[++stk_ptr] = inp_arr[i]; //push
		else if (inp_arr[i] == ')') {
			while (stk_ptr >= 0 && stack[stk_ptr] != '(')
				retarr[++retarr_pos] = stack[stk_ptr--]; //pop
			if (stack[stk_ptr] != '(') {
				printf("parenthesis mismatch!\n");
				exit(1);
			} else {
				stk_ptr--; //pop
			}
		} else {
			if (inp_arr[i] == '^') {
				while(stk_ptr >= 0 && pre(stack[stk_ptr]) >= pre(inp_arr[i]))
					retarr[++retarr_pos] = stack[stk_ptr--]; //pop
			}
			while(stk_ptr >= 0 && pre(stack[stk_ptr]) > pre(inp_arr[i]))
				retarr[++retarr_pos] = stack[stk_ptr--]; //pop
			stack[++stk_ptr] = inp_arr[i]; //push
		}
	}
	while (stk_ptr >= 0)
		retarr[++retarr_pos] = stack[stk_ptr--]; //pop
	return retarr;
}
void in_pre(char *arr) {
	reverse(arr);
	for (int i = 0; arr[i]; i++) {
		if (arr[i] == '(')
			arr[i] = ')';
		else if (arr[i] == ')')
			arr[i] = '(';
	}
	char *hold = in_po(arr);
	reverse(hold);
	fputs(hold, stdout);
}
int main() {
	char inp_exp[100];
        while (1) {
          scanf("%s", inp_exp);
          in_pre(inp_exp);
          putchar('\n');
        }
        return 0;
}
