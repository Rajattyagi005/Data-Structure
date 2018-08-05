#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void enQueue(int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=temp;
        rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}
void deQueue()
{
    struct Node* temp=front;
    if(front==NULL&&rear==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear)
    {
        front=NULL;
        rear=NULL;
        return;
    }
    else
    {
        front=front->next;
    }
    free(temp);
}
void print()
{
    struct Node* temp=front;
    printf("Queue is : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    enQueue(4);print();
    enQueue(2);print();
    enQueue(3);print();
    deQueue();print();
    deQueue();print();
    enQueue(1);print();
    enQueue(5);print();
    deQueue();print();
    enQueue(6);print();
    return 0;
}
