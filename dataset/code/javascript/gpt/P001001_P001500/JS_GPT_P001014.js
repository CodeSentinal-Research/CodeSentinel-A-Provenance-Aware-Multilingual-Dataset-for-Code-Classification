// P001014 - Merge K Sorted Arrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const k = parseInt(input[0], 10);
    const n = parseInt(input[1], 10);
    const all = [];
    let ptr = 2;
    for (let i = 0; i < k * n; i++) {
        all.push(parseInt(input[ptr++], 10));
    }
    all.sort((a, b) => a - b);
    console.log(all.join(" "));
}

main();
