#include<stdio.h>
#include<stdlib.h>

typedef struct line
{
    int val;
    struct line * next;
}Line;

void addPoint(Line **l,int val)
{
    if(*l==NULL)
    {
        *l=malloc(sizeof(Line*));
        //*(*l)=malloc(sizeof(Line));
        (*l)->val=val;
    }
    else
    {
        addPoint(&((*l)->next),val);
    }
}

void displayLine(Line *l)
{
    if(l==NULL)
    {
        return;
    }
    else
    {
        printf("%d\n",l->val);
        displayLine(l->next);
    }
}

int main(void)
{
    Line *l;
/*
    addPoint(&l,2);
    addPoint(&l,3);

    displayLine(l);
*/
    int a=12;

    printf("%d\n",a);

    return 0;
}
