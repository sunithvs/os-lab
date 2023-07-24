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
        if (current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;

        int completion = current_time + p[i].burst_time;
        p[i].tt = completion - p[i].arrival_time;
        p[i].waiting_time = p[i].tt - p[i].burst_time;
        current_time += p[i].tt;
    }
    float avg_tt = 0, avg_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("\nprocess: %d\tarrival time: %d\tburst time: %d\ttt: %d\twaiting time:%d", i + 1, p[i].arrival_time,
               p[i].burst_time, p[i].tt, p[i].waiting_time);
        avg_tt += p[i].tt;
        avg_wt += p[i].waiting_time;


    }
    avg_wt /= n;
    avg_tt /= n;

    printf("\nAverage waiting time =%f\nAverage TT = %f", avg_wt, avg_tt);


}
