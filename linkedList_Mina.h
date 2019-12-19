#ifndef LINKEDLIST_Mina_H_INCLUDED
#define LINKEDLIST_Mina_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef  struct linkedList
{
int reachTime;
int transactionTime;
struct linkedList *next,*prev;
}linkedList;

linkedList* linkedList_Create(int arrivalTime,int transTime);
void linkedList_Add(linkedList* newlinkedList);
void linkedList_Display();
void linkedList_InsertQueue();
void linkedList_InsertAfter(linkedList *pafter,linkedList* pnewlinkedList);
linkedList* linkedList_Remove(linkedList *pdelete);
void linkedList_Swap(linkedList *n1,linkedList *n2);
void linkedList_BubbleSort();
#endif
