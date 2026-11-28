#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1;
    while(l<r) {
        int mid = l+(r-l)/2;
        if(arr[mid]<arr[r]) r=mid; else l=mid+1;
    }
    int max_idx = (l-1+n)%n;
    printf("%d\n", arr[max_idx]);
    return 0;
}
