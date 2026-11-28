#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    long long sum = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k) sum += arr[i];
    }
    printf("%.2f ", (double)sum / k);
    for(int i=k; i<n; i++) {
        sum += arr[i] - arr[i-k];
        printf("%.2f ", (double)sum / k);
    }
    printf("\n");
    return 0;
}
