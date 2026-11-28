#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], count[2000001] = {0};
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); count[arr[i]+1000000]++; }
    for(int i=0; i<n; i++) if(count[arr[i]+1000000] == 1) { printf("%d\n", arr[i]); return 0; }
    printf("-1\n");
    return 0;
}
