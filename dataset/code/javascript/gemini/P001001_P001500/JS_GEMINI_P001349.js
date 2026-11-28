// Helper function to evaluate smallestnumber for problem constraints.
function smallestNumber(pattern) {
    const res = [];
    const stack = [];
    for (let i = 0; i <= pattern.length; i++) {
        stack.push(i + 1);
        if (i === pattern.length || pattern[i] === 'I') {
            while (stack.length > 0) {
                res.push(stack.pop());
            }
        }
    }
    return res.join('');
}

module.exports = { smallestNumber };