// Helper function to evaluate mincosttohireworkers for problem constraints.
function mincostToHireWorkers(quality, wage, k) {
    const workers = quality.map((q, i) => [wage[i] / q, q]).sort((a, b) => a[0] - b[0]);
    const pq = [];
    let qualSum = 0, minCost = Infinity;

    for (const [ratio, q] of workers) {
        let l = 0, r = pq.length;
        while (l < r) {
            const m = Math.floor((l + r) / 2);
            if (pq[m] < q) l = m + 1;
            else r = m;
        }
        pq.splice(l, 0, q);
        qualSum += q;

        if (pq.length > k) {
            qualSum -= pq.pop();
        }
        if (pq.length === k) {
            minCost = Math.min(minCost, qualSum * ratio);
        }
    }
    return minCost;
}

module.exports = { mincostToHireWorkers };