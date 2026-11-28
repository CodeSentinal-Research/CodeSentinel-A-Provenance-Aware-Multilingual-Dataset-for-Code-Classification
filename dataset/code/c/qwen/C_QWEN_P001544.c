#include <stdio.h>
int main() {
    int n, k, x; scanf("%d %d %d", &n, &k, &x);
    int arr[n];
    long long sum = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k) sum += arr[i];
    }
    if(sum > x) count++;
    for(int i=k; i<n; i++) {
        sum += arr[i] - arr[i-k];
        if(sum > x) count++;
    }
    printf("%d\n", count);
    return 0;
}
