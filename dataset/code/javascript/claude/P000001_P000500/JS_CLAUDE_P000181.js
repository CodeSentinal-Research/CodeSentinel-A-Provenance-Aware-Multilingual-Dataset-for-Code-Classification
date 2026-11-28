function maxSumTwoNoOverlap(nums, firstLen, secondLen) {
    const n = nums.length;
    const pre = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) pre[i+1] = pre[i] + nums[i];
    const win = (r, l) => pre[r+1] - pre[r+1-l];
    function solve(L, M) {
        let best = 0, res = 0;
        for (let i = L+M-1; i < n; i++) {
            best = Math.max(best, win(i-M, L));
            res = Math.max(res, best + win(i, M));
        }
        return res;
    }
    return Math.max(solve(firstLen, secondLen), solve(secondLen, firstLen));
}
module.exports = { maxSumTwoNoOverlap };
