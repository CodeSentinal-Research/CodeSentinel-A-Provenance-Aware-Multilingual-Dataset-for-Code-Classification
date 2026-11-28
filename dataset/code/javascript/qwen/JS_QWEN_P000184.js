const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [n, k] = lines[0].split(/\s+/).map(Number);
        const arr = lines[1].split(/\s+/).map(Number);
        let map = {0: -1}, sum=0, maxL=0;
        for(let i=0; i<n; i++) {
            sum += arr[i];
            if(map[sum-k] !== undefined) maxL = Math.max(maxL, i-map[sum-k]);
            if(map[sum] === undefined) map[sum] = i;
        }
        console.log(maxL);
        rl.close();
    }
});
