// P001436 - Maximum Number of Balloons
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const count = new Map();
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        count.set(c, (count.get(c) || 0) + 1);
    }
    const b = count.get('b') || 0;
    const a = count.get('a') || 0;
    const l = Math.floor((count.get('l') || 0) / 2);
    const o = Math.floor((count.get('o') || 0) / 2);
    const n = count.get('n') || 0;
    console.log(Math.min(b, a, l, o, n));
}

main();
