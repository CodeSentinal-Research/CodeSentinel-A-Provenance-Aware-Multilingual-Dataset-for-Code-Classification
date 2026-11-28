// P001377 - Isomorphic Strings
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const t = input[1];
    if (s.length !== t.length) { console.log("NO"); return; }
    const m1 = new Map(), m2 = new Map();
    for (let i = 0; i < s.length; i++) {
        const c1 = s[i], c2 = t[i];
        if (m1.has(c1) && m1.get(c1) !== c2) { console.log("NO"); return; }
        if (m2.has(c2) && m2.get(c2) !== c1) { console.log("NO"); return; }
        m1.set(c1, c2);
        m2.set(c2, c1);
    }
    console.log("YES");
}

main();
