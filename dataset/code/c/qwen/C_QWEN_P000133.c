#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], res[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l = 0, r = n - 1, idx = 0;
    while(l <= r) {
        if(idx % 2 == 0) res[idx++] = arr[r--];
        else res[idx++] = arr[l++];
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
