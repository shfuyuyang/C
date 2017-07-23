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
        *l=malloc(sizeof(Line));
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
    l=malloc(sizeof(Line));
    //l->val=0;

    addPoint(&l,2);
    addPoint(&l,3);

    displayLine(l);

    return 0;
}
