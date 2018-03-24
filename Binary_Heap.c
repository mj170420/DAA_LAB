#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int compare(int *, int, int, int);
int delete(int *, int);
void adjust(int *, int , int);
void main()
{
	int n, k, x, result, i;
	
	printf("Enter the size of heap\n");
	scanf("%d", &n);
	int *heap;
	heap = (int *)malloc((n+1)*(sizeof(int))); 
	for(i =1;i<=n;i++)
	{
		printf("Enter %dth Element", i);
		scanf("%d",&heap[i]);
	}
	printf("Enter the position of kth largest element");
	scanf("%d", &k);
	
	printf("Enter the value of x");
	scanf("%d", &x);
	
	result = compare(heap, k, x, n);
	
	result?printf("Larger"):printf("Smaller");
	
	getch();	
}
int compare( int *p, int pos, int compvar, int size)
{
	int a, i;
	for(i=0;i<pos;i++)
	{
		a=delete(p, size);
		size--;
		
	}
	return a>compvar;
}
int delete(int *h, int size)
{
	int root;
	root = h[1];
	h[1]=h[size-1];
	adjust(h, size-1, 1);
	return root ;
}
void adjust(int *hp, int size , int i )
{
	int a, temp =0 , item, j;
	a=2*i;
	item = hp[i];
	while(j!=temp && j<=size)
	{
		temp = j ;
		if(hp[j]>hp[j+1] && hp[j]>item)
		{
			hp[i]=hp[j+1];
			i=j;
		}
		else
		if(item < hp[j+1])
		{
			hp[i]=hp[j+1];
			i=j+1;
		}
		j=2*i;
	}
	hp[i]=item;
}
