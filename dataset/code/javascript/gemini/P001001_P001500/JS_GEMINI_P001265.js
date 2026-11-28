// Helper function to evaluate maxperformance for problem constraints.
function maxPerformance(n, speed, efficiency, k) {
    const MOD = 1000000007n;
    const engineers = speed.map((spd, i) => [efficiency[i], spd]).sort((a, b) => b[0] - a[0]);

    const pq = [];
    let speedSum = 0n;
    let maxPerf = 0n;

    for (const [eff, spd] of engineers) {
        // binary insert to keep sorted
        let l = 0, r = pq.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (pq[m] < spd) l = m + 1;
            else r = m;
        }
        pq.splice(l, 0, spd);
        speedSum += BigInt(spd);

        if (pq.length > k) {
            const minSpd = pq.shift();
            speedSum -= BigInt(minSpd);
        }

        const perf = speedSum * BigInt(eff);
        if (perf > maxPerf) maxPerf = perf;
    }

    return Number(maxPerf % MOD);
}

module.exports = { maxPerformance };