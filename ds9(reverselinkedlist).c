#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void reverse()
{
    struct Node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void insert(int data)
{
    int i;
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=data;
    temp1->next=NULL;
    if(head==NULL)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    struct Node* temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
void print()
{
    struct Node* temp=head;
    printf("List is : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();
    reverse();
    print();
    return 0;
}
