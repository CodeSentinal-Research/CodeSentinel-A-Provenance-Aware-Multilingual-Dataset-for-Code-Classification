#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) {
        int idx = arr[i] < 0 ? -arr[i] - 1 : arr[i] - 1;
        if(arr[idx] < 0) printf("%d ", idx + 1);
        else arr[idx] = -arr[idx];
    }
    printf("\n");
    return 0;
}
