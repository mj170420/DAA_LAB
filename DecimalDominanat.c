#include<stdio.h>
void main()
{
    int num,count[10]={0,0,0,0,0,0,0,0,0,0},decdom[10],i,c,j,n;
    int *array;
    printf("Enter the number of elements");
    scanf("%d", &n);

    array=(int *)malloc(n*sizeof(int));

     printf("Enter the elements in the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);

        decdom[0]=array[0];
    count[0]=1;

     for(i=1;i<n;i++)
    {
        for(j=0;j<10,j<=i;j++)
        {
            if(decdom[j]==array[i])
            {
                count[j]++;
                break;
            }
            else if(i%10==0)
                count[j]--;
            if(count[j]==0&&num!=decdom[j])
            {
                decdom[j]=array[i];
                count[j]=1;
                break;
            }
        }
    }

    for(j=0;j<10;j++)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            if(decdom[j]==array[i])
            c++;
        }
        if(c>=((n/10)+((n%10>0)?1:0)))
        printf("%d   ",decdom[j]);
    }
}
