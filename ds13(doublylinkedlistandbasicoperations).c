#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;     //here we have head as a global variable
struct Node* getNewNode(int data)    //create a new node
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insertAtHead(int data)    //insert a node at start(at head)
{
    struct Node* temp=getNewNode(data);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    struct Node* temp1=head;
    temp1->prev=temp;
    temp->next=temp1;
    head=temp;
}
void insertAtTail(int data)     //inserting a node at tail or last
{
    struct Node* temp=getNewNode(data);
    if(head==NULL)
    {
        head=temp;
        return;
    }
     struct Node* temp1=head;
     while(temp1->next!=NULL)
     {
         temp1=temp1->next;
     }
     temp1->next=temp;
     temp->prev=temp1;
}
void print()
{
    struct Node* temp=head;
    printf("list is : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reversePrint()      //print list in reverse order
{
    struct Node* temp=head;
    printf("list is : ");
    if(head==NULL)
    {
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
int main()
{
    head=NULL;
    insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);
    insertAtHead(1);
    insertAtTail(5);
    insertAtTail(6);
    insertAtTail(7);
    insertAtTail(8);
    print();
    reversePrint();
    return 0;
}

