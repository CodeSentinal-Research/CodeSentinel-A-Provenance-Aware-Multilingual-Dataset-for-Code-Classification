function countDistinct(nums, k) {
    const freq = new Map(), res = [];
    for (let i = 0; i < nums.length; i++) {
        freq.set(nums[i], (freq.get(nums[i])||0)+1);
        if (i >= k) {
            const old = nums[i-k];
            freq.set(old, freq.get(old)-1);
            if (freq.get(old) === 0) freq.delete(old);
        }
        if (i >= k-1) res.push(freq.size);
    }
    return res;
}
module.exports = { countDistinct };
