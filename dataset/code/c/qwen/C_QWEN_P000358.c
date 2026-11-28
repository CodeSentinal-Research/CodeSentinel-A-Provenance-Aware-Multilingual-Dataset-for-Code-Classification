#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[100000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=0; i<n; i++) if(arr[i]<0) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}
