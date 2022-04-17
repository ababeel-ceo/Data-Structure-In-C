                                     /* Implementing Doubly Linked List in c */                              //---by_ABD---//

                                     //Aarambikalaamaa//

#include <stdio.h>
#include <stdlib.h>
//------Creating Node-------//
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
//---------------------------//

// typedef for use shorthand notation //
typedef struct Node node;

// Creating head Pointer which is NULL//
node* head=NULL;
node* tail=NULL;


//---------------------- Inserting Data--------------------------- //
void insertData(int pos,int val)
{
    node* newNode= (node*) malloc(sizeof(node));//use malloc to dynamically allocate the memory//

//if the list has no value but user try to enter data in some incremented position //

    if(head==NULL && pos>1 )
    {
        printf("List has no value pls enter the value at opening position (eg: position :1)\n");
        return;
    }
// if the position is less than 0 Because position starts from 1st position //
    if(pos<1)
    {
        printf("Invalid Position \n");
        return;
    }
    newNode->data=val;// Assign value to the Node data(int)//

//insert data at beginning of the list //

    if(pos==1)
    {

       if(head==NULL)
        {
            newNode->next=NULL;
            newNode->prev=NULL;
            tail=newNode;
        }
        else{
            head->prev=newNode;
            newNode->next=head;


        }
        head=newNode;


         printf(" Entered position is : %d \t value is : %d \n",pos,val);
         return;

    }


//----- Enter the data at specific position-----//

    node* temp=head;    //temperary poiter variable is used to jump to the particulat position //

    for(int i=2; i<pos; i++)
        {
            if(temp==NULL)
            {
                printf("\nInvalid Position\n ");
                return;
            }
            temp=temp->next; //jumping to next Node
        }
        newNode->next=temp->next;
        newNode->prev=temp;

    printf(" Entered position is : %d \t value is : %d \n",pos,val);


  // Inserting Node last Position //
        if(temp==tail) {
            tail=newNode;
        }
        else {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
//--------  Display(Traverse) the List---------------- //


//-------Traverse Using Head----------//
    void DisplayByHead()
    {
        if(head==NULL)
        {
            printf("\nList is Empty\n");
            return;
        }
        node* temp=head;
        printf("\nDisplay Using Head : \n");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }

    //--------Traverse Using Tail----------//
    void DisplayByTail()
    {
        if(tail==NULL)
        {
            printf("\nList is Empty\n");
            return;
        }
        node* temp=tail;
        printf("\nDisplay Using Tail :\n ");
        while(temp!=NULL)
        {
             printf("%d  ",temp->data);
            temp=temp->prev;
        }

    }
//-------------Deleting Node by position---------------//

//--------deleting the Node-----------//
    void deleteNodeByPos(int pos)
    {
         node* temp=head;     // for jumping

        int value;
        if(head==NULL)
        {
           printf("\nList has No Value \n");
            return;
        }
        // deleting the 1st Node //
        if(pos==1)
        {
            value=head->data;
            head = head->next;
             if(head==NULL) {
             tail=NULL;
             }else {
                head->prev = NULL;
                }
            printf("\nDeleted Value is : %d\n ",value);
            free(temp);
            return;
        }
               node* pre = NULL;    //to store previous of temp

        // Deleting the Middle Node //
        for(int i=2; i<=pos; i++)
        {
            pre=temp;          //it stores the before the specified location
            temp=temp->next;   //it stores the specified location
            if(temp==NULL)     //if the position is greater than the available node
            {
                printf("\ninvalid Position\n");
                return;
            }
        }
        value= temp->data;
        //  Deleting the last Node //
        if(temp==tail)
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        else {
            pre->next = temp->next;
            temp->next->prev = pre;
        }
        free(temp);
         printf("\nDeleted Value is : %d\n ",value);
    }

int main()
{
    int pos,val,c;
    while(1)
    {
    printf("\nPress 1 Insert Value At Position(Position Starts from 1) \n");
    printf("\nPress 2 to Display The List Using Head\n");
    printf("\nPress 3 to Display The List Using Tail \n");
    printf("\nPress 4 to Delete The node by Position(position Starts from 1)\n");
    printf("\nPress 5 to Exit\n");
    printf("\nEnter Your Choice :  \n");
    scanf("%d",&c);
    switch(c)
    {
    case 1: printf("\nEnter the position and value :\n");
            scanf("%d%d",&pos,&val);
             if(pos<1)
                        {
                            printf("\ninvalid Position\n");
                            break;
                        }
            insertData(pos,val);
            break;
    case 2: DisplayByHead();
            break;
    case 3: DisplayByTail();
            break;

    case 4: printf("\nEnter the Position to Delete the Node\n");
            scanf("%d",&pos);
            if(pos<1)
                        {
                            printf("\nInvalid Position\n");
                            break;
                        }
            deleteNodeByPos(pos);
            break;
    case 5: exit(0);
            break;

    default:
        printf(" \nEnter the valid choice ");
    }
    }
    return 0;
}
