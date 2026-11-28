#include <stdio.h>
int atMostK(int *arr, int n, int k) {
    if(k == 0) return 0;
    long long count = 0;
    int l = 0, distinct = 0, count_map[100001] = {0};
    for(int r=0; r<n; r++) {
        if(count_map[arr[r]] == 0) distinct++;
        count_map[arr[r]]++;
        while(distinct > k) {
            count_map[arr[l]]--;
            if(count_map[arr[l]] == 0) distinct--;
            l++;
        }
        count += r - l + 1;
    }
    return count;
}
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("%lld\n", atMostK(arr, n, k) - atMostK(arr, n, k-1));
    return 0;
}
