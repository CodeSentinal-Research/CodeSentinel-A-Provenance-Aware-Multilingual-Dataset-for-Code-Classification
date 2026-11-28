#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int max_val = -1e9;
    for(int i=0; i<k; i++) { scanf("%d", &arr[i]); if(arr[i] > max_val) max_val = arr[i]; }
    printf("%d\n", max_val);
    return 0;
}
