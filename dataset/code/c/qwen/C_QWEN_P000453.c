#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1, fp=-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(arr[mid]==mid) { fp=mid; r=mid-1; }
        else if(arr[mid]<mid) l=mid+1; else r=mid-1;
    }
    printf("%d\n", fp);
    return 0;
}
