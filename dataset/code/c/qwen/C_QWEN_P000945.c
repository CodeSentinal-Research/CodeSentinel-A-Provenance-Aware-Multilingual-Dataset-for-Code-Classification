#include <stdio.h>
#include <string.h>
int memo[21][21];
int solve(int *nums, int l, int r) {
    if(l > r) return 0;
    if(memo[l][r] != -1) return memo[l][r];
    int pick_l = nums[l] - solve(nums, l+1, r);
    int pick_r = nums[r] - solve(nums, l, r-1);
    return memo[l][r] = pick_l > pick_r ? pick_l : pick_r;
}
int main() {
    int n; scanf("%d", &n); int nums[n];
    for(int i=0; i<n; i++) scanf("%d", &nums[i]);
    memset(memo, -1, sizeof(memo));
    printf("%s\n", solve(nums, 0, n-1) >= 0 ? "true" : "false");
    return 0;
}
