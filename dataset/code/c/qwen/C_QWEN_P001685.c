#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int target; scanf("%d", &target);
    int idx = -1;
    for(int i=0; i<n; i++) if(arr[i] == target) { idx = i; break; }
    if(idx != -1 && idx + 1 < n) printf("%d\n", arr[idx+1]);
    else printf("NONE\n");
    return 0;
}
