// Helper function to evaluate preordertraversal for problem constraints.
function preorderTraversal(root) {
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
                res.push(cur.val);
                prev.right = cur;
                cur = cur.left;
            } else {
                prev.right = null;
                cur = cur.right;
            }
        }
    }
    return res;
}

module.exports = { preorderTraversal };