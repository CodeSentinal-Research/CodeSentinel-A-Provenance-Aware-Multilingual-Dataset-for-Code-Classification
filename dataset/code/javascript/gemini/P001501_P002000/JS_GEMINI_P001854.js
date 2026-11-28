// Helper function to evaluate buildcartesiantree for problem constraints.
function buildCartesianTree(inorder) {
    const stack = [];

    for (const val of inorder) {
        let last = null;
        // Maintain monotonic stack property by popping smaller elements
        while (stack.length && stack[stack.length - 1].val > val) {
            last = stack.pop();
        }
        const node = { val, left: last, right: null };
        if (stack.length) {
            stack[stack.length - 1].right = node;
        }
        stack.push(node);
    }

    return stack.length ? stack[0] : null;
}

module.exports = { buildCartesianTree };