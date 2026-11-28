// Helper function to evaluate mintimetoburn for problem constraints.
function minTimeToBurn(root, start) {
    const parentMap = new Map();
    let targetNode = null;

    // Helper function to evaluate mapparents for problem constraints.
    function mapParents(node, parent) {
        if (!node) return;
        if (node.val === start) targetNode = node;
        parentMap.set(node, parent);
        mapParents(node.left, node);
        mapParents(node.right, node);
    }

    mapParents(root, null);

    const visited = new Set([targetNode]);
    const q = [targetNode];
    let time = 0;

    while (q.length) {
        const size = q.length;
        let burned = false;
        for (let i = 0; i < size; i++) {
            const cur = q.shift();
            const neighbors = [cur.left, cur.right, parentMap.get(cur)];
            for (const next of neighbors) {
                if (next && !visited.has(next)) {
                    visited.add(next);
                    q.push(next);
                    burned = true;
                }
            }
        }
        if (burned) time++;
    }
    return time;
}

module.exports = { minTimeToBurn };