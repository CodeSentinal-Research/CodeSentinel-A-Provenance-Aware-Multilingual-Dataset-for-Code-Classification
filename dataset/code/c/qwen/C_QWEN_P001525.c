#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0, diff = 0;
    for(int r=0; r<n; r++) {
        if(arr[r] % 2 == 0) diff++; else diff--;
        while(diff != 0 && l <= r) {
            if(arr[l] % 2 == 0) diff--; else diff++;
            l++;
        }
        if(diff == 0 && r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
