// P000188 - Subarray with Given Sum (Positive Numbers)
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
let l = 0, sum = 0, found = false;
for (let r = 0; r < n; r++) {
    sum += a[r];
    while (sum > target && l < r) sum -= a[l++];
    if (sum === target) {
        console.log(`${l + 1} ${r + 1}`);
        found = true;
        break;
    }
}
if (!found) console.log(-1);
