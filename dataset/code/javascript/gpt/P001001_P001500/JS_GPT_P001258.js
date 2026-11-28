// P001258 - Remove Duplicate Letters
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const last = new Map();
    for (let i = 0; i < s.length; i++) last.set(s[i], i);
    const seen = new Set();
    const stack = [];
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (!seen.has(c)) {
            while (stack.length > 0 && stack[stack.length - 1] > c && last.get(stack[stack.length - 1]) > i) {
                seen.delete(stack.pop());
            }
            seen.add(c);
            stack.push(c);
        }
    }
    console.log(stack.join(""));
}

main();
