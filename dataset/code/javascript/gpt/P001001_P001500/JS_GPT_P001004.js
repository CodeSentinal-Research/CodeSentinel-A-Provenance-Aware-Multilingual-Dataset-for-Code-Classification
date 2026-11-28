// P001004 - Heap Height Calculation
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n <= 0) {
        console.log(0);
        return;
    }
    console.log(Math.floor(Math.log2(n)));
}

main();
