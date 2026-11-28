// Helper function to evaluate findmaximizedcapital for problem constraints.
function findMaximizedCapital(k, w, profits, capital) {
    const projects = capital.map((c, i) => [c, profits[i]]).sort((a, b) => a[0] - b[0]);
    const n = projects.length;
    let idx = 0;
    const available = [];

    for (let step = 0; step < k; step++) {
        while (idx < n && projects[idx][0] <= w) {
            const p = projects[idx][1];
            let l = 0, r = available.length;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                const mid = Math.floor((l + r) / 2);
                if (available[mid] > p) l = mid + 1;
                else r = mid;
            }
            available.splice(l, 0, p);
            idx++;
        }
        if (available.length === 0) break;
        w += available.shift();
    }
    return w;
}

module.exports = { findMaximizedCapital };