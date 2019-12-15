#include"queueDeclare.h"
int main(){
    int transTime=0,reachTime=0;
    int ch=0,j=0;
    do{
        printf("Enter 1 : Enter Customer  \nEnter 2 Display All Queue \nEnter 0 : Exit");
        printf("\nEnter 3 : Clear All Queue\nEnter Number to Choose :");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1:
                        printf(" Enter Customer : Time Reach");
                        scanf("%d",&reachTime);
                        printf("Enter Customer : Time Transaction");
                        scanf("%d",&transTime);
                        enterCustomer(reachTime,transTime);
                        break;
                case 2:
                        displayQueue(0);
                        displayQueue(1);
                        displayQueue(2);
                        break;
                case 3:
                    for(j=0; j<SIZE; j++){
                        front[j]=NULL;
                        rear[j]=NULL;
                    }


        }

    }while(ch);
    printf("\nCounter Customer = %d",countCustomer);
    printf("\nTrans Time = %d , waitingTime= %d,",calTransTime(0),calWaitingTime(0));

    /*enquque(0,2,20);
    enquque(0,2,10);
    enquque(0,1,3);
    enquque(0,2,5);
    enquque(0,3,2);
    enquque(1,1,3);
    enquque(1,2,5);
    enquque(1,3,2);
    enquque(2,1,3);
    enquque(2,2,5);
    enquque(2,3,2);
    enquque(2,3,5);
    displayQueue(0);
    printf("\n%d",calTransTime(0));
    printf("\n_______________________________________\n");
    displayQueue(1);
    printf("\n%d",calTransTime(1));
    printf("\n_______________________________________\n");
    displayQueue(2);
    printf("\n%d",calTransTime(2));*/
    return 0;
}


















/*int main()
{
    int ch=0;
    int transTime,reachTime;
    do{

            printf(" Enter Customer : Time Transaction");
            scanf("%d",&transTime);
            printf(" Enter Customer : Time Reach");
            scanf("%d",&reachTime);
            if(){

            }
            printf("Hello Are you Entering Customer ( Y=1 or N=0 ) : ");
            scanf("%d",&ch);

    }while(ch !=0);
    //scanf("");
    Queue t;
    t.front=NULL;
    Queue2 n1;
    n1.reachTime=10;
    Queue1 n2;
    n2.reachTime=20;
    Queue1 n3;
    n3.reachTime=30;
    Queue1 n4;
    n4.reachTime=40;
    Queue2 n5;
    n5.reachTime=50;
    enquque2(&n1);
    enquque1(&n2);
    enquque1(&n3);
    enquque2(&n4);
    printf("%d\n",dequque2());
    printf("%d\n",dequque2());
    printf("Hello world!\n");
    return 0;
}*/
