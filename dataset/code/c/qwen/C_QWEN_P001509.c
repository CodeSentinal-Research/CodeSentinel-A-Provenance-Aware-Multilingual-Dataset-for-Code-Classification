#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0, zeros = 0;
    for(int r=0; r<n; r++) {
        if(arr[r] == 0) zeros++;
        while(zeros > 1) { if(arr[l] == 0) zeros--; l++; }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len - 1);
    return 0;
}
