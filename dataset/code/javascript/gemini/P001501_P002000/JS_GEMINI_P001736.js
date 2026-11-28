// Helper function to evaluate boundaryofbinarytreeclockwise for problem constraints.
function boundaryOfBinaryTreeClockwise(root) {
    if (!root) return [];
    const res = [];

    // Helper function to evaluate isleaf for problem constraints.
    function isLeaf(node) {
        return node && !node.left && !node.right;
    }

    // Helper function to evaluate addleavesrev for problem constraints.
    function addLeavesRev(node) {
        if (isLeaf(node)) {
            res.push(node.val);
            return;
        }
        if (node.right) addLeavesRev(node.right);
        if (node.left) addLeavesRev(node.left);
    }

    if (!isLeaf(root)) res.push(root.val);

    let cur = root.right;
    while (cur) {
        if (!isLeaf(cur)) res.push(cur.val);
        cur = cur.right ? cur.right : cur.left;
    }

    addLeavesRev(root);

    const st = [];
    cur = root.left;
    while (cur) {
        if (!isLeaf(cur)) st.push(cur.val);
        cur = cur.left ? cur.left : cur.right;
    }
    while (st.length) res.push(st.pop());

    return res;
}

module.exports = { boundaryOfBinaryTreeClockwise };