#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int min_len = 1e9, l = 0;
    long long sum = 0;
    for(int r=0; r<n; r++) {
        sum += arr[r];
        while(sum > 0) {
            if(r - l + 1 < min_len) min_len = r - l + 1;
            sum -= arr[l]; l++;
        }
    }
    printf("%d\n", min_len == 1e9 ? 0 : min_len);
    return 0;
}
