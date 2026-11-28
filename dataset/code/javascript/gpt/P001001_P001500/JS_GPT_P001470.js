// P001470 - Merge Two Sorted Arrays Without Extra Space
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const seen = new Set();
    for (let i = 0; i < s.length; i++) {
        if (seen.has(s[i])) {
            console.log(s[i]);
            return;
        }
        seen.add(s[i]);
    }
    console.log("-1");
}

main();
