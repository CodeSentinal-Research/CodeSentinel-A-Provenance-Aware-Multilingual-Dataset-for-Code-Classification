#include <stdio.h>
int main() {
    int n, sum; scanf("%d %d", &n, &sum);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    long long curr = 0;
    int left = 0;
    for(int right=0; right<n; right++) {
        curr += arr[right];
        while(curr > sum && left <= right) curr -= arr[left++];
        if(curr == sum) { printf("%d %d\n", left+1, right+1); return 0; }
    }
    printf("-1\n");
    return 0;
}
