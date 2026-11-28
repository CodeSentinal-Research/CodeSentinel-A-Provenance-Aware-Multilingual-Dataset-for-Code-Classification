const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let p = 0;
const n = Number(d[p++]);
const k = BigInt(d[p++]);
const pref = new Array(n + 1);
pref[0] = 0n;
for (let i = 1; i <= n; i++) pref[i] = pref[i - 1] + BigInt(d[p++]);

const q = [];
let head = 0;
let best = n + 1;
for (let i = 0; i <= n; i++) {
    while (head < q.length && pref[i] - pref[q[head]] >= k) {
        best = Math.min(best, i - q[head]);
        head++;
    }
    while (q.length > head && pref[i] <= pref[q[q.length - 1]]) q.pop();
    q.push(i);
}
console.log(best === n + 1 ? -1 : best);
