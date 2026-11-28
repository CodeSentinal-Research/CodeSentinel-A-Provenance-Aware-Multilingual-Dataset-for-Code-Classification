// Helper function to evaluate shortestsubarray for problem constraints.
function shortestSubarray(nums, k) {
    const n = nums.length;
    const prefix = new Array(n + 1).fill(0n);
    for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + BigInt(nums[i]);

    const dq = [];
    let minLen = n + 1;
    const target = BigInt(k);

    for (let i = 0; i <= n; i++) {
        while (dq.length && prefix[i] - prefix[dq[0]] >= target) {
            minLen = Math.min(minLen, i - dq.shift());
        }
        while (dq.length && prefix[i] <= prefix[dq[dq.length - 1]]) {
            dq.pop();
        }
        dq.push(i);
    }

    return minLen <= n ? minLen : -1;
}

module.exports = { shortestSubarray };