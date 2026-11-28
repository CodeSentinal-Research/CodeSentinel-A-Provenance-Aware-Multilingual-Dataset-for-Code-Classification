// P000225 - Minimum Swaps to Sort
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const sorted = a.slice().sort((x, y) => x - y);
const pos = new Map();
sorted.forEach((v, idx) => pos.set(v, idx));
const visited = Array(n).fill(false);
let swaps = 0;
for (let i = 0; i < n; i++) {
    if (visited[i] || pos.get(a[i]) === i) continue;
    let cycleSize = 0, j = i;
    while (!visited[j]) {
        visited[j] = true;
        j = pos.get(a[j]);
        cycleSize++;
    }
    if (cycleSize > 0) swaps += cycleSize - 1;
}
console.log(swaps);
