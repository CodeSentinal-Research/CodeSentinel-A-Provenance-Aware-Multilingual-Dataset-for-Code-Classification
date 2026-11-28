#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int missing = 0, idx = 0;
    for(int i=1; ; i++) {
        if(idx<n && arr[idx]==i) idx++;
        else { missing++; if(missing==k) { printf("%d\n", i); return 0; } }
    }
    return 0;
}
