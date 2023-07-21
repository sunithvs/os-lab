// Cycle 1 SJF
// sunith vs
// 20220098
// CS B
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    int BurstT[20];
    int WaitT[20],TurnT[20];
    int p;
    int pid[20];
    int fid[20];

    WaitT[0]=0; //Waiting time of initial process is 0

    printf("Enter number of processes required: ");
    scanf("%d",&p);
    
    printf("Enter Burst of processes:\n  Burst Time\n");
    
    for(int i=0;i<p;i++){
        printf("%d: " ,i+1);
        scanf("%d",&BurstT[i]);
        pid[i]=i;
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<p-i-1;j++){
            if(BurstT[j]>BurstT[j+1]){
                int temp=BurstT[j];
                BurstT[j]=BurstT[j+1];
                BurstT[j+1]=temp;
                temp=pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
            }
        }
    }

    for(int i=0;i<p;i++){
      fid[i]=fork();
      if(fid[i]==0){
           printf("Process %d started\n",pid[i]+1);
           sleep(1);
           printf("Process %d stopped\n",pid[i]+1);
           exit(0);
      }else{
        waitpid(fid[i],NULL,0);
     }
    }
    
   
   
 
    //Calculating Waiting Time
    for(int i=1;i<p;i++){
        WaitT[i]=WaitT[i-1]+BurstT[i-1];
    }

    //Calculating TurnAround Time
    for(int i=0;i<p;i++){
        TurnT[i]=BurstT[i]+WaitT[i];
    }
    printf("Si No:\tBurst Time\tWaiting time\tTurnAround Time\n");
    
    for(int i=0;i<p;i++){
                        printf("%d\t\t%d\t\t%d\t\t%d\n",pid[i]+1,BurstT[i],WaitT[i],TurnT[i]);
        
    }
    return 0;
}

/*
Output
Enter number of processes required: 3
Enter Burst of processes:
  Burst Time
1: 10
2: 20
3: 30
Process 1 started
Process 1 stopped
Process 2 started
Process 2 stopped
Process 3 started
Process 3 stopped
Si No:	Burst Time	Waiting time	TurnAround Time
1		10		0		10
2		20		10		30
3		30		30		60

*/
