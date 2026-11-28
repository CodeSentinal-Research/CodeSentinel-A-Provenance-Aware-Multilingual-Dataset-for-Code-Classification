function isValid(s) {
    const stack = [];
    const map = { ')': '(', ']': '[', '}': '{' };
    for (const c of s) {
        if ('([{'.includes(c)) stack.push(c);
        else {
            if (stack.length === 0 || stack.pop() !== map[c]) return false;
        }
    }
    return stack.length === 0;
}

module.exports = { isValid };
