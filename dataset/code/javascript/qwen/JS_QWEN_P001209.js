const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const vals = lines[1].split(/\s+/).map(Number);
        
        let dp = new Array(n).fill(0);
        let suffixSum = new Array(n+1).fill(0);
        for(let i=n-1; i>=0; i--) suffixSum[i] = suffixSum[i+1] + vals[i];
        
        // dp[i] = max score difference current player can achieve starting at i
        for(let i=n-1; i>=0; i--) {
            for(let k=1; k<=3 && i+k<=n; k++) {
                let take = suffixSum[i] - suffixSum[i+k];
                let nextDiff = (i+k < n) ? dp[i+k] : 0;
                dp[i] = Math.max(dp[i], take - nextDiff);
            }
        }
        
        let aliceScore = (suffixSum[0] + dp[0]) / 2;
        let bobScore = (suffixSum[0] - dp[0]) / 2;
        
        if(aliceScore > bobScore) console.log("Alice");
        else if(bobScore > aliceScore) console.log("Bob");
        else console.log("Tie");
        rl.close();
    }
});
