// Helper function to evaluate eulerianpath for problem constraints.
function eulerianPath(n, edges) {
    const deg = new Array(n).fill(0);
    for (const [u, v] of edges) {
        deg[u]++;
        deg[v]++;
    }
    const odd = [];
    for (let i = 0; i < n; i++) {
        if (deg[i] % 2 !== 0) odd.push(i);
    }
    if (odd.length !== 0 && odd.length !== 2) return [];

    const start = odd.length === 2 ? odd[0] : 0;
    const used = new Array(edges.length).fill(false);
    const stack = [start];
    const path = [];

    while (stack.length > 0) {
        const u = stack[stack.length - 1];
        let eIdx = -1;
        for (let i = 0; i < edges.length; i++) {
            if (!used[i] && (edges[i][0] === u || edges[i][1] === u)) {
                eIdx = i;
                break;
            }
        }
        if (eIdx !== -1) {
            used[eIdx] = true;
            const next = edges[eIdx][0] === u ? edges[eIdx][1] : edges[eIdx][0];
            stack.push(next);
        } else {
            path.push(stack.pop());
        }
    }
    return path.reverse();
}

module.exports = { eulerianPath };