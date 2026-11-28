const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const n = parseInt(input[0], 10);
        const MOD = 1000000007n;
        let dp = [[1n, 0n, 0n], [0n, 0n, 0n]];
        for (let i = 0; i < n; i++) {
            const next = [[0n, 0n, 0n], [0n, 0n, 0n]];
            for (let a = 0; a < 2; a++) {
                for (let l = 0; l < 3; l++) {
                    // Update dynamic programming state transition
                    const val = dp[a][l];
                    if (val === 0n) continue;
                    next[a][0] = (next[a][0] + val) % MOD;
                    if (a === 0) next[1][0] = (next[1][0] + val) % MOD;
                    if (l < 2) next[a][l + 1] = (next[a][l + 1] + val) % MOD;
                }
            }
            dp = next;
        }
        let total = 0n;
        for (let a = 0; a < 2; a++) {
            for (let l = 0; l < 3; l++) total = (total + dp[a][l]) % MOD;
        }
        console.log(total.toString());
    }
}

main();