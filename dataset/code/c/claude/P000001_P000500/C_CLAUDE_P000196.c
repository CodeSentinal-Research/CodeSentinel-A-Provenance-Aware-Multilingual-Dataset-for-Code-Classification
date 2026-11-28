long long largestSumK(int* nums, int n, int k) {
    long long win = 0;
    for (int i=0;i<k;i++) win+=nums[i];
    long long best = win;
    for (int i=k;i<n;i++) {
        win+=nums[i]-nums[i-k];
        if(win>best) best=win;
    }
    return best;
}
