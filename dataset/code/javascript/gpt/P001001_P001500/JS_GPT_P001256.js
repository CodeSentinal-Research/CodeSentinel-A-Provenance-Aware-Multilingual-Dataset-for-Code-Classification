// P001256 - Minimum Deletions to Make Character Frequencies Unique
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const mid = Math.floor(n / 2);
    console.log(mid * (n - mid));
}

main();
