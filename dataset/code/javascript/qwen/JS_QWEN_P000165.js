const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let maxProd = arr[0], minProd = arr[0], res = arr[0];
        for(let i=1; i<n; i++) {
            let tempMax = Math.max(arr[i], maxProd*arr[i], minProd*arr[i]);
            minProd = Math.min(arr[i], maxProd*arr[i], minProd*arr[i]);
            maxProd = tempMax;
            res = Math.max(res, maxProd);
        }
        console.log(res);
        rl.close();
    }
});
