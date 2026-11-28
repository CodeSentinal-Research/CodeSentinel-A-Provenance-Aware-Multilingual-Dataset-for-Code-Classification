const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        // Monotonic stack to track visible elements
        const stack = [];
        const map = { ')': '(', '}': '{', ']': '[' };
        for (let ch of s) {
            if (map[ch]) {
                const top = stack.length ? stack.pop() : '#';
                if (map[ch] !== top) { console.log("Invalid"); return; }
            } else {
                stack.push(ch);
            }
        }
        console.log(stack.length === 0 ? "Valid" : "Invalid");
    }
}
main();