const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const set = new Set(arr);
        let maxLen = 0;
        for(let x of set) {
            if(!set.has(x-1)) {
                let curr = x, len = 1;
                while(set.has(curr+1)) { curr++; len++; }
                maxLen = Math.max(maxLen, len);
            }
        }
        console.log(maxLen);
        rl.close();
    }
});
