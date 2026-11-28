// Helper function to evaluate minimumeffortpath for problem constraints.
function minimumEffortPath(heights) {
    const m = heights.length, n = heights[0].length;
    const dist = Array.from({ length: m }, () => new Array(n).fill(Infinity));
    dist[0][0] = 0;

    const pq = [[0, 0, 0]];
    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];

    while (pq.length > 0) {
        pq.sort((a, b) => a[0] - b[0]);
        const [d, r, c] = pq.shift();
        if (r === m - 1 && c === n - 1) return d;
        if (d > dist[r][c]) continue;

        for (const [dr, dc] of dirs) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                const effort = Math.max(d, Math.abs(heights[nr][nc] - heights[r][c]));
                if (effort < dist[nr][nc]) {
                    dist[nr][nc] = effort;
                    pq.push([effort, nr, nc]);
                }
            }
        }
    }
    return 0;
}

module.exports = { minimumEffortPath };