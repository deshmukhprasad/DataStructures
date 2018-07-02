#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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
	int n ;
	printf("Enter the number of elements \n");
	scanf("%d",&n);
	// a = (int) malloc(n*sizeof(int));
	int a[n];
	printf("Enter the elements of array\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	struct stack* stack = createstack(n);
	for (int i = 0; i < n; ++i)
	{
		push(stack , a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = pop(stack);
	}
	printf("The reversed string is \n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i] );
	}
	return 0;
}