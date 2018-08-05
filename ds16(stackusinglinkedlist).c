#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* top;
void push(int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=top;
    top=temp;
}
void  pop()
{
    if(top==NULL)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    struct Node* temp=top;
    top=temp->next;
    free(temp);
}
void Top()
{
    if(top==NULL)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    //struct Node* temp=top;
    printf("%d\n",top->data);
}
void isEmpty()
{
    if(top==NULL)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
void print()
{
    struct Node* temp;
    if(top==NULL)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    temp=top;
    printf("Stack is : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    push(2);print();
    push(1);print();
    push(3);print();
    push(4);print();
    push(4);print();
    pop();print();
    push(5);print();
    push(6);print();
    pop();print();
    pop();print();
    Top();
    isEmpty();
    return 0;
}
