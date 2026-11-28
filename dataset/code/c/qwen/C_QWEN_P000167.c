#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], max_l = 1, curr = 1;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i-1]) { curr++; if(curr > max_l) max_l = curr; }
        else curr = 1;
    }
    printf("%d\n", max_l);
    return 0;
}
