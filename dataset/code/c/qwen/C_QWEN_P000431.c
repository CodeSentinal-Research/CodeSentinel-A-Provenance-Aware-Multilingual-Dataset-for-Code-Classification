#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000], count = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i]==target) count++; }
    printf("%d\n", count);
    return 0;
}
