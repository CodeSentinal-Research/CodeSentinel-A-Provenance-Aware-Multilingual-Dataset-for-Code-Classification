#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long max_sum = -1e18;
    int max_level = 0;
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        long long sum = 0;
        for(int i=start; i<=end; i++) if(arr[i] != -1) sum += arr[i];
        if(sum > max_sum) { max_sum = sum; max_level = level; }
        start = end + 1;
        level *= 2;
    }
    printf("%d\n", max_level);
    return 0;
}
