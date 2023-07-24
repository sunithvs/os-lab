#include <stdio.h>

struct process {
    int id, burst_time, tt, waiting_time;
    int completed;
};

void swap(struct process *p1, struct process *p2) {
    struct process tmp;
    printf("\nswapping %d and %d", p1->id, p2->id);
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main() {
    int n;
    printf("Enter the number of processes");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter the burst time of process :%d ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].id = i + 1;
    }
    // sort based on burst time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burst_time > p[j + 1].burst_time) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
    int current_time=0;
    for (int i = 0; i < n; i++) {
        int completion = current_time + p[i].burst_time;
        p[i].tt = completion ;
        p[i].waiting_time = p[i].tt - p[i].burst_time;
        current_time += p[i].tt;
    }
    float avg_tt = 0, avg_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("\nprocess: %d\tburst time: %d\ttt: %d\twaiting time:%d", p[i].id,
               p[i].burst_time, p[i].tt, p[i].waiting_time);
        avg_tt += p[i].tt;
        avg_wt += p[i].waiting_time;


    }
    avg_wt /= n;
    avg_tt /= n;

    printf("\nAverage waiting time =%f\nAverage TT = %f", avg_wt, avg_tt);
}
