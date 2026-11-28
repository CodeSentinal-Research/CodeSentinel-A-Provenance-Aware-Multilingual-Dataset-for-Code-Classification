// P001290 - Maximum Score from Removing Stones
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const a = parseInt(input[0], 10);
    const b = parseInt(input[1], 10);
    const c = parseInt(input[2], 10);
    const stones = [a, b, c].sort((x, y) => x - y);
    if (stones[0] + stones[1] <= stones[2]) {
        console.log(stones[0] + stones[1]);
    } else {
        console.log(Math.floor((a + b + c) / 2));
    }
}

main();
