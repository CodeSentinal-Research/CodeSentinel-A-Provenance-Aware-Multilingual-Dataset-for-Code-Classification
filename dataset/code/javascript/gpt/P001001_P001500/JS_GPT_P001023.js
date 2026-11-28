// P001023 - Parent of a Heap Node
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const idx = parseInt(input[1], 10);
    if (idx === 0) {
        console.log("-1");
    } else {
        console.log(Math.floor((idx - 1) / 2));
    }
}

main();
