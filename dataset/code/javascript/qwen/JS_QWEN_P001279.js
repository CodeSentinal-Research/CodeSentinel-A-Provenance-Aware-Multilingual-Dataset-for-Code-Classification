const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        let res = new Array(n).fill('a');
        let rem = k-n;
        for(let i=n-1; i>=0; i--) {
            let add = Math.min(25, rem);
            res[i] = String.fromCharCode('a'.charCodeAt(0)+add);
            rem-=add;
        }
        console.log(res.join(''));
        rl.close();
    }
});
