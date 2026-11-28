const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++], target = d[p++];
const a = Array.from({ length: n }, () => {
    const row = d.slice(p, p + m);
    p += m;
    return row;
});
let answer = 0;
for (let top = 0; top < n; top++) {
    const col = new Array(m).fill(0);
    for (let bottom = top; bottom < n; bottom++) {
        for (let j = 0; j < m; j++) col[j] += a[bottom][j];
        const freq = new Map([[0, 1]]);
        let sum = 0;
        for (const x of col) {
            sum += x;
            answer += freq.get(sum - target) || 0;
            freq.set(sum, (freq.get(sum) || 0) + 1);
        }
    }
}
console.log(answer);
