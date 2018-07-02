#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stacknode
{
	int data;
	struct stacknode* next ;
};

struct stacknode* newstack(int data)
{
	struct stacknode* stack = (struct stacknode*) malloc(sizeof(struct stacktnode*));
	stack -> next = NULL;
	stack -> data = data ;
	return stack ;
}

int isemp(struct stacknode* root)
{return !root;}

void push (struct stacknode** root , int data)
{
	struct stacknode* stacknode = newstack(data);
	stacknode -> next = *root;
	*root = stacknode;
}

int pop (struct stacknode** root)
{
	if (isemp(*root))
	{
		return INT_MIN;
	}
	struct stacknode* temp = *root;
	*root = (*root) -> next ;
	return temp -> data;
}

int peek (struct stacknode* root)
{
	if (isemp(root))
	{
		return INT_MIN;
	}
	return root->data;
}

int main()
{
	struct stacknode* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
	return 0 ;
}

