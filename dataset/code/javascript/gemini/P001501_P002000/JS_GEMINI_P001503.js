// Helper function to evaluate minmoves for problem constraints.
function minMoves(nums, k) {
    const p = [];
    nums.forEach((x, i) => { if (x === 1) p.push(i); });
    const n = p.length;
    const presum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) presum[i + 1] = presum[i] + p[i];

    let ans = Infinity;
    const radius = Math.floor((k - 1) / 2);

    for (let i = radius; i < n - k + radius + 1; i++) {
        const right = presum[i + k - radius] - presum[i + 1];
        const left = presum[i] - presum[i - radius];
        ans = Math.min(ans, right - left);
    }

    let offset = radius * (radius + 1);
    if (k % 2 === 0) offset += (radius + 1);
    return ans - offset;
}

module.exports = { minMoves };