// P001402 - Check If Array Pairs Are Divisible by K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const rem = new Array(k).fill(0);
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[2 + i], 10);
        const r = ((x % k) + k) % k;
        rem[r]++;
    }
    if (rem[0] % 2 !== 0) {
        console.log("NO");
        return;
    }
    for (let i = 1; i <= Math.floor(k / 2); i++) {
        if (i * 2 === k) {
            if (rem[i] % 2 !== 0) {
                console.log("NO");
                return;
            }
        } else if (rem[i] !== rem[k - i]) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
