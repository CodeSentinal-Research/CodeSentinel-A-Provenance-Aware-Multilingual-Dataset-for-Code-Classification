// P001514 - Longest Semi-Repetitive Substring
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let maxLen = 1, l = 0, repeatCount = 0;
    for (let r = 1; r < s.length; r++) {
        if (s[r] === s[r - 1]) repeatCount++;
        while (repeatCount > 1) {
            if (s[l + 1] === s[l]) repeatCount--;
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
