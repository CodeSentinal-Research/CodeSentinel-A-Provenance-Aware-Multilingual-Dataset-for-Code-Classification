// Helper function to evaluate maxnumedgestoremove for problem constraints.
function maxNumEdgesToRemove(n, edges) {
    const parentA = Array.from({ length: n + 1 }, (_, i) => i);
    const parentB = Array.from({ length: n + 1 }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(parent, i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    let used = 0, edgesA = 0, edgesB = 0;

    for (const [type, u, v] of edges) {
        if (type === 3) {
            const rA1 = find(parentA, u), rA2 = find(parentA, v);
            const rB1 = find(parentB, u), rB2 = find(parentB, v);
            if (rA1 !== rA2 || rB1 !== rB2) {
                parentA[rA1] = rA2;
                parentB[rB1] = rB2;
                used++;
                edgesA++;
                edgesB++;
            }
        }
    }

    for (const [type, u, v] of edges) {
        if (type === 1) {
            const r1 = find(parentA, u), r2 = find(parentA, v);
            if (r1 !== r2) {
                parentA[r1] = r2;
                used++;
                edgesA++;
            }
        } else if (type === 2) {
            const r1 = find(parentB, u), r2 = find(parentB, v);
            if (r1 !== r2) {
                parentB[r1] = r2;
                used++;
                edgesB++;
            }
        }
    }

    return (edgesA === n - 1 && edgesB === n - 1) ? edges.length - used : -1;
}

module.exports = { maxNumEdgesToRemove };