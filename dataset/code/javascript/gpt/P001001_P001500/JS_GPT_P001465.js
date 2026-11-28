// P001465 - Squares of a Sorted Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const t = input[1];
    if (s.length !== t.length) {
        console.log("NO");
        return;
    }
    const mapST = new Map(), mapTS = new Map();
    for (let i = 0; i < s.length; i++) {
        const c1 = s[i], c2 = t[i];
        if ((mapST.has(c1) && mapST.get(c1) !== c2) || (mapTS.has(c2) && mapTS.get(c2) !== c1)) {
            console.log("NO");
            return;
        }
        mapST.set(c1, c2);
        mapTS.set(c2, c1);
    }
    console.log("YES");
}

main();
