// Helper function to evaluate findcirclenum for problem constraints.
function findCircleNum(isConnected) {
    const n = isConnected.length;
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }

    let provinces = n;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (isConnected[i][j]) {
                const ri = find(i), rj = find(j);
                if (ri !== rj) {
                    parent[ri] = rj;
                    provinces--;
                }
            }
        }
    }
    return provinces;
}

module.exports = { findCircleNum };