// P001378 - Word Pattern
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const pattern = lines[0].trim();
    const words = lines[1].trim().split(/\s+/);
    if (pattern.length !== words.length) { console.log("NO"); return; }
    const pToW = new Map(), wToP = new Map();
    for (let i = 0; i < pattern.length; i++) {
        const p = pattern[i], w = words[i];
        if (pToW.has(p) && pToW.get(p) !== w) { console.log("NO"); return; }
        if (wToP.has(w) && wToP.get(w) !== p) { console.log("NO"); return; }
        pToW.set(p, w);
        wToP.set(w, p);
    }
    console.log("YES");
}

main();
