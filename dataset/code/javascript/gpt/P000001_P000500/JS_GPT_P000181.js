// P000181 - Maximum Sum of Two Non-Overlapping Subarrays
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], L = tokens[p++], M = tokens[p++];
const a = tokens.slice(p, p + n);
const pref = Array(n + 1).fill(0);
for (let i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
function maxTwo(len1, len2) {
    let max1 = 0, ans = 0;
    for (let i = len1 + len2; i <= n; i++) {
        max1 = Math.max(max1, pref[i - len2] - pref[i - len2 - len1]);
        ans = Math.max(ans, max1 + pref[i] - pref[i - len2]);
    }
    return ans;
}
console.log(Math.max(maxTwo(L, M), maxTwo(M, L)));
