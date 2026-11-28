// P000161 - Find All Pairs with Given Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
let l = 0, r = n - 1;
const pairs = [];
while (l < r) {
    const sum = a[l] + a[r];
    if (sum === target) {
        pairs.push(`${a[l]} ${a[r]}`);
        const leftVal = a[l], rightVal = a[r];
        while (l < r && a[l] === leftVal) l++;
        while (l < r && a[r] === rightVal) r--;
    } else if (sum < target) l++;
    else r--;
}
for (const pair of pairs) console.log(pair);
