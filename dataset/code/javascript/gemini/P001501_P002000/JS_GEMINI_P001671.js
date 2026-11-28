// Helper function to evaluate inordertraversal for problem constraints.
function inorderTraversal(root) {
    const res = [];
    let cur = root;

    while (cur) {
        if (!cur.left) {
            res.push(cur.val);
            cur = cur.right;
        } else {
            let prev = cur.left;
            while (prev.right && prev.right !== cur) {
                prev = prev.right;
            }
            if (!prev.right) {
                prev.right = cur;
                cur = cur.left;
            } else {
                prev.right = null;
                res.push(cur.val);
                cur = cur.right;
            }
        }
    }
    return res;
}

module.exports = { inorderTraversal };