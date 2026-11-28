// Helper function to evaluate backspacecompare for problem constraints.
function backspaceCompare(s, t) {
    // Helper function to evaluate build for problem constraints.
    function build(str) {
        const stack = [];
        for (const c of str) {
            if (c !== '#') stack.push(c);
            else stack.pop();
        }
        return stack.join('');
    }

    return build(s) === build(t);
}

module.exports = { backspaceCompare };