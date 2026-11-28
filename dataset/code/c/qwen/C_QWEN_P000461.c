#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1, idx=-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(arr[mid]==1) { idx=mid; r=mid-1; } else l=mid+1;
    }
    printf("%d\n", idx);
    return 0;
}
