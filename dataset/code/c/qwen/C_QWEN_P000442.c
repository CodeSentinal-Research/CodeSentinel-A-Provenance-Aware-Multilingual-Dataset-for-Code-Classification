#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1, idx=-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(arr[mid]==target) { idx=mid; break; }
        if(arr[l]==arr[mid] && arr[mid]==arr[r]) { l++; r--; }
        else if(arr[l]<=arr[mid]) {
            if(arr[l]<=target && target<arr[mid]) r=mid-1; else l=mid+1;
        } else {
            if(arr[mid]<target && target<=arr[r]) l=mid+1; else r=mid-1;
        }
    }
    printf("%d\n", idx);
    return 0;
}
