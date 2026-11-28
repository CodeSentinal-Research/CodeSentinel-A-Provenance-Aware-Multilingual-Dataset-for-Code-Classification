// P001413 - Largest Unique Number
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
    const s = new Set();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        s.add(x);
        s.add(rev(x));
    }
    console.log(s.size);
}

main();
