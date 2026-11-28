// P001419 - Sort Characters by Occurrence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const seen = new Set();
    let count = 0;
    for (let i = 0; i < n; i++) {
        const word = input[1 + i];
        const rev = word.split("").reverse().join("");
        if (seen.has(rev)) {
            count++;
        }
        seen.add(word);
    }
    console.log(count);
}

main();
