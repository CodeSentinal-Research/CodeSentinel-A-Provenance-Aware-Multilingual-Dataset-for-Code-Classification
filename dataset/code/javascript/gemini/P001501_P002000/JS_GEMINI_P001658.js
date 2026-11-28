// Helper function to evaluate distancek for problem constraints.
function distanceK(root, target, k) {
    const parentMap = new Map();

    // Helper function to evaluate mapparents for problem constraints.
    function mapParents(node, parent) {
        if (!node) return;
        parentMap.set(node, parent);
        mapParents(node.left, node);
        mapParents(node.right, node);
    }

    mapParents(root, null);

    const visited = new Set([target]);
    const q = [[target, 0]];
    const res = [];

    while (q.length) {
        const [node, dist] = q.shift();
        if (dist === k) {
            res.push(node.val);
        } else if (dist < k) {
            for (const neighbor of [node.left, node.right, parentMap.get(node)]) {
                if (neighbor && !visited.has(neighbor)) {
                    visited.add(neighbor);
                    q.push([neighbor, dist + 1]);
                }
            }
        }
    }
    return res;
}

module.exports = { distanceK };