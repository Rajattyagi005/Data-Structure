#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* getNewNode(data)
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
int findMin(struct Node* root)
{
    struct Node* current=root;
    if(current==NULL)
    {
        return -1;
    }
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}
int findMax(struct Node* root)
{
    struct Node* current=root;
    if(current==NULL)
    {
        return -1;
    }
    while(current->right!=NULL)
    {
        current=current->right;
    }
    return current->data;
}
int main()
{
    int min,max;
    struct Node* root=NULL;
    root=insert(root,4);
    root=insert(root,54);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,10);
    min=findMin(root);
    if(min==-1)
    {
        printf("Error : No data in tree\n ");

    }
    else
    {
        printf("Minimum in tree is : %d\n",min);
    }
    max=findMax(root);
    if(max==-1)
    {
        printf("Error : No data in tree\n ");

    }
    else
    {
        printf("Maximum in tree is : %d\n",max);
    }
    return 0;
}

