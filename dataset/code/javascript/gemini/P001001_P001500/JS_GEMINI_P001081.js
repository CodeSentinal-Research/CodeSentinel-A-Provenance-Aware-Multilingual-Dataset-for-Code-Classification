// Helper function to evaluate euleriancircuit for problem constraints.
function eulerianCircuit(n, edges) {
    const deg = new Array(n).fill(0);
    const adj = Array.from({ length: n }, () => []);
    const edgeMap = new Map();

    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
        deg[u]++;
        deg[v]++;
        const k1 = `${u},${v}`, k2 = `${v},${u}`;
        edgeMap.set(k1, (edgeMap.get(k1) || 0) + 1);
        edgeMap.set(k2, (edgeMap.get(k2) || 0) + 1);
    }

    if (deg.some(d => d % 2 !== 0)) return [];

    const stack = [0];
    const circuit = [];
    while (stack.length > 0) {
        const u = stack[stack.length - 1];
        let found = false;
        for (const v of adj[u]) {
            const k1 = `${u},${v}`, k2 = `${v},${u}`;
            if (edgeMap.get(k1) > 0) {
                edgeMap.set(k1, edgeMap.get(k1) - 1);
                edgeMap.set(k2, edgeMap.get(k2) - 1);
                stack.push(v);
                found = true;
                break;
            }
        }
        if (!found) circuit.push(stack.pop());
    }
    return circuit.reverse();
}

module.exports = { eulerianCircuit };