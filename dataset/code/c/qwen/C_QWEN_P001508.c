#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int count[100001] = {0};
    int l=0, types=0, max_len=0;
    for(int r=0; r<n; r++) {
        if(count[arr[r]] == 0) types++;
        count[arr[r]]++;
        while(types > 2) {
            count[arr[l]]--;
            if(count[arr[l]] == 0) types--;
            l++;
        }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
