// Cycle 1 FCFS program
// sunith vs
// 20220098
// CS B
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


struct process{
	int arrival_time;
	int burst_time;
	int process_id;
	int tat;
	int wt;
};


int main(){

	int n,current=0;
	printf("enter the number of process");
	scanf("%d",&n);
	printf("you have entered %d process",n);
	struct process p[n],tmp;

	for(int i=0;i<n;i++){
		printf("\nenter arrival time of process %d: ",i+1);
		scanf("%d",&p[i].arrival_time);

		printf("\nenter burst time of process %d: ",i+1);
		scanf("%d",&p[i].burst_time);
		p[i].process_id=i+1;
		
	}

	for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++){
				if(p[i].arrival_time > p[j].arrival_time){
						tmp=p[i];
						p[i]=p[j];
						p[j]=tmp;
				}
			}
			
		}
	
	for(int i=0;i<n;i++){
			int diff = p[i].arrival_time-current;
			if(diff > 0){
				printf("\nthe cpu is idle state for %d secs",diff);
				printf("\n");
				sleep(diff);
				current+=diff;
			}
			
			p[i].wt=current-p[i].arrival_time;
			p[i].tat=p[i].wt+p[i].burst_time;
		
			printf("\nprocess :%d started",p[i].process_id);
			
			printf("\n");
			sleep(p[i].burst_time);
			current+=p[i].burst_time;
			printf("\nprocess :%d ended after %d secs",p[i].process_id,p[i].burst_time);
		}
	printf("\n");

		for(int i=0;i<n;i++){
			printf("\nprocess :%d arrival time: %d burst time: %d wait time : %d tat: %d",p[i].process_id,p[i].arrival_time,p[i].burst_time,p[i].wt,p[i].tat);
		}

}

/*
Output

enter the number of process3
you have entered 3 process
enter arrival time of process 1: 1

enter burst time of process 1: 10

enter arrival time of process 2: 20

enter burst time of process 2: 1

enter arrival time of process 3: 1

enter burst time of process 3: 20

the cpu is idle state for 1 secs

process :1 started

process :1 ended after 10 secs
process :3 started

process :3 ended after 20 secs
process :2 started

process :2 ended after 1 secs

process :1 arrival time: 1 burst time: 10 wait time : 0 tat: 10
process :3 arrival time: 1 burst time: 20 wait time : 10 tat: 30
*/
