#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int first = 1;
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        if(arr[start] != -1) { if(!first) printf(" "); printf("%d", arr[start]); first=0; }
        start = end + 1;
        level *= 2;
    }
    printf("\n");
    return 0;
}
