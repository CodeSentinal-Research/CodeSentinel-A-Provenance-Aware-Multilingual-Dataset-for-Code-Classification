const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        // Monotonic stack to track visible elements
        const stack = [];
        for (const c of s) {
            if (stack.length > 0 && stack[stack.length - 1] === c) stack.pop();
            else stack.push(c);
        }
        console.log(stack.join(''));
    }
}
main();