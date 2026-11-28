int mostFrequent(int* nums, int n) {
    int best = 0, res = nums[0];
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) if (nums[j] == nums[i]) cnt++;
        if (cnt > best) { best = cnt; res = nums[i]; }
    }
    return res;
}
