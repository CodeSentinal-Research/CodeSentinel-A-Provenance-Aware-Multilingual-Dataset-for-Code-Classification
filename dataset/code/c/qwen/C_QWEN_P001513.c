#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    int distinct = 0, count[100001] = {0};
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        if(count[arr[i]] == 0) distinct++;
        count[arr[i]]++;
    }
    int l=0, ans=0;
    int cur_distinct = 0, cur_count[100001] = {0};
    for(int r=0; r<n; r++) {
        if(cur_count[arr[r]] == 0) cur_distinct++;
        cur_count[arr[r]]++;
        while(cur_distinct == distinct) {
            ans += n - r;
            cur_count[arr[l]]--;
            if(cur_count[arr[l]] == 0) cur_distinct--;
            l++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
