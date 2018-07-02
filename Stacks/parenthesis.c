#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>
struct stack
{
	int top;
	unsigned capacity;
	char* arr;
};

struct stack* createstack(unsigned capacity)
{
	struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
	stack -> top = -1 ;
	stack -> capacity= capacity;
	stack -> arr = (char*) malloc(stack -> capacity*sizeof(char));
	return stack;
}

int isFull (struct stack* stack)
{
	return stack -> top == stack -> capacity - 1 ;
}

int isEmp (struct stack* stack)
{
	return stack -> top == -1 ;
}

void push (struct stack* stack , char item)
{
	if (isFull(stack))
	{
		return ;
	}
	stack -> arr[++stack->top] = item ;
	printf("%c element added to the stack\n", item );
}

char pop (struct stack* stack)
{
	if (isEmp(stack))
	{
		return SCHAR_MIN ;
	}
	return stack->arr[stack->top--];
}



int main()
{
	
	char a[100] , temp;
	int c;
	printf("Enter the string\n");
	gets(a);
	struct stack* stack = createstack(100);
	for (int i = 0; i <= strlen(a); ++i)
	{
		if (a[i] == '{' || a[i]=='[' || a[i] == '(')
		{
			push(stack, a[i]);
		}
		else if (a[i] == '}' || a[i]==']' || a[i] == ')')
		{
			temp = pop(stack);
			if(a[i]==')' && (temp=='{' || temp=='['))
			c = 0;
			if(a[i]=='}' && (temp=='(' || temp=='['))
			c = 0;
			if(a[i]==']' && (temp=='(' || temp=='{'))
			c = 0;
		}
	}
	if (c == 0)
	{
		printf("The string is invalid\n");
	}
	else 
	{
		printf("The string is valid\n");
	}
	return 0 ;
}