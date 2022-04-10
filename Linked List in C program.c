                                     /* Implementing Linked List in c */                              //---by_ABD---//

                                     //Aarambikalaamaa//

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
node* head=NULL;


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
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }

         printf(" Entered position is : %d \t value is : %d \n",pos,val);
         return;

    }
    node* temp=head;  //temperary poiter variable is used to jump to the particulat position //

//----- Enter the data at specific position-----//


    for(int i=2; i<pos; i++)
    {
         temp=temp->next;
        if(temp==NULL)
        {
            printf("Invalid position   :%d\n",pos);
            return;
        }

    }
   newNode->next=temp->next; //inserting the node in specified Position//
   temp->next=newNode;

    printf(" Entered position is : %d \t value is : %d \n",pos,val);

}

//--------  Display(Traverse) the List---------------- //


void displayLL()
{
    if(head==NULL)
    {
        printf("\nlist is empty \n");
        return;
    }
    node* temp=head;
    printf("\nLiinked list Elements Are : ");
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;// Jumping to next Node //
    }
}
//-------------Deleting Node by position---------------//

void deletedata(int pos)
{
    if(head==NULL)
    {
        printf("\nList has no Value \n");
        return;

    }
    node* temp=head;
    node* prev;
//------deleting the top node-----//

    if(pos==1)
    {
        int value=head->data;
        head=head->next;
        printf("\ndeleted value is : %d",value);
        return;
    }

//------------deleting specified Node----------//
    for(int i=2; i<=pos; i++)
    {
        prev=temp; //it stores the previous node of temp node
        temp=temp->next; //it stores the specified position node

        if(temp==NULL)
        {
            printf("\nInvalid Position \n");
            return;
        }
    }
    prev->next=temp->next;      // breaking the link of temp node (Deleting the temp Node)//
    printf("\nDeleted : %d \n",temp->data);
    free(temp);  //deleting the deleted node from the Memory//

}

int main()
{
    int pos,val,c;
    while(1)
    {
    printf("\nPress 1 to enter the data \n");
    printf("\nPress 2 to display(Traverse) the value \n");
    printf("\nPress 3 to delete the data \n");
    printf("\nPress 4 to Exit \n");
    printf("\nEnter Your Choice :  \n");
    scanf("%d",&c);
    switch(c)
    {
    case 1: printf("\nEnter the position and value :\n");
            scanf("%d%d",&pos,&val);
            insertData(pos,val);
            break;
    case 2: displayLL();
            break;
    case 3: printf("\nEnter the Position \n");
            scanf("%d",&pos);
            deletedata(pos);
            break;
    case 4: exit(0);


    default:
        printf(" \nEnter the valid choice ");
    }
    }
    return 0;
}
