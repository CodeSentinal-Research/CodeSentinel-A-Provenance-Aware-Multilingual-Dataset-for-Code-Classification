// P001405 - Count Nice Pairs in an Array
const fs = require("fs");

function rev(num) {
    let r = 0;
    while (num > 0) {
        r = r * 10 + (num % 10);
        num = Math.floor(num / 10);
    }
    return r;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const MOD = 1000000007;
    const freq = new Map();
    let ans = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        const diff = x - rev(x);
        const count = freq.get(diff) || 0;
        ans = (ans + count) % MOD;
        freq.set(diff, count + 1);
    }
    console.log(ans);
}

main();
