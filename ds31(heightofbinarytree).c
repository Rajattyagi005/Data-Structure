#include<math.h>
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
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int findHeight(struct Node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return max(findHeight(root->left),findHeight(root->right))+1;
}
int main()
{
    int height;
    struct Node* root=NULL;
    root=insert(root,4);
    root=insert(root,54);
    root=insert(root,1);
    root=insert(root,5);
    root=insert(root,10);
    height=findHeight(root);
    printf("Height of tree : %d\n",height);
    return 0;
}
