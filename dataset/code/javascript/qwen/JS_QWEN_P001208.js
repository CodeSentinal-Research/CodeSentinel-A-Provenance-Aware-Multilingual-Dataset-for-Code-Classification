const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const n = parseInt(lines[0]);
        const piles = lines[1].split(/\s+/).map(Number);
        
        let suffixSum = new Array(n+1).fill(0);
        for(let i=n-1; i>=0; i--) suffixSum[i] = suffixSum[i+1] + piles[i];
        
        let memo = {};
        function dfs(i, m) {
            if(i>=n) return 0;
            let key = `${i},${m}`;
            if(memo[key]!==undefined) return memo[key];
            
            let maxStones = 0;
            for(let x=1; x<=2*m && i+x<=n; x++) {
                let taken = suffixSum[i] - suffixSum[i+x];
                let nextM = Math.max(m, x);
                let opponent = dfs(i+x, nextM);
                maxStones = Math.max(maxStones, taken + (suffixSum[i+x] - opponent)); // Simplified logic
                // Correct logic: Alice takes sum(i, i+x), then Bob plays optimally.
                // Alice's total = sum(i, i+x) + (TotalRemaining - Bob'sBest)
                // Actually simpler: dp[i][m] = max(sum(i, i+x) + (suffixSum[i+x] - dp[i+x][max(m,x)]))
                // Wait, dp returns max stones current player can get from i onwards with limit m.
                // Current player takes sum(i, i+x). Remaining is suffixSum[i+x].
                // Opponent gets dp[i+x][max(m,x)].
                // Current player gets sum(i, i+x) + (suffixSum[i+x] - dp[i+x][max(m,x)])
                // Which simplifies to suffixSum[i] - dp[i+x][max(m,x)]
                
                let val = suffixSum[i] - dfs(i+x, Math.max(m, x));
                maxStones = Math.max(maxStones, val);
            }
            memo[key] = maxStones;
            return maxStones;
        }
        console.log(dfs(0, 1));
        rl.close();
    }
});
