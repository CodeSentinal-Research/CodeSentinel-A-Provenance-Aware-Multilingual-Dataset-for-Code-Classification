// P001339 - Maximum Length of Concatenated String with Unique Characters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(input[1 + i]);
    let maxLen = 0;
    function backtrack(idx, mask, curLen) {
        if (curLen > maxLen) maxLen = curLen;
        for (let i = idx; i < n; i++) {
            let wordMask = 0, valid = true;
            for (const c of arr[i]) {
                const bit = 1 << (c.charCodeAt(0) - 97);
                if (wordMask & bit) { valid = false; break; }
                wordMask |= bit;
            }
            if (valid && (mask & wordMask) === 0) {
                backtrack(i + 1, mask | wordMask, curLen + arr[i].length);
            }
        }
    }
    backtrack(0, 0, 0);
    console.log(maxLen);
}

main();
