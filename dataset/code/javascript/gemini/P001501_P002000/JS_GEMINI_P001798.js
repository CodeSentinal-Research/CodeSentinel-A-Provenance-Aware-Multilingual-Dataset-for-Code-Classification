// Helper function to evaluate kthsmallest for problem constraints.
function kthSmallest(root, k) {
    const stack = [];
    let cur = root;

    while (cur || stack.length) {
        while (cur) {
            stack.push(cur);
            cur = cur.left;
        }
        cur = stack.pop();
        if (--k === 0) return cur.val;
        cur = cur.right;
    }
    return -1;
}

module.exports = { kthSmallest };