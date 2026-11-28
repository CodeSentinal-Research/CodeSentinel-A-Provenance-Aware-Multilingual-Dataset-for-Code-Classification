// P000201 - Maximum Sum Increasing Subsequence
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const dp = a.slice();
let answer = n ? a[0] : 0;
for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
        if (a[j] < a[i]) dp[i] = Math.max(dp[i], dp[j] + a[i]);
    }
    answer = Math.max(answer, dp[i]);
}
console.log(answer);
