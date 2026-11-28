int getMaxLen(int* nums, int n) {
    int pos = 0, neg = 0, best = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (x == 0) { pos = neg = 0; }
        else if (x > 0) { pos++; neg = neg > 0 ? neg+1 : 0; }
        else { int np = neg>0 ? neg+1 : 0; neg = pos+1; pos = np; }
        if (pos > best) best = pos;
    }
    return best;
}
