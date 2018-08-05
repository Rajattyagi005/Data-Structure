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
struct Node* findMin(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        findMin(root->left);
    }
    return root;
}
struct Node* delete(struct Node* root,int val)
{
    if(root==NULL)
    {
        return;
    }
    else if(root->data > val)
    {
        root->left=delete(root->left,val);
    }
    else if(root->data < val )
    {
        root->right=delete(root->right,val);
    }
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            struct Node* temp=root;
            free(root);
            return temp->right;

        }
        else if(root->right==NULL)
        {
            struct Node* temp=root;
            free(temp);
            return temp->left;
        }
        else
        {
            struct Node* temp;
            temp=findMin(root->right);
            root->data=temp->data;
            return root->right=delete(root->right,temp->data);
        }
    }

}
void inOrder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
int main()
{
    struct Node* root=NULL;
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,1);
    root=insert(root,5);
    inOrder(root);
    printf("\n");
    root=delete(root,4);
    inOrder(root);
    return 0;
}
