// P001399 - Uncommon Words from Two Sentences
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const s1 = lines[0].trim().split(/\s+/);
    const s2 = lines[1].trim().split(/\s+/);
    const count = new Map();
    for (const w of s1.concat(s2)) {
        if (w) count.set(w, (count.get(w) || 0) + 1);
    }
    const uncommons = [];
    for (const [w, c] of count.entries()) {
        if (c === 1) uncommons.push(w);
    }
    uncommons.sort();
    console.log(uncommons.join(" "));
}

main();
