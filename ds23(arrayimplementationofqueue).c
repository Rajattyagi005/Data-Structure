#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 5
int a[max];
int rear,front;

bool isEmpty()
{
    if(rear==-1&&front==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isFull()
{
    if((rear+1)%max==front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
bool isEmpty(){
return (front == -1 && rear == -1) ? true : false;
}

bool isFull(){
return (rear+1)%max == front ? true : false;
}
*/
void enQueue(int data)
{
    if(isFull())
    {
        printf("Queue is full\n");
        return;
    }
    else if(isEmpty())
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%max;
    }
    a[rear]=data;
}
void deQueue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%max;
    }
}

void Print()
{
    int length,i;
    length=(rear+max-front)%max+1;
    printf("Queue is : ");
    for(i=0;i<length;i++)
    {
        printf("%d ",a[(front+i)%max]);
    }
    printf("\n");
}
int main()
{
front = -1;
rear = -1;
enQueue(2); Print();
enQueue(4); Print();
enQueue(6); Print();
deQueue(); Print();
enQueue(10); Print();
deQueue(); Print();
return 0;
}
