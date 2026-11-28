#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    // Reverse level order
    int level = 1, start = 0;
    int levels[1000], lvl_idx = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        levels[lvl_idx++] = start; // simplified
        start = end + 1;
        level *= 2;
    }
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    printf("\n");
    return 0;
}
