// P001446 - Sentence Similarity
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 3) return;
    const s1 = lines[0].trim().split(/\s+/);
    const s2 = lines[1].trim().split(/\s+/);
    const p = parseInt(lines[2].trim(), 10);
    if (s1.length !== s2.length) {
        console.log("NO");
        return;
    }
    const pairs = new Set();
    for (let i = 3; i < 3 + p && i < lines.length; i++) {
        const line = lines[i].trim();
        if (!line) continue;
        const [w1, w2] = line.split(/\s+/);
        pairs.add(`${w1}#${w2}`);
        pairs.add(`${w2}#${w1}`);
    }
    for (let i = 0; i < s1.length; i++) {
        const w1 = s1[i], w2 = s2[i];
        if (w1 !== w2 && !pairs.has(`${w1}#${w2}`)) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
