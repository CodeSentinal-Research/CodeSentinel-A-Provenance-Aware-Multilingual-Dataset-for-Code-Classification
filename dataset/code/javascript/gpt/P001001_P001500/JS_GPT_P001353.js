// P001353 - Restore the Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = BigInt(input[1]);
    const n = s.length;
    const MOD = 1000000007n;
    const dp = new Array(n + 1).fill(0n);
    dp[n] = 1n;
    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === "0") continue;
        let num = 0n;
        for (let j = i; j < n; j++) {
            num = num * 10n + BigInt(s[j]);
            if (num > k) break;
            dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
    }
    console.log(dp[0].toString());
}

main();
