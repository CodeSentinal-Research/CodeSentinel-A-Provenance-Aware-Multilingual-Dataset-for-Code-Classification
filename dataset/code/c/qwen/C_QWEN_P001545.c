#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int min_diff = 1e9;
    for(int i=0; i<=n-k; i++) {
        int min_val = arr[i], max_val = arr[i];
        for(int j=1; j<k; j++) {
            if(arr[i+j] < min_val) min_val = arr[i+j];
            if(arr[i+j] > max_val) max_val = arr[i+j];
        }
        if(max_val - min_val < min_diff) min_diff = max_val - min_val;
    }
    printf("%d\n", min_diff);
    return 0;
}
