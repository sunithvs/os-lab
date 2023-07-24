#include <cstdio>
#include <unistd.h>


struct process {
    int arrival_time, burst_time, tt, waiting_time;

};

int main() {
    int n;
    printf("Enter the number of processes");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter the arrival time of process :%d ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("\nEnter the burst time of process :%d ", i + 1);
        scanf("%d", &p[i].burst_time);
    }
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        int completion = current_time + p[i].burst_time;
        p[i].tt = completion - p[i].arrival_time;
        p[i].waiting_time = p[i].tt - p[i].burst_time;
        current_time = current_time + p[i].burst_time;
    }

    for (int i = 0; i < n; i++) {
        printf("\nprocess: %d\tarrival time: %d\tburst time: %d\ttt: %d\twaiting time:%d", i + 1, p[i].arrival_time,
               p[i].burst_time, p[i].tt, p[i].waiting_time);


    }


}