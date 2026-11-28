#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int max_len = 0, l = 0, distinct = 0, count_map[100001] = {0};
    for(int r=0; r<n; r++) {
        if(count_map[arr[r]] == 0) distinct++;
        count_map[arr[r]]++;
        while(distinct > k) {
            count_map[arr[l]]--;
            if(count_map[arr[l]] == 0) distinct--;
            l++;
        }
        if(r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
