// P001417 - Relative Sort Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const forts = [];
    for (let i = 0; i < n; i++) forts.push(parseInt(input[1 + i], 10));
    let maxCapture = 0;
    let prev = -1;
    for (let i = 0; i < n; i++) {
        if (forts[i] === 1 || forts[i] === -1) {
            if (prev !== -1 && forts[i] !== forts[prev]) {
                maxCapture = Math.max(maxCapture, i - prev - 1);
            }
            prev = i;
        }
    }
    console.log(maxCapture);
}

main();
