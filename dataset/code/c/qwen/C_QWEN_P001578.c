#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int arr[n];
    int distinct = 0, count_map[100001] = {0};
    int count = 0;
    for(int i=0; i<k; i++) {
        scanf("%d", &arr[i]);
        if(count_map[arr[i]] == 0) distinct++;
        count_map[arr[i]]++;
    }
    if(distinct == k) count++;
    for(int i=k; i<n; i++) {
        scanf("%d", &arr[i]);
        count_map[arr[i]]++;
        if(count_map[arr[i]] == 1) distinct++;
        count_map[arr[i-k]]--;
        if(count_map[arr[i-k]] == 0) distinct--;
        if(distinct == k) count++;
    }
    printf("%d\n", count);
    return 0;
}
