#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
struct stack
{
	int top;
	unsigned capacity;
	int* arr;
};

struct stack* createstack(unsigned capacity)
{
	struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
	stack -> top = -1 ;
	stack -> capacity= capacity;
	stack -> arr = (int*) malloc(stack -> capacity*sizeof(int));
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

void push (struct stack* stack , int item)
{
	if (isFull(stack))
	{
		return ;
	}
	stack -> arr[++stack->top] = item ;
	printf("%d element added to the stack\n", item );
}

int pop (struct stack* stack)
{
	if (isEmp(stack))
	{
		return INT_MIN ;
	}
	return stack->arr[stack->top--];
}

int main()
{
	struct stack* stack = createstack(100);
	push(stack, 200);
	push(stack, 100);
	push(stack, 1000);
	printf("%d popped from stack\n", pop(stack));
	pop(stack);
	return 0;
}