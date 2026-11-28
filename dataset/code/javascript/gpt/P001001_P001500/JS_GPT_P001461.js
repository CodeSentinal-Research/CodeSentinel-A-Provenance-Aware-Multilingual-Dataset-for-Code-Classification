// P001461 - Two Sum II - Sorted Array
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let maxLen = 0, l = 0;
    const pos = new Map();
    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        if (pos.has(c) && pos.get(c) >= l) {
            l = pos.get(c) + 1;
        }
        pos.set(c, r);
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
