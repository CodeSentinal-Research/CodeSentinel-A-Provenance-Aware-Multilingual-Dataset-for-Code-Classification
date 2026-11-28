const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0];
        const c = lines[1];
        
        let n = s.length;
        let left = new Array(n).fill(Infinity), right = new Array(n).fill(Infinity);
        
        for (let i = 0; i < n; i++) {
            if (s[i] === c) left[i] = 0;
            else if (i > 0) left[i] = left[i-1] + 1;
        }
        for (let i = n - 1; i >= 0; i--) {
            if (s[i] === c) right[i] = 0;
            else if (i < n - 1) right[i] = right[i+1] + 1;
        }
        
        let res = [];
        for (let i = 0; i < n; i++) res.push(Math.min(left[i], right[i]));
        console.log(res.join(" "));
        rl.close();
    }
});
