// P001219 - Word Break II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const diff = parseInt(input[1], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[2 + i], 10));
    const dp = new Map();
    let maxLen = 1;
    for (const x of arr) {
        const prevLen = dp.get(x - diff) || 0;
        const curLen = prevLen + 1;
        dp.set(x, curLen);
        if (curLen > maxLen) maxLen = curLen;
    }
    console.log(maxLen);
}

main();
