#include<stdio.h>
#include<stdlib.h>

typedef struct binTree
{
    int val;
    struct binTree * left;
    struct binTree * right;
}BinTree;

BinTree * mergeTree(BinTree * t1,BinTree * t2)
{
    BinTree * returnT;
    if(t1==NULL&&t2!=NULL)
    {
        return t2;
    }
    else if(t1!=NULL&&t2!=NULL)
    {
        return t1;
    }
    else if(t1==NULL&&t2==NULL)
    {
        return NULL;
    }

    returnT=malloc(sizeof(BinTree));
    returnT->val=t1->val+t2->val;
    returnT->left=mergeTree(t1->left,t2->left);
    returnT->right=mergeTree(t1->right,t2->right);
    return returnT;
}

BinTree * invertTree(BinTree * root)
{
    BinTree * returnT;
    if(root==NULL)
    {
        return NULL;
    }
    returnT=malloc(sizeof(BinTree));
    returnT->val=root->val;
    returnT->left=invertTree(returnT->right);
    returnT->right=invertTree(returnT->left);
    return returnT;
}

void main()
{

}
