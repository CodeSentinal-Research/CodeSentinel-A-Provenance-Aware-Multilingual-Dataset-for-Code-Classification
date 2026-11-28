// P001309 - Survival on an Island
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const s = parseInt(input[0], 10);
    const n = parseInt(input[1], 10);
    const m = parseInt(input[2], 10);
    if (m > n || (s >= 7 && (n - m) * 6 < m)) {
        console.log("-1");
        return;
    }
    const totalFood = s * m;
    console.log(Math.ceil(totalFood / n));
}

main();
