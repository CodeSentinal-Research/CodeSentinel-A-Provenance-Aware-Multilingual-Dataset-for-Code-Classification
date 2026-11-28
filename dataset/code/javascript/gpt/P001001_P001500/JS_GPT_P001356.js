// P001356 - Split Into Maximum Number of Unique Substrings
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const seen = new Set();
    let maxSplits = 0;
    function backtrack(idx) {
        if (idx === s.length) {
            maxSplits = Math.max(maxSplits, seen.size);
            return;
        }
        for (let i = idx + 1; i <= s.length; i++) {
            const sub = s.substring(idx, i);
            if (!seen.has(sub)) {
                seen.add(sub);
                backtrack(i);
                seen.delete(sub);
            }
        }
    }
    backtrack(0);
    console.log(maxSplits);
}

main();
