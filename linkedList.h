#include <stdio.h>
#include <stdlib.h>
typedef  struct linkedList
{
int reachTime;
int transactionTime;
struct linkedList *next,*prev;
}linkedList;

linkedList *first=NULL,*last=NULL;

linkedList* linkedList_Create(int arrivalTime,int transTime)
{
    linkedList* newlinkedList=(linkedList *)malloc(sizeof(linkedList));
    newlinkedList->reachTime=arrivalTime;
    newlinkedList->transactionTime=transTime;
    newlinkedList->next=newlinkedList->prev=NULL;
    return newlinkedList;
}

void linkedList_Add(linkedList* newlinkedList)
{
    if(first==NULL){//==>First Element
            first=last=newlinkedList;
    }
    else
    {
            newlinkedList->prev=last;
            last->next=newlinkedList;
            last=newlinkedList;
            newlinkedList->next=NULL;//My Extra Code
    }
}

void linkedList_Display(){
linkedList *pdisplay=first;
int i=0;
    while(pdisplay != NULL)
    {
        printf("Display Data %d: Arrival Time= %d , Reach Time %d \n",i,pdisplay->reachTime,pdisplay->transactionTime);
        pdisplay=pdisplay->next;
        i++;
    }
}

void linkedList_InsertQueue(){
linkedList *pdisplay=first;
dequque(0);
dequque(1);
dequque(2);
    while(pdisplay != NULL )
    {
            enterCustomer(pdisplay->reachTime,pdisplay->transactionTime);
            pdisplay=pdisplay->next;
    }
}

void linkedList_InsertAfter(linkedList *pafter,linkedList* pnewlinkedList)
{
    if(pafter==last)
    {
        linkedList_Add(pnewlinkedList);
    }
    else
    {
        pnewlinkedList->prev=pafter;
        pnewlinkedList->next=pafter->next;
        pafter->next->prev=pnewlinkedList;
        pafter->next=pnewlinkedList;
    }
}

linkedList* linkedList_Remove(linkedList *pdelete){
if(pdelete==first)
    {
        if(pdelete==last)
        {
            first=last=NULL;
        }
        else
        {
            first=pdelete->next;
            first->prev=NULL;
        }
    }
    else if(pdelete==last)
    {
        last=last->prev;
        last->next=NULL;
    }
    else
    {
        pdelete->next->prev= pdelete->prev;
        pdelete->prev->next= pdelete->next;
    }
    pdelete->next=pdelete->prev=NULL;
    return pdelete;
}

void linkedList_Swap(linkedList *n1,linkedList *n2){
    linkedList * ptr=linkedList_Remove(n1);
    linkedList_InsertAfter(n2,ptr);
}

void linkedList_BubbleSort()
{    int sorted=0;
    linkedList *ptr1;
    //linkedList *lptr = NULL;

    /* Checking for empty list */
    if(first==NULL){return ;}
    do
    {
        sorted=1;
        ptr1=first;
        while(ptr1->next!=NULL)
        {
            if(ptr1->reachTime > ptr1->next->reachTime)
            {
                linkedList_Swap(ptr1, ptr1->next);
                sorted=0;
            }
            else
            {
                ptr1=ptr1->next;
            }

        }

    }
    while(!sorted);
}
