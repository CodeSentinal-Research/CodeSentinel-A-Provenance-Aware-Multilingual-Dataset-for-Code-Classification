// P001025 - Count Internal Nodes in a Heap
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    console.log(Math.floor(n / 2));
}

main();
