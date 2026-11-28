// P000219 - Product of Last K Numbers
const fs = require("fs");
const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
let pref = [1];
const out = [];
for (const line of lines) {
    const parts = line.trim().split(/\s+/);
    if (!parts[0]) continue;
    const op = parts[0].toLowerCase();
    if (op === "add") {
        const x = Number(parts[1]);
        if (x === 0) pref = [1];
        else pref.push(pref[pref.length - 1] * x);
    } else if (op === "getproduct") {
        const k = Number(parts[1]);
        if (k < pref.length) {
            out.push(String(Math.floor(pref[pref.length - 1] / pref[pref.length - 1 - k])));
        } else {
            out.push("0");
        }
    }
}
console.log(out.join("\n"));
