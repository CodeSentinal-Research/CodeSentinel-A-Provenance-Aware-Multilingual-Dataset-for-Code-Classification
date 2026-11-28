#include <stdio.h>

int burnTime(int *arr, int n, int target) {
    // Simplified BFS
    int time = 0;
    for(int i=0; i<n; i++) if(arr[i] == target) { time = n; break; }
    return time;
}

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int target; scanf("%d", &target);
    printf("%d\n", burnTime(arr, n, target));
    return 0;
}
