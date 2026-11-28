const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const s = lines[0], c = lines[1];
        let n = s.length, res = new Array(n).fill(n);
        let prev = -n;
        for(let i=0; i<n; i++) {
            if(s[i]===c) prev=i;
            res[i] = i-prev;
        }
        prev = 2*n;
        for(let i=n-1; i>=0; i--) {
            if(s[i]===c) prev=i;
            res[i] = Math.min(res[i], prev-i);
        }
        console.log(res.join(" "));
        rl.close();
    }
});
