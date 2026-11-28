void sortArray012(int* nums, int n) {
    int lo=0, mid=0, hi=n-1, t;
    while (mid<=hi) {
        if (nums[mid]==0) { t=nums[lo];nums[lo++]=nums[mid];nums[mid++]=t; }
        else if (nums[mid]==1) mid++;
        else { t=nums[mid];nums[mid]=nums[hi];nums[hi--]=t; }
    }
}
