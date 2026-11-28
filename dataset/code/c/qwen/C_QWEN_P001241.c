#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int gas[n], cost[n];
    for(int i=0; i<n; i++) scanf("%d", &gas[i]);
    for(int i=0; i<n; i++) scanf("%d", &cost[i]);
    int total = 0, tank = 0, start = 0;
    for(int i=0; i<n; i++) {
        int diff = gas[i] - cost[i];
        total += diff; tank += diff;
        if(tank < 0) { start = i + 1; tank = 0; }
    }
    printf("%d\n", total >= 0 ? start : -1);
    return 0;
}
