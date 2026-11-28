#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int deepest = -1, val = -1;
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        for(int i=start; i<=end; i++) {
            if(i%2==1 && arr[i] != -1) { deepest = level; val = arr[i]; break; }
        }
        start = end + 1;
        level *= 2;
    }
    printf("%d\n", val);
    return 0;
}
