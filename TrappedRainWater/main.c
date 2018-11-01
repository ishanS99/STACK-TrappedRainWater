#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* create(int n)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = n;
    temp->next = NULL;
    return temp;
};
void push(int n , struct Node** top)
{
    struct Node* t = create(n);
    t->next = *top;
    *top = t;
}
int pop(struct Node** top)
{
    int d = (*top)->data;
    struct Node* t= *top;
    *top = (*top)->next;
    free(t);
    return d;
}
int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
int main()
{
    int size,ans=0,i;
    struct Node* top =NULL;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<size;i++)
    {
        int current = i;
        while(top!=NULL && arr[current]>arr[top->data])
        {
            int temp = pop(&top);
            int d = current - top->data-1;
            int bounded_ht = min(arr[current],arr[top->data]) - arr[temp];
            ans+= d*bounded_ht;
        }
        push(current , &top);
    }
    printf("TOTAL WATER : %d", ans);
    return 0;
}
