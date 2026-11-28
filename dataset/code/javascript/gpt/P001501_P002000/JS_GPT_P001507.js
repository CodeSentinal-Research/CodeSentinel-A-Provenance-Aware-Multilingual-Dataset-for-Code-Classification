// P001507 - Longest Turbulent Subarray
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    if (n === 1) {
        console.log(1);
        return;
    }
    let inc = 1, dec = 1, maxLen = 1;
    for (let i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            inc = dec + 1;
            dec = 1;
        } else if (arr[i] < arr[i - 1]) {
            dec = inc + 1;
            inc = 1;
        } else {
            inc = 1;
            dec = 1;
        }
        maxLen = Math.max(maxLen, inc, dec);
    }
    console.log(maxLen);
}

main();
