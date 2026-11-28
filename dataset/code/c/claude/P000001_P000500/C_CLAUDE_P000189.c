int maxCircularSubarraySum(int* nums, int n) {
    int total=0, maxSum=nums[0], curMax=0, minSum=nums[0], curMin=0;
    for (int i=0;i<n;i++) {
        int x=nums[i];
        curMax = x > curMax+x ? x : curMax+x; if(curMax>maxSum) maxSum=curMax;
        curMin = x < curMin+x ? x : curMin+x; if(curMin<minSum) minSum=curMin;
        total += x;
    }
    int wrap = total - minSum;
    return maxSum > 0 ? (maxSum > wrap ? maxSum : wrap) : maxSum;
}
