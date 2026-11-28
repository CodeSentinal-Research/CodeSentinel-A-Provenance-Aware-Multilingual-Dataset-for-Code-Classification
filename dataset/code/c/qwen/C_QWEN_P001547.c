#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int cur = 0, max_odd = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(i < k && arr[i]%2 != 0) cur++;
    }
    max_odd = cur;
    for(int i=k; i<n; i++) {
        if(arr[i]%2 != 0) cur++;
        if(arr[i-k]%2 != 0) cur--;
        if(cur > max_odd) max_odd = cur;
    }
    printf("%d\n", max_odd);
    return 0;
}
