#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        if(level % 2 == 0) {
            for(int i=start, j=end; i<j; i++, j--) { int t=arr[i]; arr[i]=arr[j]; arr[j]=t; }
        }
        start = end + 1;
        level *= 2;
    }
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
