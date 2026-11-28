#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int chunks = 0;
    int max_left[n], min_right[n];
    max_left[0] = arr[0];
    for(int i=1; i<n; i++) max_left[i] = arr[i] > max_left[i-1] ? arr[i] : max_left[i-1];
    min_right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) min_right[i] = arr[i] < min_right[i+1] ? arr[i] : min_right[i+1];
    for(int i=0; i<n-1; i++) {
        if(max_left[i] <= min_right[i+1]) chunks++;
    }
    printf("%d\n", chunks + 1);
    return 0;
}
