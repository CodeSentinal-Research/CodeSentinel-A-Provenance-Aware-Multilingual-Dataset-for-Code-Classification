// Helper function to evaluate kthlargest for problem constraints.
function kthLargest(root, k) {
    const stack = [];
    let cur = root;

    while (cur || stack.length) {
        while (cur) {
            stack.push(cur);
            cur = cur.right;
        }
        cur = stack.pop();
        if (--k === 0) return cur.val;
        cur = cur.left;
    }
    return -1;
}

module.exports = { kthLargest };