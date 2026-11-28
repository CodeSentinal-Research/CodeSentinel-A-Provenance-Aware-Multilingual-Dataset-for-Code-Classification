// P001252 - Maximum Length Pair Chain
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let even = 0, odd = 0;
    for (let i = 0; i < n; i++) {
        const pos = parseInt(input[1 + i], 10);
        if (pos % 2 === 0) even++;
        else odd++;
    }
    console.log(Math.min(even, odd));
}

main();
