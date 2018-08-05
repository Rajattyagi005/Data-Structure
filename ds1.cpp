
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;

};


void insert(Node** pointertohead,int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *pointertohead;
    *pointertohead=temp;
}
void print(Node* head)
{

    printf("List is : \n");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = NULL;
    int n,i,x;
    printf("Enter how many numbers?\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for %d node\n",i+1);
        scanf("%d",&x);
        insert(&head,x);
        print(head);
    }
}
