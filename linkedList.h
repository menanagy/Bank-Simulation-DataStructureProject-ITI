#include <stdio.h>
#include <stdlib.h>
typedef  struct linkedList{
int reachTime;
int transactionTime;
struct linkedList *next,*prev;
}linkedList;
linkedList *first=NULL,*last=NULL;
linkedList* _create(int arrivalTime,int transTime)
{
    linkedList* newlinkedList=(linkedList *)malloc(sizeof(linkedList));
    newlinkedList->reachTime=arrivalTime;
    newlinkedList->transactionTime=transTime;
    newlinkedList->next=newlinkedList->prev=NULL;
    return newlinkedList;
}
void _add(linkedList* newlinkedList)
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
void _display(){
linkedList *pdisplay=first;
int i=0;
    while(pdisplay != NULL)
    {
        printf("Display Data %d: Arrival Time= %d , Reach Time %d\n",i,pdisplay->reachTime,pdisplay->transactionTime);
        pdisplay=pdisplay->next;
        i++;
    }
}

void _insertAfter(linkedList *pafter,linkedList* pnewlinkedList)
{
    if(pafter==last){
        _add(pnewlinkedList);
    }
    else
        {
        pnewlinkedList->prev=pafter;
        pnewlinkedList->next=pafter->next;
        pafter->next->prev=pnewlinkedList;
        pafter->next=pnewlinkedList;
    }
}
linkedList* _remove(linkedList *pdelete){
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
void _swap(linkedList *n1,linkedList *n2){
    linkedList * ptr=_remove(n1);
    _insertAfter(n2,ptr);
}
void bubbleSort()
{    int sorted=0;
    linkedList *ptr1=first;
    /* Checking for empty list */
    do
    {
        sorted=1;
        ptr1=first;
        while(first->next!=NULL)
        {

            if(first->reachTime > first->next->reachTime)
            {
                _swap(first, first->next);
                //printf("%d  %d\n",first->data.id,first->Next->data.id);
                sorted=0;


            }
            else
            {
                first=first->next;
            }
        }

    }
    while(!sorted);
}
