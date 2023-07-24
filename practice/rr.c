#include <stdio.h>
#include <stdlib.h>


struct process {
    int arrival_time, burst_time, tt, waiting_time, completed_time, remaining_time;
};

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, TQ, remaining;
    printf("Enter the number of processes");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter the arrival time of process :%d ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("\nEnter the burst time of process :%d ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;

    }
    remaining = n;
    printf("\nEnter time quantum");
    scanf("%d", &TQ);
    int current_time = 0;
    while (remaining) {
        for (int i = 0; i < n; ++i) {
            if (p[i].remaining_time <= 0 || p[i].arrival_time > current_time) {
                continue;
            }

            current_time += min(p[i].remaining_time, TQ);
            p[i].remaining_time -= min(p[i].remaining_time, TQ);

            if (p[i].remaining_time == 0) {
                printf("process %d completed", i + 1);
                remaining--;
                p[i].completed_time = current_time;
            }
        }
    }
    for (int i = 0; i < n; i++) {

        p[i].tt = p[i].completed_time - p[i].arrival_time;
        p[i].waiting_time = p[i].tt - p[i].burst_time;
        current_time += p[i].tt;
    }

    float avg_tt = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        printf("\nprocess: %d\tarrival time: %d\tburst time: %d\ttt: %d\twaiting time:%d\tcompleted time: %d", i + 1,
               p[i].arrival_time,
               p[i].burst_time, p[i].tt, p[i].waiting_time, p[i].completed_time);
        avg_tt += p[i].tt;
        avg_wt += p[i].waiting_time;
    }
    avg_wt /= n;
    avg_tt /= n;

    printf("\nAverage waiting time =%f\nAverage TT = %f", avg_wt, avg_tt);
}
