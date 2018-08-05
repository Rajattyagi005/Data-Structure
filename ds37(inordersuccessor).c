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
struct Node* a[10];
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

void inOrder(struct Node* root)
{
    static int i;
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    a[i++]=root->data;
    inOrder(root->right);
}
void findSuccessor(struct Node* root,int data)
{
    int i=0;
    inOrder(root);
    while(a[i]!=data)
    {
        i++;
    }
    printf("%d",a[i+1]);
}
int main()
{
    struct Node* root=NULL;
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,5);
    findSuccessor(root,5);
    return 0;
}

