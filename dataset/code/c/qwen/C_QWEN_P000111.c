#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max1 = -2000000000, max2 = -2000000000;
    for(int i=0; i<n; i++) {
        if(arr[i] > max1) { max2 = max1; max1 = arr[i]; }
        else if(arr[i] > max2 && arr[i] < max1) max2 = arr[i];
    }
    printf("%d\n", max2 == -2000000000 ? -1 : max2);
    return 0;
}
