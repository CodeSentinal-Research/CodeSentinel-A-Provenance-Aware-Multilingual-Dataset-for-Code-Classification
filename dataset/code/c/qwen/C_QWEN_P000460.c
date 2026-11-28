#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1, peak=-1;
    while(l<r) {
        int mid = l+(r-l)/2;
        if(arr[mid]>arr[mid+1]) r=mid; else l=mid+1;
    }
    peak = l;
    if(arr[peak]==target) { printf("%d\n", peak); return 0; }
    l=0; r=peak-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(arr[mid]==target) { printf("%d\n", mid); return 0; }
        else if(arr[mid]<target) l=mid+1; else r=mid-1;
    }
    l=peak+1; r=n-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(arr[mid]==target) { printf("%d\n", mid); return 0; }
        else if(arr[mid]<target) r=mid-1; else l=mid+1;
    }
    printf("-1\n");
    return 0;
}
