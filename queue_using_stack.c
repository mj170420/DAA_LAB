#include<stdio.h>
#include<stdlib.h>
#define maxstk 5
//for pointing the TOP element
static int top=0 ;
//for inserting the element to TOP Location
void push(int*, int);
//for removing the element to TOP Location
int pop(int*);

int popnew(int*);

int main()
{
	int* pushstk;
	int* popstk;
	int popped, n, i, ch, index;
	pushstk=(int*)malloc(maxstk*(sizeof(int)));
	popstk=(int*)malloc(maxstk*(sizeof(int)));
	while(1)
	{
	printf("Enter Your Choice\n1. Insertion 2. Deletion");
	scanf("%d", &ch);

	switch(ch)
	{
	case 1:
	    fflush(stdin);
	for(i=0;i<maxstk;i++)
	{
		printf("Enter the number u want to insert into queue");
		scanf("%d", &n);
		push(pushstk, n);
	}
	top --;
		for(i=maxstk-1;i>=0;i--)
	{
		popstk[i]=pop(pushstk);
	}
	for(i=0;i<maxstk;i++)
	printf("%d\n", popstk[i]);
	break ;
	case 2:
		printf("The Deleted element is:\n");
		popped=popnew(popstk);
		printf("%d\n", popped);
        break;
	default: printf("Wrong Choice Entered\n");
	break ;
	}
}
	return 0;
}
void push(int* stack, int element)
{
	if(top>maxstk-1)
	{
	printf("Overflow\n");
	top--;
	return ;
	}
	else
	{
		stack[top]=element;
		top++;
		printf("Insertion Sucessful !!\n");
	}
}

int pop(int* stack)
{
	int poppedItem ;
	if(top<0)
	{
		printf("UnderFlow\n");
		return ;
	}
	else
	{
		poppedItem=stack[top];
		top-- ;
	}
	return poppedItem;
}

int popnew(int* stack)
{
	int poppedItem ;
	top=0;
	if(top>maxstk-1)
	{
		printf("UnderFlow\n");
		return ;
	}
	else
	{
		poppedItem=stack[top];
		top-- ;
	}
	return poppedItem;
}
