// P001163 - Interleaving Strings
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 3) return;
    const s1 = lines[0].trim();
    const s2 = lines[1].trim();
    const s3 = lines[2].trim();
    if (s1.length + s2.length !== s3.length) {
        console.log("NO");
        return;
    }
    const m = s1.length, n = s2.length;
    const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(false));
    dp[0][0] = true;
    for (let i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] && s1[i - 1] === s3[i - 1];
    for (let j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] && s2[j - 1] === s3[j - 1];
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] === s3[i + j - 1]) ||
                       (dp[i][j - 1] && s2[j - 1] === s3[i + j - 1]);
        }
    }
    console.log(dp[m][n] ? "YES" : "NO");
}

main();
