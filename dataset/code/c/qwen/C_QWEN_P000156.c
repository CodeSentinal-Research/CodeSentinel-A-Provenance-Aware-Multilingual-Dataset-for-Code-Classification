#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], max_c = 0, curr = 0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i]==0) { curr++; if(curr>max_c) max_c=curr; } else curr=0; }
    printf("%d\n", max_c);
    return 0;
}
