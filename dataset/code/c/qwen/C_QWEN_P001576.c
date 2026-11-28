#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int zeros = 0, count = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k && arr[i] == 0) zeros++;
    }
    if(zeros > 0) count++;
    for(int i=k; i<n; i++) {
        if(arr[i] == 0) zeros++;
        if(arr[i-k] == 0) zeros--;
        if(zeros > 0) count++;
    }
    printf("%d\n", count);
    return 0;
}
