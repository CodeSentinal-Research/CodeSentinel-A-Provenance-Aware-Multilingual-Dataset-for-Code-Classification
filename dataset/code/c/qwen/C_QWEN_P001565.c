#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int dq[n];
    int front=0, rear=0;
    for(int i=0; i<n; i++) {
        while(rear > front && arr[dq[rear-1]] <= arr[i]) rear--;
        dq[rear++] = i;
        if(dq[front] <= i - k) front++;
        if(i >= k - 1) printf("%d ", arr[dq[front]]);
    }
    printf("\n");
    return 0;
}
