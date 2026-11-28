const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const arr = lines[1].split(/\s+/).map(Number);
        let dp = [...arr];
        for(let i=1; i<n; i++) {
            for(let j=0; j<i; j++) {
                if(arr[i] > arr[j]) dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            }
        }
        console.log(Math.max(...dp));
        rl.close();
    }
});
