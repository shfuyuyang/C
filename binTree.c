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

int getBinaryTreeLongest(BinTree * root)
{
    int left=0,right=0;
    if(root==NULL)
    {
        return 0;
    }
    left=getBinaryTreeLongest(root->left);
    right=getBinaryTreeLongest(root->right);
    if(left>=right)
    {
        return left+1;
    }
    else
    {
        return right+1;
    }
}
//[1,2,3,4,5,6,7,8,9,0,null,null,null,null,null,1,null,null,null,0,0,null,1,null,1,null,1,1,null,null,null,1]
int diameterOfBinaryTreeShadow(BinTree * root,int *max)
{
    int left=0,right=0;
    if(root==NULL)
    {
        return 0;
    }
    left=getBinaryTreeLongest(root->left);
    right=getBinaryTreeLongest(root->right);
    if(*max<left+right)
    {
        *max=left+right;
    }
    diameterOfBinaryTreeShadow(root->left,max);
    diameterOfBinaryTreeShadow(root->right,max);
}

int diameterOfBinaryTree(BinTree * root)
{
    int max=0;
    diameterOfBinaryTreeShadow(root,&max);
    return max;
}

void main()
{
    BinTree * root;
    int a=0;
    root=malloc(sizeof(BinTree));
    root->val=1;
    a=diameterOfBinaryTree(root);
    printf("%d\n",a);

}
