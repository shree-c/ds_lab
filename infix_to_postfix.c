#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int top = -1;
char arr_stk[MAX];
void push(int val)
{
  if (top == MAX - 1)
  {
    printf("stack full!!\n");
    exit(-1);
  }
  else
  {
    top = top + 1;
    arr_stk[top] = val;
    return;
  }
}

int pop()
{
  if (top == -1)
  {
    printf("stack empty!!\n");
    exit(-1);
  }
  else
  {
    return arr_stk[top--];
  }
}
int isEmpty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}
int returnTop()
{
  if (top == -1)
  {
    printf("return top: stack empty!\n");
    exit(-1);
  }
  else
    return arr_stk[top];
}
int precedence(char focus_element)
{
  switch (focus_element)
  {
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

char *infix_to_postfix(char *exp)
{
  char *ret_array = (char *)malloc(sizeof(char) * 100);
  int ret_arr_pos = -1;
  //stack *stackhol = newStack();
  for (int i = 0; exp[i]; i++)
  {
    //if alphabet output it
    if (isalpha(exp[i]))
      ret_array[++ret_arr_pos] = exp[i];
    //if '(' push it
    else if (exp[i] == '(')
    {
      push(exp[i]);
    }
    // if ')'
    //pop everything until ) and pop it also
    else if (exp[i] == ')')
    {
      while (!isEmpty() && returnTop() != '(')
        ret_array[++ret_arr_pos] = pop();
      pop();
    }
    //if operator
    else
    {
      //pop all operators which are greater than or eq to cur op
      //and then push it
      while (!isEmpty() && precedence(exp[i]) <= precedence(returnTop()))
      {
        ret_array[++ret_arr_pos] = pop();
      }
      push(exp[i]);
    }
  }
  while (!isEmpty())
    ret_array[++ret_arr_pos] = pop();
  ret_array[++ret_arr_pos] = '\0';
  return ret_array;
}

int main()
{
  char hold[100];
  fgets(hold, 100, stdin);
  fputs(infix_to_postfix(hold), stdout);
  return 0;
}
