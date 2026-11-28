#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int chunks = 0, max_val = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > max_val) max_val = arr[i];
        if(max_val == i) chunks++;
    }
    printf("%d\n", chunks);
    return 0;
}
