const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000089 - Find Square Root without Built-in Function
let lo = 0, hi = n, ans = 0;
while (lo <= hi) {
    const mid = Math.trunc((lo + hi) / 2);
    if (mid * mid <= n) { ans = mid; lo = mid + 1; }
    else { hi = mid - 1; }
}
console.log(ans);
