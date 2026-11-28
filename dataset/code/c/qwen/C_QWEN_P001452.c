#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int nums[n];
    int present[100001] = {0};
    int distinct = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (!present[nums[i]]) {
            present[nums[i]] = 1;
            distinct++;
        }
    }
    
    for (int i = 0; i < q; i++) {
        int idx, val;
        scanf("%d %d", &idx, &val);
        idx--;
        if (present[nums[idx]] == 1) {
            // check if another instance exists
            int count = 0;
            for(int j=0; j<n; j++) if(nums[j]==nums[idx]) count++;
            if(count == 1) distinct--;
            present[nums[idx]] = 0; // simplified
        }
        nums[idx] = val;
        if (!present[val]) {
            present[val] = 1;
            distinct++;
        }
        printf("%d\n", distinct);
    }
    return 0;
}
