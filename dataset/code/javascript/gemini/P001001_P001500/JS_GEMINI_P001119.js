// Helper function to evaluate calcequation for problem constraints.
function calcEquation(equations, values, queries) {
    const graph = new Map();
    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        const val = values[i];
        if (!graph.has(a)) graph.set(a, new Map());
        if (!graph.has(b)) graph.set(b, new Map());
        graph.get(a).set(b, val);
        graph.get(b).set(a, 1.0 / val);
    }

    return queries.map(([src, dst]) => {
        if (!graph.has(src) || !graph.has(dst)) return -1.0;
        if (src === dst) return 1.0;
        const q = [[src, 1.0]];
        const visited = new Set([src]);
        while (q.length > 0) {
            const [node, prod] = q.shift();
            if (node === dst) return prod;
            for (const [nxt, weight] of graph.get(node).entries()) {
                if (!visited.has(nxt)) {
                    visited.add(nxt);
                    q.push([nxt, prod * weight]);
                }
            }
        }
        return -1.0;
    });
}

module.exports = { calcEquation };