#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 1, cur = 1;
    for(int i=1; i<n; i++) {
        if(arr[i]%2 != arr[i-1]%2) { cur++; if(cur > max_len) max_len = cur; }
        else cur = 1;
    }
    printf("%d\n", max_len);
    return 0;
}
