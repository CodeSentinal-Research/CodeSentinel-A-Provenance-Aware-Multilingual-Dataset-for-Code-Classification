// P001454 - Count Distinct Substrings
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const set = new Set();
    for (let i = 0; i < s.length; i++) {
        for (let j = i + 1; j <= s.length; j++) {
            set.add(s.substring(i, j));
        }
    }
    console.log(set.size);
}

main();
