#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int idx = -1;
    for(int i=0; i<n; i++) if(arr[i]==target) { idx=i; break; }
    printf("%d\n", idx);
    return 0;
}
