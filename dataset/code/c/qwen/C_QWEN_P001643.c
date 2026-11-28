#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_width = 0;
    int level = 1, start = 0;
    while(start < n) {
        int end = start + level - 1;
        if(end >= n) end = n - 1;
        int width = end - start + 1;
        if(width > max_width) max_width = width;
        start = end + 1;
        level *= 2;
    }
    printf("%d\n", max_width);
    return 0;
}
