const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const a = d.slice(p, p + n); p += n;
const evenPref = new Array(n + 1).fill(0);
const oddPref = new Array(n + 1).fill(0);
for (let i = 0; i < n; i++) {
    evenPref[i + 1] = evenPref[i];
    oddPref[i + 1] = oddPref[i];
    if (i % 2 === 0) evenPref[i + 1] += a[i];
    else oddPref[i + 1] += a[i];
}
const q = d[p++];
const out = [];
for (let z = 0; z < q; z++) {
    const l = d[p++], r = d[p++];
    const count = r - l + 1;
    if (count % 2 === 1) {
        const base = evenPref[r + 1] - evenPref[l];
        const alt = oddPref[r + 1] - oddPref[l];
        out.push(String(l % 2 === 0 ? base : alt));
    } else {
        const e = evenPref[r + 1] - evenPref[l];
        const o = oddPref[r + 1] - oddPref[l];
        out.push(String(l % 2 === 0 ? e : o));
    }
}
console.log(out.join("\n"));
