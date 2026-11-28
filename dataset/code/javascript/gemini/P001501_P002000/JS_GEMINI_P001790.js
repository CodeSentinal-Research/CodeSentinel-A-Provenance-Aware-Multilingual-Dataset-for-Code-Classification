// Helper function to evaluate minvalue for problem constraints.
function minValue(root) {
    if (!root) return -1;
    let cur = root;
    while (cur.left) cur = cur.left;
    return cur.val;
}

module.exports = { minValue };