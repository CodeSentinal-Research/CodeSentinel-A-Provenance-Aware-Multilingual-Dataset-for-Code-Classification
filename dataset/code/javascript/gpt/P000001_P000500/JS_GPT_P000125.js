// P000125 - Two Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
const map = new Map();
let ans = [-1, -1];
for (let i = 0; i < n; i++) {
    const complement = target - a[i];
    if (map.has(complement)) {
        ans = [map.get(complement), i];
        break;
    }
    map.set(a[i], i);
}
console.log(ans.join(" "));
