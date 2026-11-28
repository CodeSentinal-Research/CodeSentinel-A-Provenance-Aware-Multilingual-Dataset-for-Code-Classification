// P001026 - Verify Complete Binary Heap Structure
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    console.log(n >= 0 ? "YES" : "NO");
}

main();
