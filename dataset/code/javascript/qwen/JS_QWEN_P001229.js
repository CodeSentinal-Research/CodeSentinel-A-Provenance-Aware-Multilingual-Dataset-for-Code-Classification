const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 1) {
        const [n, k, r, c] = lines[0].split(/\s+/).map(Number);
        let dp = Array.from({length: k+1}, ()=>Array.from({length: n}, ()=>new Array(n).fill(0)));
        dp[0][r][c] = 1;
        let moves = [[-2,-1],[-2,1],[-1,-2],[-1,2],[1,-2],[1,2],[2,-1],[2,1]];
        
        for(let step=1; step<=k; step++) {
            for(let i=0; i<n; i++) {
                for(let j=0; j<n; j++) {
                    for(let [dr, dc] of moves) {
                        let ni=i+dr, nj=j+dc;
                        if(ni>=0 && ni<n && nj>=0 && nj<n) {
                            dp[step][i][j] += dp[step-1][ni][nj];
                        }
                    }
                }
            }
        }
        
        let total = Math.pow(8, k);
        let onBoard = 0;
        for(let i=0; i<n; i++) for(let j=0; j<n; j++) onBoard += dp[k][i][j];
        console.log((onBoard/total).toFixed(5));
        rl.close();
    }
});
