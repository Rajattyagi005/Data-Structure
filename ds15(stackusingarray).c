#include<stdio.h>
#define max 100
int a[max],top;
void push(int data)
{
    if(top==max-1)
    {
        printf("Error : Stack is full\n");
        return;
    }
    top++;
    a[top]=data;
}
void pop()
{
    if(top==-1)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    top--;
}
void Top()
{
    if(top==-1)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    printf("%d\n",a[top]);
}
void isEmpty()
{
    if(top==-1)
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
    int i;
    printf("Stack is : ");
    if(top==-1)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    for(i=0;i<=top;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    top=-1;
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
