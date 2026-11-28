const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let leaves = [];
        for(let i=Math.floor(n/2); i<n; i++) leaves.push(arr[i]);
        console.log(leaves.join(" "));
        rl.close();
    }
});
