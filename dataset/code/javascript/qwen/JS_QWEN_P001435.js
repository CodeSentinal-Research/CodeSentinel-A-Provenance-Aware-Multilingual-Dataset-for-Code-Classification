const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const [n, m] = lines[0].split(/\s+/).map(Number);
        let count1 = {}, count2 = {};
        for (let i = 1; i <= n; i++) {
            let w = lines[i];
            count1[w] = (count1[w] || 0) + 1;
        }
        for (let i = n + 1; i <= n + m; i++) {
            let w = lines[i];
            count2[w] = (count2[w] || 0) + 1;
        }
        
        let res = 0;
        for (let w in count1) {
            if (count1[w] === 1 && count2[w] === 1) res++;
        }
        console.log(res);
        rl.close();
    }
});
