// Helper function to evaluate verifypreorder for problem constraints.
function verifyPreorder(preorder) {
    const stack = [];
    let low = -Infinity;

    for (const p of preorder) {
        if (p < low) return false;
        // Maintain monotonic stack property by popping smaller elements
        while (stack.length && p > stack[stack.length - 1]) {
            low = stack.pop();
        }
        stack.push(p);
    }
    return true;
}

module.exports = { verifyPreorder };