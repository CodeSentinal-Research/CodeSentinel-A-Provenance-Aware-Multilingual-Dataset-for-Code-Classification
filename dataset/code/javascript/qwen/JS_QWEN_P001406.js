const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 3) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const key = parseInt(lines[2]);
        
        let count = {};
        let maxFreq = 0, res = -1;
        for (let i = 1; i < n; i++) {
            if (arr[i-1] === key) {
                let next = arr[i];
                count[next] = (count[next] || 0) + 1;
                if (count[next] > maxFreq || (count[next] === maxFreq && next < res)) {
                    maxFreq = count[next];
                    res = next;
                }
            }
        }
        console.log(res);
        rl.close();
    }
});
