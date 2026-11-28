// P001425 - Destination City
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let maxLen = 0;
    const count = new Map();
    let l = 0;
    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        count.set(c, (count.get(c) || 0) + 1);
        while (count.get(c) > 2) {
            const leftChar = s[l];
            count.set(leftChar, count.get(leftChar) - 1);
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
