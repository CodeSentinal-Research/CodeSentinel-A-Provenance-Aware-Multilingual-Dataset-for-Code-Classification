#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[n], idx = -1;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i] == target && idx == -1) idx = i; }
    printf("%d\n", idx);
    return 0;
}
