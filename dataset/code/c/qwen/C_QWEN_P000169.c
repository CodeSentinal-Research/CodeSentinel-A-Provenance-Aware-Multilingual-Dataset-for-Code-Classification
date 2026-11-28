#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int seen[2000001] = {0};
    for(int i=0; i<n; i++) {
        int idx = arr[i] + 1000000;
        if(seen[idx]) { printf("%d\n", arr[i]); return 0; }
        seen[idx] = 1;
    }
    printf("-1\n");
    return 0;
}
