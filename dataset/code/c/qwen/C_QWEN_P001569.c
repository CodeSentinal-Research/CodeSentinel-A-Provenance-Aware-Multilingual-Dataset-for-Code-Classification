#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_sum = 0, l = 0, cur_sum = 0;
    int seen[100001] = {0};
    for(int r=0; r<n; r++) {
        while(seen[arr[r]]) { seen[arr[l]] = 0; cur_sum -= arr[l]; l++; }
        seen[arr[r]] = 1;
        cur_sum += arr[r];
        if(cur_sum > max_sum) max_sum = cur_sum;
    }
    printf("%d\n", max_sum);
    return 0;
}
