#include <stdio.h>
int main() {
    int n, k, d; scanf("%d %d %d", &n, &k, &d);
    int arr[n];
    long long sum = 0;
    int count = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k) sum += arr[i];
    }
    if(sum % d == 0) count++;
    for(int i=k; i<n; i++) {
        sum += arr[i] - arr[i-k];
        if(sum % d == 0) count++;
    }
    printf("%d\n", count);
    return 0;
}
