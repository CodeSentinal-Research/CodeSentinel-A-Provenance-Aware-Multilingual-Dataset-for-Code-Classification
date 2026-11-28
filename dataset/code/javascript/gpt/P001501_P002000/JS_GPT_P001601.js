const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const a = d.slice(p, p + n); p += n;
const q = d[p++];
const pref = new Int32Array(n + 1);
for (let i = 0; i < n; i++) pref[i + 1] = pref[i] + (a[i] === 0 ? 1 : 0);
const out = [];
for (let i = 0; i < q; i++) {
    const l = d[p++], r = d[p++];
    out.push(String(pref[r + 1] - pref[l]));
}
console.log(out.join("\n"));
