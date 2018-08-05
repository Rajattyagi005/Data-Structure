#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 10
struct BstNode
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
/*
struct BstNode* arr[MAX];
int front = -1, rear = -1;

bool isEmpty()
{
    return (front == -1 && rear == -1) ? true : false;
}

bool isFull()
{
    return (rear+1)%MAX == front ? true : false;
}

void enQueue(struct BstNode* x)
{
    if(isFull())
    {
        printf("queue is full\n");
        return;
    }
    if(isEmpty())
    front = rear = 0;
    else
    rear = (rear+1)%MAX;
    arr[rear] = x;
}
void deQueue()
{
    if(isEmpty())
    {
        printf("queue is empty\n");
        return;
    }
    else if(front == rear)
    front = rear = -1;
    else
    front = (front+1)%MAX;

}*/

struct BstNode* getNewNode(int d)
{
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
    newNode->data = d;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct BstNode* Insert(struct BstNode* root, int d)
{
    struct BstNode* newNode = getNewNode(d);
    if(root == NULL)
    {
        root = newNode;
    }
    else if(d <= root->data)
    {
        root->left = Insert(root->left, d);
    }
    else
        root->right = Insert(root->right, d);

    return root;
}
/*
void levelOrder(struct BstNode* root)
{
    if(root == NULL) return;
    enQueue(root);
    while(!isEmpty())
    {
        struct BstNode* current = arr[front];

        printf("%d ", current->data);
        deQueue();
        if(current->left != NULL) enQueue(current->left);
        if(current->right != NULL) enQueue(current->right);

    }
}*/
void preOrder(struct BstNode*root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct BstNode*root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct BstNode*root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
int main()
{
    struct BstNode* root = NULL;
    root = Insert(root,5);
    root = Insert(root,1);
    root = Insert(root,15);
   /* root = Insert(root,7);
    root = Insert(root,3);
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,21);*/
    /*printf("Level order traversal : ");
    levelOrder(root);
    printf("\n");*/
    printf("Pre order traversal : ");
    preOrder(root);
    printf("\n");
    printf("In order traversal : ");
    inOrder(root);
    printf("\n");
    printf("Post order traversal : ");
    postOrder(root);
    printf("\n");
    return 0;
}
