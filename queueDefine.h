/*#ifndef QUEUEDEFINE_H_INCLUDED
#define QUEUEDEFINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//Queue *front=NULL,*rear=NULL;
//Queue bank[3];
typedef struct Bank
{
    int reachTime;
    int transactionTime;
    struct Bank *ptr;

}Bank;
typedef struct Queue
{
    Bank B;
    Bank * front;
    Bank * rear;
}Queue;
void enquque(Queue * q)
{
    if(q==NULL)
    {
        q.=q;
        rear1=q;
    }
    else
    {
        rear1->ptr=q;
        rear1=q;
    }
}

typedef struct Queue1
{
    int reachTime;
    int transactionTime;
    struct Queue1 *ptr;
}Queue1;
typedef struct Queue2
{
    int reachTime;
    int transactionTime;
    struct Queue2 *ptr;
}Queue2;
typedef struct Queue3
{
    int reachTime;
    int transactionTime;
    struct Queue3 *ptr;
}Queue3;

Queue1 *front1=NULL,*rear1=NULL;
Queue2 *front2=NULL,*rear2=NULL;
Queue3 *front3=NULL,*rear3=NULL;
Queue1.reachTime=0;
Queue2.reachTime=0;
Queue3.reachTime=0;
Queue1.transactionTime=0;
Queue2.transactionTime=0;
Queue3.transactionTime=0;
void enquque1(Queue1 * q)
{
    if(front1==NULL)
    {
        front1=q;
        rear1=q;
    }
    else
    {
        rear1->ptr=q;
        rear1=q;
    }
}
int dequque1()
{
        Queue1 *pqueue=front1;
        int x=front1->reachTime;
        front1=front1->ptr;
        free(pqueue);
        return x;
}
void enquque2(Queue2 * q)
{
    if(front2==NULL)
    {
        front2=q;
        rear2=q;
    }
    else
    {
        rear2->ptr=q;
        rear2=q;
    }
}
int dequque2()
{
        Queue2 *pqueue=front2;
        int x=front2->reachTime;
        front2=front2->ptr;
        free(pqueue);
        return x;
}
void enquque3(Queue3 * q)
{
    if(front3==NULL)
    {
        front3=q;
        rear3=q;
    }
    else
    {
        rear3->ptr=q;
        rear3=q;
    }
}
int dequque3()
{
        Queue3 *pqueue=front3;
        int x=front3->reachTime;
        front3=front3->ptr;
        free(pqueue);
        return x;
}
#endif */
