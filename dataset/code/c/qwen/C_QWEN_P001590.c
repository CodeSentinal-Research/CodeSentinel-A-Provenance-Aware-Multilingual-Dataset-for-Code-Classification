#include <stdio.h>
int main() {
    int n; long long budget; scanf("%d %lld", &n, &budget);
    long long charge[n], run[n];
    for(int i=0; i<n; i++) scanf("%lld", &charge[i]);
    for(int i=0; i<n; i++) scanf("%lld", &run[i]);
    int max_robots = 0, l = 0;
    long long sum_run = 0, max_charge = 0;
    int dq[n]; int front=0, rear=0;
    for(int r=0; r<n; r++) {
        sum_run += run[r];
        while(rear > front && charge[dq[rear-1]] <= charge[r]) rear--;
        dq[rear++] = r;
        if(dq[front] <= r - (r - l + 1) + 1) {} // wait
        while(front < rear && (r - l + 1) * sum_run + charge[dq[front]] > budget) {
            sum_run -= run[l];
            if(dq[front] == l) front++;
            l++;
        }
        if(r - l + 1 > max_robots) max_robots = r - l + 1;
    }
    printf("%d\n", max_robots);
    return 0;
}
