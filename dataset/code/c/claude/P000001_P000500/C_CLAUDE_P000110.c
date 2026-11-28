int countFrequency(int* nums, int n, int target) {
    int cnt = 0;
    for (int i = 0; i < n; i++) if (nums[i] == target) cnt++;
    return cnt;
}
