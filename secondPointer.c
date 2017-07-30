#include<stdio.h>
#include<stdlib.h>

void main()
{
    int **p;
    int c=0;
    int i,j;

    p=malloc(sizeof(int *)*20);
    for(i=0;i<20;i++)
    {
        *(p+i)=malloc(sizeof(int)*20);
        for(j=0;j<i;j++)
        {
            *(*(p+i)+j)=c++;
        }
    }

    for(i=0;i<20;i++)
    {
        for(j=0;j<i;j++)
        {
            c=*(*(p+i)+j);
            printf("%d     ",c);
        }
        printf("\n");
    }

}
