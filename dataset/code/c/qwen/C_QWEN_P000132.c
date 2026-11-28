#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    long long total = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); total += arr[i]; }
    long long left_sum = 0;
    for(int i=0; i<n; i++) {
        if(left_sum == total - left_sum - arr[i]) { printf("%d\n", i); return 0; }
        left_sum += arr[i];
    }
    printf("-1\n");
    return 0;
}
