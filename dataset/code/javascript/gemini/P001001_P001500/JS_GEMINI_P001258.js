// Helper function to evaluate removeduplicateletters for problem constraints.
function removeDuplicateLetters(s) {
    const last = {};
    for (let i = 0; i < s.length; i++) last[s[i]] = i;

    const stack = [];
    const seen = new Set();

    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (!seen.has(c)) {
            while (stack.length > 0 && stack[stack.length - 1] > c && i < last[stack[stack.length - 1]]) {
                seen.delete(stack.pop());
            }
            seen.add(c);
            stack.push(c);
        }
    }
    return stack.join('');
}

module.exports = { removeDuplicateLetters };