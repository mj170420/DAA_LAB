#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data ;
    struct node *next ;
}node ;
node *start;
void insert(int n)
{
    node *q, *t;
    if(start==NULL)
    {
        start=(node *)malloc(sizeof(node));
        start->data= n ;
        start->next=NULL;
    }

    else
    {
        q= start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        t=(node *)malloc(sizeof(node));
        t->data=n;
        t->next=NULL ;
        q->next=t;
    }
}
int checkloop()
{
    node *sl, *ft;
    sl=start;
    ft=start;
    while(sl->next!=NULL)
    {
        sl=sl->next;
        while(ft->next!=NULL)
        {
            ft=ft->next->next;
            if(ft==sl){
                printf("Loop Exist");
                return 1 ;
            }

        }
    }
    printf("NO LOOP");
    return 0 ;
}
main()
{
    insert(10);
    insert(25);
    insert(30);
    insert(32);
    insert(36);
    insert(38);
    insert(70);
    node *p ;
    p=start ;
    while(p->next!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }

    checkloop();
}
