// P001368 - Count Lexicographically Sorted Vowel Strings
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    // Formula is C(n + 4, 4)
    const ans = ((n + 4) * (n + 3) * (n + 2) * (n + 1)) / 24;
    console.log(ans);
}

main();
