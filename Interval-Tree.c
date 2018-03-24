#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data, h_range, l_range ;
	struct node* right;
	struct node* left;
}interval ;
interval* create_tree(int,int);
void update_nodes(interval *,int ,int);
int AddRange(interval *, int, int);

main()
{

	int n,x,i,ch,hr,lr,sum;
	char c;
	interval *root;
	root=NULL;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	root=create_tree(0,n-1);
	do
    {
	printf("Enter your choice\n1 Update\n2 Range Query\n");
	scanf("%d",&ch);
	if(ch==1)
    {
        printf("Enter the value to be added\n");
        scanf("%d",&x);
        printf("Enter the index \n");
        scanf("%d",&i);
        if(i<n)
        {
            update_nodes(root,x,i);
        }
    }
    else if(ch==2)
    {
        printf("Enter the smaller index of the range\n");
        scanf("%d",&lr);
        printf("Enter the higher index of the range\n");
        scanf("%d",&hr);
        if(lr<=hr && hr<=root->h_range && lr>=root->l_range)
        {
            sum=AddRange(root,lr,hr);
            printf("Addition Done with sum = %d : ",sum);
        }
        else
            printf("\nWrong Range\n");
    }
    else
        printf("\nWRONG CHOICE\n");
    printf("Do you want to operate more\n");
    fflush(stdin);
    scanf("%c",&c);
}while(c=='y'||c=='Y');
}
interval *create_tree(int start,int end)
{
    int mid;
    interval *p;
    p=(interval *)malloc(sizeof(interval));
    if(end==start)
    {
        p->data=0;
        p->h_range=end;
        p->l_range=start;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    p->data=0;
    p->h_range=end;
    p->l_range=start;
    mid=(start+end)/2;
    p->left=create_tree(start,mid);
    p->right=create_tree(mid+1,end);
    return p;
}

void update_nodes( interval *start, int x , int index)
{
    int mid;
    interval *temp;
    temp=start;

    while( temp!=NULL )
    {
        temp->data=( temp->data )+x;
        mid=( ( ( temp->l_range )+ ( temp->h_range ))/2 );
        if(index>mid)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
}
int AddRange(interval *ptr,int low,int high)
{
    if(ptr->h_range<low || ptr->l_range>high)
        return 0;
    else if(ptr->l_range>=low && ptr->h_range<=high)
        return ptr->data;
    else
        return AddRange(ptr->left,low,high) + AddRange(ptr->right,low,high);
}

