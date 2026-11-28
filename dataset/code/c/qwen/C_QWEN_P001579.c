#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int cur = 0, max_neg = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k && arr[i] < 0) cur++;
    }
    max_neg = cur;
    for(int i=k; i<n; i++) {
        if(arr[i] < 0) cur++;
        if(arr[i-k] < 0) cur--;
        if(cur > max_neg) max_neg = cur;
    }
    printf("%d\n", max_neg);
    return 0;
}
