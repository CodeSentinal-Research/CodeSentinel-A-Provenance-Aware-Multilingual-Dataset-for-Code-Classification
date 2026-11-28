#include <stdio.h>
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[1000];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int found = 0;
    for(int i=0; i<n-2 && !found; i++) {
        int l=i+1, r=n-1;
        while(l<r && !found) {
            int sum = arr[i]+arr[l]+arr[r];
            if(sum==target) found=1;
            else if(sum<target) l++; else r--;
        }
    }
    printf("%s\n", found ? "Yes" : "No");
    return 0;
}
