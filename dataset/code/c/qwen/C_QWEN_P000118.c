#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], j = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) if(arr[i] != 0) arr[j++] = arr[i];
    while(j < n) arr[j++] = 0;
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
