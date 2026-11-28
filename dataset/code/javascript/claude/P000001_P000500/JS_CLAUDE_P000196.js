function largestSumK(nums, k) {
    let win = nums.slice(0,k).reduce((a,b)=>a+b,0), best = win;
    for (let i=k;i<nums.length;i++) {
        win += nums[i]-nums[i-k];
        best = Math.max(best, win);
    }
    return best;
}
module.exports = { largestSumK };
