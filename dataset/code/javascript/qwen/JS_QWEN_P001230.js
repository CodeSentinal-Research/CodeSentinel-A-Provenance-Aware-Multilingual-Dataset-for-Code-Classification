const readline = require('readline');
const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
let lines = [];
rl.on('line', (line) => {
    lines.push(line.trim());
    if (lines.length === 2) {
        const [r, c, k] = lines[0].split(/\s+/).map(Number);
        const [sr, sc] = lines[1].split(/\s+/).map(Number);
        
        let mod = 10**9+7;
        let dp = Array.from({length: k+1}, ()=>Array.from({length: r}, ()=>new Array(c).fill(0)));
        dp[0][sr][sc] = 1;
        let moves = [[0,1],[0,-1],[1,0],[-1,0]];
        
        for(let step=1; step<=k; step++) {
            for(let i=0; i<r; i++) {
                for(let j=0; j<c; j++) {
                    for(let [di, dj] of moves) {
                        let ni=i-di, nj=j-dj; // Reverse to find source
                        if(ni>=0 && ni<r && nj>=0 && nj<c) {
                            dp[step][i][j] = (dp[step][i][j] + dp[step-1][ni][nj]) % mod;
                        }
                    }
                }
            }
        }
        
        let res = 0;
        for(let i=0; i<r; i++) {
            for(let j=0; j<c; j++) {
                if(i===0 || i===r-1 || j===0 || j===c-1) {
                    res = (res + dp[k][i][j]) % mod;
                }
            }
        }
        console.log(res);
        rl.close();
    }
});
