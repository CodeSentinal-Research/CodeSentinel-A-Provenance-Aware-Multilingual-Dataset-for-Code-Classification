// P001569 - Maximum Erasure Value
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const num = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const s = num.toString();
    let ans = 0;
    for (let i = 0; i + k <= s.length; i++) {
        const val = parseInt(s.substring(i, i + k), 10);
        if (val !== 0 && num % val === 0) {
            ans++;
        }
    }
    console.log(ans);
}

main();
