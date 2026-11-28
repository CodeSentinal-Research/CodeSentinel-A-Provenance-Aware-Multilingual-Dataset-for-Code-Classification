#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) if(arr[i] != -1) printf("%d%c", arr[i], i==n-1?'\n':' ');
    printf("\n");
    return 0;
}
