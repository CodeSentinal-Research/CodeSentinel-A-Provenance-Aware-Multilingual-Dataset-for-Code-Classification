// Helper function to evaluate findmaximizedcapital for problem constraints.
function findMaximizedCapital(k, w, profits, capital) {
    const projects = capital.map((c, i) => [c, profits[i]]).sort((a, b) => a[0] - b[0]);
    const pq = [];
    let i = 0, n = projects.length;

    for (let step = 0; step < k; step++) {
        while (i < n && projects[i][0] <= w) {
            pq.push(projects[i++][1]);
        }
        if (pq.length === 0) break;
        pq.sort((a, b) => b - a);
        w += pq.shift();
    }
    return w;
}

module.exports = { findMaximizedCapital };