#include <stdio.h>
#include <limits.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        int max_val = INT_MIN;
        for(int i=start; i<=end; i++) if(arr[i] > max_val) max_val = arr[i];
        printf("%d%c", max_val, end>=n-1?'\n':' ');
        start = end + 1;
        level *= 2;
    }
    return 0;
}
