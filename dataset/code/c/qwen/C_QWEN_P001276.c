#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int seats[n]; for(int i=0; i<n; i++) scanf("%d", &seats[i]);
    int max_dist = 0, last = -1;
    for(int i=0; i<n; i++) {
        if(seats[i] == 1) {
            if(last == -1) max_dist = i;
            else max_dist = max_dist > (i-last)/2 ? max_dist : (i-last)/2;
            last = i;
        }
    }
    if(last != -1 && n-1-last > max_dist) max_dist = n-1-last;
    printf("%d\n", max_dist);
    return 0;
}
