#include"queue_mina.h"
int countCustomer =0;
queue_Mina *front[SIZE]={NULL,NULL,NULL},*rear[SIZE]={NULL,NULL,NULL};

void enquque(char noQueue,int RTime,int TTime)
{
    queue_Mina *node=(queue_Mina *)malloc (sizeof(queue_Mina));
    node->reachTime=RTime;
    node->transTime=TTime;
    node->endTime=RTime+TTime;
    if(front[noQueue]==NULL)
    {
        front[noQueue]=node;
        rear[noQueue]=node;
        node->waitingTime=0;
        node->startTime=node->reachTime+node->waitingTime;
        node->ptr=NULL;
        countCustomer++;
    }
    else
    {
        node->waitingTime=rear[noQueue]->endTime-node->reachTime;
        if(node->waitingTime<0){node->waitingTime=0;}
        node->endTime+=node->waitingTime;
        node->startTime=node->reachTime+node->waitingTime;
        rear[noQueue]->ptr=node;
        rear[noQueue]=node;
        node->ptr=NULL;
        countCustomer++;
    }
}

void dequque(char noQueue)
{
        while(front[noQueue]!=NULL)
        {
                queue_Mina *pnode=front[noQueue];
                //*RTime=front[i]->reachTime;
                //*TTime=front[i]->transTime;
                front[noQueue]=front[noQueue]->ptr;
                free(pnode);
        }
}

void displayQueue(char noQueue)
{
    if(front[noQueue]!=NULL)
    {
        queue_Mina* dnode=front[noQueue];
        printf("______________________________________________________\n");
        printf("Display All Queue %d : ",noQueue);
        printf("\nStart\tend\twait\t\n");
        while(dnode!=NULL)
        {
            printf("| %d\t |%d\t |%d\n",dnode->startTime,dnode->endTime,dnode->waitingTime);
            dnode=dnode->ptr;
        }
        printf("\n");
        printf("______________________________________________________\n");
        printf("Num of Customer =%d | TotalWaiting= %d",count_queue(noQueue),totalWaitingTimeForQueue(noQueue));
        printf("|AverageWaiting = %f\n",totalWaitingTimeForQueue(noQueue)/count_queue(noQueue));
    }
    else
    {
        printf("\n Sorry this Queue is Empty : \n");
    }
}
int count_queue(char noQueue)
{
    queue_Mina *count_customer=front[noQueue];
    int counter_customer=0;
    if(front[noQueue]!= NULL)
    {
        while(count_customer!=NULL)
        {
            counter_customer++;
            count_customer=count_customer->ptr;
        }
        return counter_customer;
    }
    else
    {
        return -1;
    }
}
int totalTransTime(char noQueue)
{
    queue_Mina * dnode=front[noQueue];
    int sum=0;
    while(dnode!=NULL){
        sum=sum+dnode->transTime;
        dnode=dnode->ptr;
    }
    return sum;
}
int totalWaitingTimeForQueue(char noQueue)
{
    queue_Mina* dnode=front[noQueue];
    int sumwaiting=0;
    while(dnode!=NULL){
        sumwaiting=sumwaiting+dnode->waitingTime;
        dnode=dnode->ptr;
    }
    return sumwaiting;
}
int totalWaitingTimeForAllQueue(void)
{
    char i=0;
    int  totalWaitingTimeAll=0;
    for(i=0; i<SIZE; i++){
        totalWaitingTimeAll+=totalWaitingTimeForQueue(i);
    }
    return totalWaitingTimeAll;
}
void enterCustomer(int reachTime ,int transTime)
{
    if(front[0]!=NULL&&front[1]!=NULL&&front[2]!=NULL)//Queue 1,2,3 are not Empty
    {
        if(rear[0]->endTime<=rear[1]->endTime&&rear[0]->endTime<=rear[2]->endTime)//Queue 1 is the Shortest Time
        {
            enquque(0,reachTime,transTime);//Insert in Queue1
        }
        else if(rear[1]->endTime<=rear[0]->endTime&&rear[1]->endTime<=rear[2]->endTime)//Queue 2 is the Shortest Time
        {
            enquque(1,reachTime,transTime);//Insert in Queue2
        }
        else if(rear[2]->endTime<=rear[0]->endTime&&rear[2]->endTime<=rear[1]->endTime)//Queue 3 is the Shortest Time
        {
            enquque(2,reachTime,transTime);//Insert in Queue3
        }

    }
    else// Queue1 or Queue2 or Queue3
    {
        if(front[0]==NULL){
            enquque(0,reachTime,transTime);//Insert in Queue1
        }
        else if(front[1]==NULL){
            enquque(1,reachTime,transTime);//Insert in Queue2
        }
        else if(front[2]==NULL)
        {
            enquque(2,reachTime,transTime);//Insert in Queue3
        }
    }
}
void display_Bank_Data(void)
{
    if(countCustomer!=0)
    {
        printf("Total Bank Data : \nWaiting Time\tAverageWTime\n");
        printf("%d,%f",totalWaitingTimeForAllQueue(),totalWaitingTimeForAllQueue()/countCustomer);
    }

}
