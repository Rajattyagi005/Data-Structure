#include<stdio.h>                //print linked list recursively in order and reverse order
#include<malloc.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;

};
struct Node* insert(struct Node* head,int data)
{
     struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    struct Node*temp1=head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    return head;
}
void print(struct Node* p)
{

    if(p==NULL)
    {
        return;
    }
    printf("%d ",p->data);
    print(p->next);

}
void reverse(struct Node* q)
{

    if(q==NULL)
    {
        return;
    }
    reverse(q->next);
    printf("%d ",q->data);
}
int main()
{
    //int x,i,n;
    struct Node* head=NULL;
   /* printf("Enter the size of linked list");
    scanf("%d",&n);
    printf("Enter the values for linked list");
   /* for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }*/
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    print(head);
    printf("\n");
    reverse(head);
    return 0;
}
