// Helper function to evaluate equalpairs for problem constraints.
function equalPairs(grid) {
    const n = grid.length;
    const map = new Map();

    for (const row of grid) {
        const key = row.join(',');
        map.set(key, (map.get(key) || 0) + 1);
    }

    let ans = 0;
    for (let c = 0; c < n; c++) {
        const col = [];
        for (let r = 0; r < n; r++) col.push(grid[r][c]);
        ans += (map.get(col.join(',')) || 0);
    }
    return ans;
}

module.exports = { equalPairs };