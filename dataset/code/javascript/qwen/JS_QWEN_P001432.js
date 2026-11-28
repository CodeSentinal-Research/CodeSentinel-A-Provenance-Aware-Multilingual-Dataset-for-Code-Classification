const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let count = {};
        for (let i = 1; i <= n; i++) {
            const [a, b] = lines[i].split(/\s+/).map(Number);
            let key = [Math.min(a,b), Math.max(a,b)].join(",");
            count[key] = (count[key] || 0) + 1;
        }
        
        let res = 0;
        for (let k in count) {
            let c = count[k];
            res += (c * (c - 1)) / 2;
        }
        console.log(res);
        rl.close();
    }
});
