const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= 2) {
        const n = parseInt(lines[0]);
        let count = {};
        for (let i = 1; i <= n; i++) {
            let w = lines[i];
            count[w] = (count[w] || 0) + 1;
        }
        
        let res = 0;
        for (let w in count) {
            if (w[0] === w[1]) {
                res += Math.floor(count[w] / 2) * 4;
                if (count[w] % 2 === 1) res += 2;
            } else {
                let rev = w.split('').reverse().join('');
                if (count[rev]) {
                    res += Math.min(count[w], count[rev]) * 4;
                    count[w] = 0;
                    count[rev] = 0;
                }
            }
        }
        console.log(res);
        rl.close();
    }
});
