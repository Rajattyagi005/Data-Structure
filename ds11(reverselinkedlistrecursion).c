#include<stdio.h>
#include<stdlib.h>              //reverse linked list using recursion

#include<malloc.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
void reverse(struct Node* p)    // this function reverse linked list actually
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse(p->next);
    struct Node* q=p->next;
    q->next=p;
    p->next=NULL;
}
/*void reverse(struct Node* p)   //this function only print linked list in reverse order
{
    if(p==NULL)
    {
        return;
    }
    reverse(p->next);
    printf("%d ",p->data);
}*/
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
    reverse(head);
    print();
    return 0;
}
