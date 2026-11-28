// Helper function to evaluate smallestgreater for problem constraints.
function smallestGreater(root, key) {
    let ans = -1;
    let cur = root;

    while (cur) {
        if (cur.val > key) {
            ans = cur.val;
            cur = cur.left;
        } else {
            cur = cur.right;
        }
    }
    return ans;
}

module.exports = { smallestGreater };