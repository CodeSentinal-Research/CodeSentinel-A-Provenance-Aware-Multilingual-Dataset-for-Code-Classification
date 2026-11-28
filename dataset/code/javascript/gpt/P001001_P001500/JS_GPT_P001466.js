// P001466 - Valid Palindrome
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const pattern = lines[0].trim();
    const words = lines[1].trim().split(/\s+/);
    if (pattern.length !== words.length) {
        console.log("NO");
        return;
    }
    const mapPW = new Map(), mapWP = new Map();
    for (let i = 0; i < pattern.length; i++) {
        const p = pattern[i], w = words[i];
        if ((mapPW.has(p) && mapPW.get(p) !== w) || (mapWP.has(w) && mapWP.get(w) !== p)) {
            console.log("NO");
            return;
        }
        mapPW.set(p, w);
        mapWP.set(w, p);
    }
    console.log("YES");
}

main();
