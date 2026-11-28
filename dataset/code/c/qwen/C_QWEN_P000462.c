#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i=0; i<n-1; i++) scanf("%d", &arr[i]);
    int expected = arr[0] + (arr[n-2]-arr[0])/(n-1) * (n-1);
    int actual_sum = 0;
    for(int i=0; i<n-1; i++) actual_sum += arr[i];
    int full_sum = n * (arr[0] + expected) / 2;
    printf("%d\n", full_sum - actual_sum);
    return 0;
}
