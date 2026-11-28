#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int min_val = 1e9;
    for(int i=0; i<k; i++) { scanf("%d", &arr[i]); if(arr[i] < min_val) min_val = arr[i]; }
    printf("%d\n", min_val);
    return 0;
}
