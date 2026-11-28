// Helper function to evaluate regionsbyslashes for problem constraints.
function regionsBySlashes(grid) {
    const n = grid.length;
    const parent = Array.from({ length: 4 * n * n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    // Helper function to evaluate union for problem constraints.
    function union(i, j) {
        const ri = find(i), rj = find(j);
        if (ri !== rj) parent[ri] = rj;
    }

    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            const root = 4 * (r * n + c);
            const val = grid[r][c];
            if (val !== '/') {
                union(root + 0, root + 1);
                union(root + 2, root + 3);
            }
            if (val !== '\\') {
                union(root + 0, root + 3);
                union(root + 1, root + 2);
            }
            if (r + 1 < n) {
                union(root + 2, 4 * ((r + 1) * n + c) + 0);
            }
            if (c + 1 < n) {
                union(root + 1, 4 * (r * n + c + 1) + 3);
            }
        }
    }

    let count = 0;
    for (let i = 0; i < 4 * n * n; i++) {
        if (find(i) === i) count++;
    }
    return count;
}

module.exports = { regionsBySlashes };