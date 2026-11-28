const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let count = new Array(k).fill(0);
        arr.forEach(x => count[x]++);
        let maxIdx = 0;
        for(let i=1; i<k; i++) if(count[i] > count[maxIdx]) maxIdx = i;
        console.log(maxIdx);
        rl.close();
    }
});
