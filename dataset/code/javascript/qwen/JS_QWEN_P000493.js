const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const temps = lines[1].split(/\s+/).map(Number);
        let res = new Array(n).fill(0);
        let stack = [];
        for(let i=0; i<n; i++) {
            while(stack.length && temps[stack[stack.length-1]] < temps[i]) {
                res[stack.pop()] = i - stack[stack.length-1] || i; // Simplified logic
                // Correct logic: res[prev] = i - prev
                // Wait, stack stores indices
            }
            stack.push(i);
        }
        // Re-implementing correctly
        res = new Array(n).fill(0);
        stack = [];
        for(let i=0; i<n; i++) {
            while(stack.length && temps[stack[stack.length-1]] < temps[i]) {
                let prev = stack.pop();
                res[prev] = i - prev;
            }
            stack.push(i);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
