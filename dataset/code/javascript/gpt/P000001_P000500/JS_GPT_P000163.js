// P000163 - Find Triplet with Given Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
let found = false;
for (let i = 0; i < n - 2; i++) {
    let l = i + 1, r = n - 1;
    while (l < r) {
        const sum = a[i] + a[l] + a[r];
        if (sum === target) { found = true; break; }
        if (sum < target) l++;
        else r--;
    }
    if (found) break;
}
console.log(found ? "Yes" : "No");
