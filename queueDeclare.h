#ifndef QUEUEDECLARE_H_INCLUDED
#define QUEUEDECLARE_H_INCLUDED
//#include <stdio.h>
//#include <stdlib.h>
//Hello Mina
#include"linkedList.h"
#define SIZE 3
int countCustomer =0;
typedef struct NewNode{
    int reachTime;
    int transTime;
    int waitingTime;
    struct NewNode *ptr;
}Node;

Node *front[SIZE]={NULL,NULL,NULL},*rear[SIZE]={NULL,NULL,NULL};

void enquque(char i,int RTime,int TTime)
{
    Node *node=(Node *)malloc (sizeof(Node));
    node->reachTime=RTime;
    node->transTime=TTime;
    if(front[i]==NULL)
    {
        front[i]=node;
        rear[i]=node;
        node->waitingTime=0;
        node->ptr=NULL;
        countCustomer++;
    }
    else
    {
        node->waitingTime=rear[i]->waitingTime+rear[i]->reachTime+rear[i]->transTime-node->reachTime;
        rear[i]->ptr=node;
        rear[i]=node;
        node->ptr=NULL;
        countCustomer++;
    }
}
void dequque(char i,int *RTime,int *TTime)
{
        Node *pnode=front[i];
        *RTime=front[i]->reachTime;
        *TTime=front[i]->transTime;
        front[i]=front[i]->ptr;
        free(pnode);
}
void displayQueue(char i)
{
    if(front[i]!=NULL)
    {
        Node* dnode=front[i];
        printf("______________________________________________________\n");
        printf("Display All Queue %d : ",i);
        while(dnode!=NULL)
        {
            printf("RT= %d TT= %d WT= %d ,",dnode->reachTime,dnode->transTime,dnode->waitingTime);
            dnode=dnode->ptr;
        }
        printf("\n");
    }
    else
    {
        printf("\n Sorry this Queue is Empty : ");
    }
}
int calTransTime(char i)
{
    Node* dnode=front[i];
    int sum=0;
    while(dnode!=NULL){
        sum=sum+dnode->transTime;
        dnode=dnode->ptr;
    }
    return sum;
}
int calWaitingTime(char i)
{
    Node* dnode=front[i];
    int sumwaiting=0;
    while(dnode!=NULL){
        sumwaiting=sumwaiting+dnode->waitingTime;
        dnode=dnode->ptr;
    }
    return sumwaiting;
}
void enterCustomer(int reachTime ,int transTime)
{
    if(front[0]!=NULL&&front[1]!=NULL&&front[2]!=NULL)
            {
                 if (calTransTime(0) <= calTransTime(1) && calTransTime(0) <= calTransTime(2)){
                    enquque(0,reachTime,transTime);
                 }
                 else if (calTransTime(1) <= calTransTime(0) && calTransTime(1) <= calTransTime(2)){
                    enquque(1,reachTime,transTime);
                 }
                 else{
                    enquque(2,reachTime,transTime);
                 }
            }
            else
            {
                if(front[0]==NULL){
                    enquque(0,reachTime,transTime);
                }
                else if(front[1]==NULL){
                    enquque(1,reachTime,transTime);
                }
                else if(front[2]==NULL){
                    enquque(2,reachTime,transTime);
                }


            }
}
/*void enquque2(int RTime,int TTime)
{
    Node *node=(Node *)malloc (sizeof(Node));
    node->reachTime=RTime;
    node->reachTime=TTime;
    if(front2==NULL)
    {
        front2=node;
        rear2=node;
        node->ptr=NULL;
    }
    else
    {
        rear2->ptr=node;
        rear2=node;
        node->ptr=NULL;
    }
}
void dequque2(int *RTime,int *TTime )
{
        Node *pnode=front2;
        *RTime=front2->reachTime;
        *TTime=front2->transTime;
        front2=front2->ptr;
        free(pnode);
}
void displayQueue2(void)
{
    Node* dnode=front2;
    printf("Display All Queue : ");
    while(dnode!=NULL)
    {
        printf("%d,%d",dnode->reachTime,dnode->transTime);
        dnode=dnode->ptr;
    }
    printf("\n");

}
void enquque3(int RTime,int TTime)
{
    Node *node=(Node *)malloc (sizeof(Node));
    node->reachTime=RTime;
    node->transTime=TTime;
    if(front3==NULL)
    {
        front3=node;
        rear3=node;
        node->ptr=NULL;
    }
    else
    {
        rear3->ptr=node;
        rear3=node;
        node->ptr=NULL;
    }
}
void dequque3(int *RTime,int *TTime)
{
        Node *pnode=front3;
        *RTime=front3->reachTime;
        *TTime=front3->transTime;
        front3=front3->ptr;
        free(pnode);
//        return x;
}
void displayQueue3(void)
{
    Node* dnode=front3;
    printf("Display All Queue : ");
    while(dnode!=NULL){
        printf("%d,%d",dnode->reachTime,dnode->transTime);
        dnode=dnode->ptr;
    }

}*/
#endif
