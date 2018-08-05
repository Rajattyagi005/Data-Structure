
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* getNewNode(int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct Node* insert(struct Node* root,int data)
{
    if(root==NULL)
    {
        root=getNewNode(data);
    }
    else if(data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}
/*bool utilBst(struct Node* root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    else if(root->data>min
       &&root->data<max
       &&utilBst(root->left,min,root->data)
       &&utilBst(root->right,root->data,max))
    {
        return true;
    }
    else
    {
        return false;
    }
}*/
bool isSubTreeLesser(struct Node* root,int data)
{
    if(root==NULL)
    {
        return true;
    }
    else if(root->data<=data
            &&isSubTreeLesser(root->left,data)
            &&isSubTreeLesser(root->right,data))
    {
        return true;

    }
    else
    {
        return false;
    }
}
bool isSubTreeGreator(struct Node* root,int data)
{
    if(root==NULL)
    {
        return true;
    }
    else if(root->data>data
            &&isSubTreeGreator(root->left,data)
            &&isSubTreeGreator(root->right,data))
    {
        return true;

    }
    else
    {
        return false;
    }
}
bool isBinaryTree(struct Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    else if(isSubTreeLesser(root->left,root->data)
            &&isSubTreeGreator(root->right,root->data)
            &&isBinaryTree(root->left)
            &&isBinaryTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    bool x;
    struct Node* root=NULL;
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,5);
    x=isBinaryTree(root);
    if(x==true)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
