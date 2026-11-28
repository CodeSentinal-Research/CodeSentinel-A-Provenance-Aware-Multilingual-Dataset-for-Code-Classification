#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int closest = arr[0];
    for(int i=1; i<n; i++) if(abs(arr[i]-target) < abs(closest-target)) closest = arr[i];
    printf("%d\n", closest);
    return 0;
}
