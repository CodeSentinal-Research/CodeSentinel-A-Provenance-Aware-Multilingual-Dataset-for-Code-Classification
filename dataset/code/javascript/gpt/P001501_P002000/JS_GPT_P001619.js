const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const pref = new Array(n + 1).fill(0);
for (let i = 0; i < n; i++) pref[i + 1] = pref[i] ^ d[p++];
const q = d[p++];
const out = [];
for (let i = 0; i < q; i++) {
    const l = d[p++], r = d[p++];
    out.push(String(pref[r + 1] ^ pref[l]));
}
console.log(out.join("\n"));
