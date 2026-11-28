#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1;
    while(l<r) {
        int mid = l+(r-l)/2;
        if(mid%2==0) {
            if(arr[mid]==arr[mid+1]) l=mid+2; else r=mid;
        } else {
            if(arr[mid]==arr[mid-1]) l=mid+1; else r=mid-1;
        }
    }
    printf("%d\n", arr[l]);
    return 0;
}
