function maxSumTwoNoOverlap(nums, firstLen, secondLen) {
    function helper(L, M) {
        let sumL = 0, sumM = 0;
        for (let i = 0; i < L; i++) sumL += nums[i];
        for (let i = L; i < L + M; i++) sumM += nums[i];

        let maxL = sumL;
        let ans = sumL + sumM;

        for (let i = L + M; i < nums.length; i++) {
            sumL += nums[i - M] - nums[i - L - M];
            maxL = Math.max(maxL, sumL);
            sumM += nums[i] - nums[i - M];
            ans = Math.max(ans, maxL + sumM);
        }
        return ans;
    }

    return Math.max(helper(firstLen, secondLen), helper(secondLen, firstLen));
}

module.exports = { maxSumTwoNoOverlap };