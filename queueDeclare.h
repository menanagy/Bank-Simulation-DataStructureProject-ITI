#ifndef QUEUEDECLARE_H_INCLUDED
#define QUEUEDECLARE_H_INCLUDED
#include"linkedList.h"
#define SIZE 3
int countCustomer =0;
typedef struct NewNode{
    int reachTime;
    int transTime;
    int endTime;
    int waitingTime;
    int startTime;
    struct NewNode *ptr;
}Node;

Node *front[SIZE]={NULL,NULL,NULL},*rear[SIZE]={NULL,NULL,NULL};

void enquque(char i,int RTime,int TTime)
{
    Node *node=(Node *)malloc (sizeof(Node));
    node->reachTime=RTime;
    node->transTime=TTime;
    node->endTime=RTime+TTime;
    if(front[i]==NULL)
    {
        front[i]=node;
        rear[i]=node;
        node->waitingTime=0;
        node->startTime=node->reachTime+node->waitingTime;
        node->ptr=NULL;
        countCustomer++;
    }
    else
    {
        node->waitingTime=rear[i]->endTime-node->reachTime;
        if(node->waitingTime<0){node->waitingTime=0;}
        node->endTime+=node->waitingTime;
        node->startTime=node->reachTime+node->waitingTime;
        rear[i]->ptr=node;
        rear[i]=node;
        node->ptr=NULL;
        countCustomer++;
    }
}
void dequque(char i)
{
        while(front[i]!=NULL)
        {
                Node *pnode=front[i];
                //*RTime=front[i]->reachTime;
                //*TTime=front[i]->transTime;
                front[i]=front[i]->ptr;
                free(pnode);
        }
}

void displayQueue(char i)
{
    if(front[i]!=NULL)
    {
        Node* dnode=front[i];
        printf("______________________________________________________\n");
        printf("Display All Queue %d : ",i);
        printf("\nStart\tend\twait\tTotalWaiting\tAverageWaiting\n");
        while(dnode!=NULL)
        {
            printf(" %d\t %d\t %d\n",dnode->startTime,dnode->endTime,dnode->waitingTime);
            printf(" %d\t %d\t %d\n",totalWaitingTime(),(totalWaitingTime()/countCustomer),dnode->waitingTime);

            dnode=dnode->ptr;
        }
        printf("\n");
    }
    else
    {
        printf("\n Sorry this Queue is Empty : ");
    }
}
int totalTransTime(char i)
{
    Node* dnode=front[i];
    int sum=0;
    while(dnode!=NULL){
        sum=sum+dnode->transTime;
        dnode=dnode->ptr;
    }
    return sum;
}
int totalWaitingTime(char i)
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
            //endTimeCurrent=rear->reachTime;
            if(rear[0]->endTime<rear[1]->endTime&&rear[0]->endTime<rear[2]->endTime)
            {
                enquque(0,reachTime,transTime);
            }
            else if(rear[1]->endTime<rear[0]->endTime&&rear[1]->endTime<rear[2]->endTime)
            {
                enquque(1,reachTime,transTime);
            }
            else if(rear[2]->endTime<rear[0]->endTime&&rear[2]->endTime<rear[1]->endTime)
            {
                enquque(2,reachTime,transTime);
            }

                /*int x=calWaitingTime(0)-reachTime;
                int y=calWaitingTime(1)-reachTime;
                int z=calWaitingTime(2)-reachTime;
                 if ( x<=y  && x <= z){
                    enquque(0,reachTime,transTime);
                 }
                 else if (y<=x&&y<=z){
                    enquque(1,reachTime,transTime);
                 }
                 else{
                    enquque(2,reachTime,transTime);
                 }*/
            }
            else
            {
                if(front[0]==NULL){
                    enquque(0,reachTime,transTime);
                }
                else if(front[1]==NULL){
                    enquque(1,reachTime,transTime);
                }
                else if(front[2]==NULL)
                {
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
