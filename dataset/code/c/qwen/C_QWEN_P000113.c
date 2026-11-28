#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], j = 0;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) if(i==0 || arr[i] != arr[i-1]) arr[j++] = arr[i];
    printf("%d\n", j);
    return 0;
}
