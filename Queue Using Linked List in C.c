#include <stdio.h>
#include <stdlib.h>

// Creating Node Structure//
struct Node{
    int data;
    struct Node* next;
};
//-----------------------------//
typedef struct Node node;
//-----------------------------//

// Creating Queue Strucure//

struct Queue{
    node* front;
    node* rear;
};
//-----------------------------//
typedef struct Queue que;
//-----------------------------//

// Creating Queue Dymically    //

que*  createQueue()
{
   que* q= (que*)malloc(sizeof(que));
   q->front=NULL;
   q->rear=NULL;

   return q;

}
//------------------------------//

//--------------Enqueue Operation ------------------//
void enqueue(que* q, int val)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    if(q->rear == NULL)
    {
        q->front=newNode;
    }
    else{
        q->rear->next=newNode;
    }
    q->rear=newNode;
    printf("\nENqueued value is : %d",val);
}
//--------------------------------------------------//

//-------------------dequeue Operation --------------------//

int dequeue(que* q)
{
    if(q->front==NULL)
    {
        printf("\nQueue is Empty \n");
        return;
    }
    node* del=q->front;
    q->front=q->front->next;
    int delvalue= del->data;
    free(del);
    return delvalue;
}

int main()
{
    que* q1=createQueue();
     enqueue(q1,23);
     enqueue(q1,22);
     enqueue(q1,24);
     enqueue(q1,25);
     printf("\nDeleted Queue element is : %d",dequeue(q1));
     printf("\nDeleted Queue element is : %d",dequeue(q1));
     printf("\nDeleted Queue element is : %d",dequeue(q1));
     printf("\nDeleted Queue element is : %d",dequeue(q1));
     printf("\nDeleted Queue element is : %d",dequeue(q1));
     return 0;
}
