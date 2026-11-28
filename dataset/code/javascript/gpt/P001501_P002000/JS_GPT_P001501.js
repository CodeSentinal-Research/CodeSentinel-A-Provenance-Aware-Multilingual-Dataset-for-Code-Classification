// P001501 - Maximize Distance to Closest Person
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const seats = [];
    for (let i = 0; i < n; i++) seats.push(parseInt(input[1 + i], 10));
    let last = -1, maxDist = 0;
    for (let i = 0; i < n; i++) {
        if (seats[i] === 1) {
            if (last === -1) {
                maxDist = i;
            } else {
                maxDist = Math.max(maxDist, Math.floor((i - last) / 2));
            }
            last = i;
        }
    }
    maxDist = Math.max(maxDist, n - 1 - last);
    console.log(maxDist);
}

main();
