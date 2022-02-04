#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int top = -1;
char arr_stk[MAX];
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
void push(int val) {
  if (top == MAX - 1) {
    printf("stack full!!\n");
    exit(-1);
  } else {
    top = top + 1;
    arr_stk[top] = val;
    return;
  }
}

int pop() {
  if (top == -1) {
    printf("stack empty!!\n");
    exit(-1);
  } else {
    return arr_stk[top--];
  }
}
int isEmpty() {
  if (top == -1)
    return 1;
  else
    return 0;
}
int returnTop() {
  if (top == -1) {
    printf("return top: stack empty!\n");
    exit(-1);
  } else
    return arr_stk[top];
}
int precedence(char focus_element) {
  switch (focus_element) {
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 1;
  case '^':
    return 3;
  }
  return -1;
}

char *infix_to_postfix(char *exp) {
  char *ret_array = (char *)malloc(sizeof(char) * 100);
  int ret_arr_pos = -1;
  // stack *stackhol = newStack();
  for (int i = 0; exp[i]; i++) {
    // if alphabet output it
    if (isalpha(exp[i]))
      ret_array[++ret_arr_pos] = exp[i];
    // if '(' push it
    else if (exp[i] == '(') {
      push(exp[i]);
    }
    // if ')'
    // pop everything until ( and pop it also
    else if (exp[i] == ')') {
      while (!isEmpty() && returnTop() != '(')
        ret_array[++ret_arr_pos] = pop();
      pop();
    }
    // if operator
    else {
      // pop all operators which are greater than or eq to cur op
      // and then push it
      if (exp[i] == '^') {
        while (!isEmpty() && precedence(exp[i]) <= precedence(returnTop())) {
          ret_array[++ret_arr_pos] = pop();
        }
      } else {
        while (!isEmpty() && precedence(exp[i]) < precedence(returnTop())) {
          ret_array[++ret_arr_pos] = pop();
        }
      }
      push(exp[i]);
    }
  }
  while (!isEmpty())
    ret_array[++ret_arr_pos] = pop();
  ret_array[++ret_arr_pos] = '\0';
  return ret_array;
}

char *infix_to_prefix(char *exp) {
  reverse(exp);
  for (int i = 0; exp[i]; i++) {
    if (exp[i] == '(')
      exp[i] = ')';
    else if (exp[i] == ')')
      exp[i] = '(';
  }
  return reverse(infix_to_postfix(exp));
}
int main() {
  char hold[100];
  printf("Enter infix expression: ");
  scanf("%s", hold);
  printf("the prifix expression is: ");
  fputs(infix_to_prefix(hold), stdout);
  return 0;
}
