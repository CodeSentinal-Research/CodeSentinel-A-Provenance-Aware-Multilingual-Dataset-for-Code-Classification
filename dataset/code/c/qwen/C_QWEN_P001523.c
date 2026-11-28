#include <stdio.h>
int main() {
    int n, limit; scanf("%d %d", &n, &limit);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0;
    int min_q[100001], max_q[100001], min_f=0, min_r=0, max_f=0, max_r=0;
    for(int r=0; r<n; r++) {
        while(min_r > min_f && arr[min_q[min_r-1]] >= arr[r]) min_r--;
        min_q[min_r++] = r;
        while(max_r > max_f && arr[max_q[max_r-1]] <= arr[r]) max_r--;
        max_q[max_r++] = r;
        while(arr[max_q[max_f]] - arr[min_q[min_f]] > limit) {
            if(min_q[min_f] == l) min_f++;
            if(max_q[max_f] == l) max_f++;
            l++;
        }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
