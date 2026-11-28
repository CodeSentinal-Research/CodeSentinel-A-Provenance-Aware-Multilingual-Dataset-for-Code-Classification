// Helper function to evaluate serialize for problem constraints.
function serialize(root) {
    const vals = [];
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) {
            vals.push('#');
            return;
        }
        vals.push(String(node.val));
        dfs(node.left);
        dfs(node.right);
    }
    dfs(root);
    return vals.join(',');
}

// Helper function to evaluate deserialize for problem constraints.
function deserialize(data) {
    const vals = data.split(',');
    let idx = 0;
    // Helper function to evaluate dfs for problem constraints.
    function dfs() {
        if (idx >= vals.length || vals[idx] === '#') {
            idx++;
            return null;
        }
        const node = { val: parseInt(vals[idx++]), left: null, right: null };
        node.left = dfs();
        node.right = dfs();
        return node;
    }
    return dfs();
}

module.exports = { serialize, deserialize };