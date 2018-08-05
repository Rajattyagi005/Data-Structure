#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
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
bool search(struct Node* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }
    else if(data<=root->data)
    {
        return search(root->left,data);
    }
    else
    {
        return search(root->right,data);
    }
}

int main()
{
    int key;
    struct Node* root=NULL;
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,6);
    printf("Enter key to be searched\n");
    scanf("%d",&key);
    if(search(root,key)==true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    return 0;
}

