// Helper function to evaluate verifypostorder for problem constraints.
function verifyPostorder(postorder) {
    const stack = [];
    let high = Infinity;

    for (let i = postorder.length - 1; i >= 0; i--) {
        const p = postorder[i];
        if (p > high) return false;
        // Maintain monotonic stack property by popping smaller elements
        while (stack.length && p < stack[stack.length - 1]) {
            high = stack.pop();
        }
        stack.push(p);
    }
    return true;
}

module.exports = { verifyPostorder };