#include<stdio.h>
#include<stdlib.h>
main()
{
    int n ,i, x, start=0, end;
    int* array;
    printf("Enter the Number of elements\n");
    scanf("%d", &n);
    array=(int *)malloc(n*sizeof(int));
    printf("Enter the elements of Array\n");
    for(i=0;i<n;i++){
        scanf("%d", &array[i]);
    }
    printf("Enter the value of x\n");
        scanf("%d", &x);
    i=n-1;
    while(array[i]>x)
    {
        i--;
    }
    end=i;

    while(end>start)
    {
        if(x==(array[end]+array[start]))
        {
            printf("x = array[%d] + array[%d]\n",end+1,start+1);
            break;
        }
        else if(x>(array[end]+array[start]))
            start++;
        else
            end--;
    }
    if(end<=start)
        printf("No solution exist\n");
}
