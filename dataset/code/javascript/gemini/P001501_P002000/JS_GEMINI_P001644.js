// Helper function to evaluate boundaryofbinarytree for problem constraints.
function boundaryOfBinaryTree(root) {
    if (!root) return [];
    const res = [];

    // Helper function to evaluate isleaf for problem constraints.
    function isLeaf(node) {
        return node && !node.left && !node.right;
    }

    // Helper function to evaluate addleaves for problem constraints.
    function addLeaves(node) {
        if (isLeaf(node)) {
            res.push(node.val);
            return;
        }
        if (node.left) addLeaves(node.left);
        if (node.right) addLeaves(node.right);
    }

    if (!isLeaf(root)) res.push(root.val);

    let cur = root.left;
    while (cur) {
        if (!isLeaf(cur)) res.push(cur.val);
        cur = cur.left ? cur.left : cur.right;
    }

    addLeaves(root);

    const st = [];
    cur = root.right;
    while (cur) {
        if (!isLeaf(cur)) st.push(cur.val);
        cur = cur.right ? cur.right : cur.left;
    }
    while (st.length) res.push(st.pop());

    return res;
}

module.exports = { boundaryOfBinaryTree };