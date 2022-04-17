#include <stdio.h>
#include <stdlib.h>


//------Creating Node-------//
struct Node
{
    int data;
    struct Node* next;
};
//---------------------------//

// typedef for use shorthand notation //
typedef struct Node node;

// Creating head Pointer which is NULL//
node* top=NULL;

void push(int val)
{
    node* newNode= (node*) malloc(sizeof(node));//use malloc to dynamically allocate the memory//
    if(newNode==NULL)
    {
        printf("OVERFLOW");
        return;
    }
    newNode->data=val;
    if(top==NULL)
        {
            newNode->next=NULL;
        }
        else{
            newNode->next=top;
        }
 top=newNode;
 printf("\npushed : %d",top->data);
}

int pop()
{
    node* temp=top;
    if(top==NULL)
    {
        printf("\nUNDERFLOW");
        return -1;
    }
    int val=top->data;
    top=top->next;
    free(temp);
    return val;
}
int peek()
{
    if(top==NULL)
        return -1;
    return top->data;
}


int main()
{
   push(10);
   push(15);
   push(65);
   push(5);
   printf("\nPeeked :%d",peek());

   printf("\nPoped :%d\n",pop());
   printf("\nPoped :%d\n",pop());
   printf("\nPoped :%d\n",pop());
   printf("\nPoped :%d\n",pop());
   printf("\n%d\n",pop());

   return 0;
}
