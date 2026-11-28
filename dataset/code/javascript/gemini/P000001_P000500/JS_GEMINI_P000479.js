const fs = require('fs');
function isValid(s) {
    // Monotonic stack to track visible elements
    const stack = [];
    const map = { ')': '(', '}': '{', ']': '[' };
    for (const c of s) {
        if (map[c]) {
            if (stack.pop() !== map[c]) return false;
        } else {
            stack.push(c);
        }
    }
    return stack.length === 0;
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        console.log(isValid(s) ? "true" : "false");
    }
}
main();