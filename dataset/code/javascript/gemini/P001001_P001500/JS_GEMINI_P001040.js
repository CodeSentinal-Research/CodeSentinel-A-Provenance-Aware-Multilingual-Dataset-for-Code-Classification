// Helper function to evaluate maxperformance for problem constraints.
function maxPerformance(n, speed, efficiency, k) {
    const MOD = 1000000007n;
    const engineers = [];
    for (let i = 0; i < n; i++) engineers.push([efficiency[i], speed[i]]);
    engineers.sort((a, b) => b[0] - a[0]);

    const heap = [];
    let speedSum = 0n;
    let best = 0n;

    for (const [eff, spd] of engineers) {
        let l = 0, r = heap.length;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (heap[mid] < spd) l = mid + 1;
            else r = mid;
        }
        heap.splice(l, 0, spd);
        speedSum += BigInt(spd);
        if (heap.length > k) {
            speedSum -= BigInt(heap.shift());
        }
        const cur = speedSum * BigInt(eff);
        if (cur > best) best = cur;
    }
    return Number(best % MOD);
}

module.exports = { maxPerformance };