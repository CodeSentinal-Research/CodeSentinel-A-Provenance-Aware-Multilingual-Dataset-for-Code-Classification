// Helper function to evaluate maxvalue for problem constraints.
function maxValue(root) {
    if (!root) return -1;
    let cur = root;
    while (cur.right) cur = cur.right;
    return cur.val;
}

module.exports = { maxValue };