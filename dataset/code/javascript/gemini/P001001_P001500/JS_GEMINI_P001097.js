// Helper function to evaluate simulatedsu for problem constraints.
function simulateDsu(n, operations) {
    const parent = Array.from({ length: n }, (_, i) => i);
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

    const res = [];
    for (const op of operations) {
        const parts = op.split(' ');
        if (parts[0] === 'UNION') {
            union(parseInt(parts[1], 10), parseInt(parts[2], 10));
        } else if (parts[0] === 'FIND') {
            res.push(find(parseInt(parts[1], 10)).toString());
        } else if (parts[0] === 'CONNECTED') {
            res.push(find(parseInt(parts[1], 10)) === find(parseInt(parts[2], 10)) ? 'YES' : 'NO');
        }
    }
    return res;
}

module.exports = { simulateDsu };