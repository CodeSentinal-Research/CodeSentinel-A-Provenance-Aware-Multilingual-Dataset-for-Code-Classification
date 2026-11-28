// P001044 - Level of a Heap Node
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const idx = parseInt(input[1], 10);
    console.log(Math.floor(Math.log2(idx + 1)));
}

main();
