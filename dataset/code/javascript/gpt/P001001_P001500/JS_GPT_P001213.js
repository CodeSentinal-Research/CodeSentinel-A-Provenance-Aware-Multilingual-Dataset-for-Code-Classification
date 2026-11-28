// P001213 - Scramble String
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const count = new Array(1 << 16).fill(0);
    for (const a of nums) {
        for (const b of nums) {
            count[a & b]++;
        }
    }
    let ans = 0;
    for (const c of nums) {
        for (let i = 0; i < (1 << 16); i++) {
            if ((c & i) === 0) ans += count[i];
        }
    }
    console.log(ans);
}

main();
