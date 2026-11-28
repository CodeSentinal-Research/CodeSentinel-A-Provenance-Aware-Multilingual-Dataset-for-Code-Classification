const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let words1 = [], words2 = [];
        for (let i = 1; i <= n; i++) words1.push(lines[i]);
        for (let i = n + 1; i <= n + m; i++) words2.push(lines[i]);
        
        let count1 = {}, count2 = {};
        for (let w of words1) {
            let mask = 0;
            for (let c of w) mask |= (1 << (c.charCodeAt(0) - 97));
            count1[mask] = (count1[mask] || 0) + 1;
        }
        
        let res = 0;
        for (let w of words2) {
            let mask = 0;
            for (let c of w) mask |= (1 << (c.charCodeAt(0) - 97));
            if (count1[mask]) res++;
        }
        console.log(res);
        rl.close();
    }
});
