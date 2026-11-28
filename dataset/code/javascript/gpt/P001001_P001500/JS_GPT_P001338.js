// P001338 - Sequential Digits
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const low = parseInt(input[0], 10);
    const high = parseInt(input[1], 10);
    const digits = "123456789";
    const res = [];
    for (let len = 1; len <= 9; len++) {
        for (let i = 0; i + len <= 9; i++) {
            const val = parseInt(digits.substring(i, i + len), 10);
            if (val >= low && val <= high) res.push(val);
        }
    }
    res.sort((a, b) => a - b);
    console.log(res.join(" "));
}

main();
