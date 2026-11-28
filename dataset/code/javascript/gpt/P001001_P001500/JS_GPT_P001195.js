// P001195 - Maximum Alternating Subsequence Sum
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let even = 0n, odd = 0n;
    for (let i = 0; i < n; i++) {
        const x = BigInt(input[1 + i]);
        const nextEven = even > (odd + x) ? even : (odd + x);
        const nextOdd = odd > (even - x) ? odd : (even - x);
        even = nextEven;
        odd = nextOdd;
    }
    console.log(even.toString());
}

main();
