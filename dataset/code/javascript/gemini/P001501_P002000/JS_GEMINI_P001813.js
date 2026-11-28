// Helper function to evaluate closestvalue for problem constraints.
function closestValue(root, target) {
    let closest = root.val;
    let cur = root;

    while (cur) {
        if (Math.abs(cur.val - target) < Math.abs(closest - target) ||
            (Math.abs(cur.val - target) === Math.abs(closest - target) && cur.val < closest)) {
            closest = cur.val;
        }

        if (target < cur.val) {
            cur = cur.left;
        } else {
            cur = cur.right;
        }
    }
    return closest;
}

module.exports = { closestValue };