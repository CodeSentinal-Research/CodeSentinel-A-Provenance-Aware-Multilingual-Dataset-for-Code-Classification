#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1, ceil=-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(arr[mid]>=target) { ceil=arr[mid]; r=mid-1; }
        else l=mid+1;
    }
    printf("%d\n", ceil);
    return 0;
}
