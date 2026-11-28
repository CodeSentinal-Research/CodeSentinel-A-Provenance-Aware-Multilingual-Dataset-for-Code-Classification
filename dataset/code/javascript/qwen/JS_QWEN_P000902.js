const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length >= parseInt(lines[0]) + 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        const q = parseInt(lines[2]);
        let res = [];
        // Precompute prefix sums for each possible divisor? No, too large.
        // Just iterate for each query since constraints are moderate or use simple loop
        for(let i=3; i<3+q; i++) {
            const [l, r, x] = lines[i].split(/\s+/).map(Number);
            let count = 0;
            for(let j=l; j<=r; j++) {
                if(arr[j] % x === 0) count++;
            }
            res.push(count);
        }
        console.log(res.join("\n"));
        rl.close();
    }
});
