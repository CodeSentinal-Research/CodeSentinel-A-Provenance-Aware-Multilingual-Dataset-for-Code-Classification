const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let res = new Array(n).fill(-1);
        let stack = [];
        for(let i=0; i<n; i++) {
            while(stack.length > 0 && arr[stack[stack.length-1]] > arr[i]) {
                res[stack.pop()] = arr[i];
            }
            stack.push(i);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
