#ifndef QUEUEMina_H_INCLUDED
#define QUEUEMina_H_INCLUDED
#define SIZE 3
#include <stdio.h>
#include <stdlib.h>
typedef struct NewNode{
    int reachTime;
    int transTime;
    int endTime;
    int waitingTime;
    int startTime;
    struct NewNode *ptr;
}queue_Mina;
void enquque(char noQueue,int RTime,int TTime);
void dequque(char noQueue);
void displayQueue(char noQueue);
int totalTransTime(char noQueue);
int totalWaitingTimeForQueue(char noQueue);
int totalWaitingTimeForAllQueue(void);
void enterCustomer(int reachTime ,int transTime);
int count_queue(char noQueue);
void display_Bank_Data(void);
#endif
