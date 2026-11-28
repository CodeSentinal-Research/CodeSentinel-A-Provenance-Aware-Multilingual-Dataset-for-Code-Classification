// P000126 - Three Sum Closest
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
let best = a[0] + a[1] + a[2];
for (let i = 0; i < n - 2; i++) {
    let l = i + 1, r = n - 1;
    while (l < r) {
        const sum = a[i] + a[l] + a[r];
        if (Math.abs(sum - target) < Math.abs(best - target)) best = sum;
        if (sum < target) l++;
        else if (sum > target) r--;
        else { console.log(target); process.exit(0); }
    }
}
console.log(best);
