#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int jumps = 0, cur_end = 0, max_reach = 0;
    for(int i=0; i<n-1; i++) {
        if(i + a[i] > max_reach) max_reach = i + a[i];
        if(i == cur_end) { jumps++; cur_end = max_reach; }
    }
    printf("%d\n", jumps);
    return 0;
}
