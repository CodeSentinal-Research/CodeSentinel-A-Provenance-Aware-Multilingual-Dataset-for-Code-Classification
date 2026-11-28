// Helper function to evaluate recoverfrompreorder for problem constraints.
function recoverFromPreorder(traversal) {
    const stack = [];
    let i = 0, n = traversal.length;

    while (i < n) {
        let depth = 0;
        while (i < n && traversal[i] === '-') {
            depth++;
            i++;
        }

        let val = 0;
        while (i < n && traversal[i] >= '0' && traversal[i] <= '9') {
            val = val * 10 + parseInt(traversal[i]);
            i++;
        }

        const node = { val, left: null, right: null };
        while (stack.length > depth) {
            stack.pop();
        }

        if (stack.length) {
            if (!stack[stack.length - 1].left) {
                stack[stack.length - 1].left = node;
            } else {
                stack[stack.length - 1].right = node;
            }
        }

        stack.push(node);
    }

    return stack[0] || null;
}

module.exports = { recoverFromPreorder };