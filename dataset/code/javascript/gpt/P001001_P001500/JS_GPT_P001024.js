// P001024 - Children of a Heap Node
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const idx = parseInt(input[1], 10);
    const left = 2 * idx + 1;
    const right = 2 * idx + 2;
    const lRes = left < n ? left : -1;
    const rRes = right < n ? right : -1;
    console.log(lRes + " " + rRes);
}

main();
