const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let words = [];
        for (let i = 1; i <= n; i++) words.push(lines[i]);
        const order = lines[n+1];
        
        let rank = {};
        for (let i = 0; i < order.length; i++) rank[order[i]] = i;
        
        let valid = true;
        for (let i = 0; i < words.length - 1; i++) {
            let w1 = words[i], w2 = words[i+1];
            let j = 0;
            while (j < w1.length && j < w2.length && w1[j] === w2[j]) j++;
            if (j < w1.length && j < w2.length) {
                if (rank[w1[j]] > rank[w2[j]]) { valid = false; break; }
            } else if (j < w1.length) {
                valid = false;
            }
        }
        console.log(valid ? "YES" : "NO");
        rl.close();
    }
});
