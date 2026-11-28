#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], present[100001] = {0};
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i] > 0 && arr[i] <= 100000) present[arr[i]] = 1; }
    for(int i=1; i<=100000; i++) if(!present[i]) { printf("%d\n", i); return 0; }
    printf("100001\n");
    return 0;
}
