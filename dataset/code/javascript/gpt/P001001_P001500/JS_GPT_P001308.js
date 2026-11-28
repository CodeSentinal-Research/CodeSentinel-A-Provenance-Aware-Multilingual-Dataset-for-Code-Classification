// P001308 - Defense of a Kingdom
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const w = parseInt(input[0], 10);
    const h = parseInt(input[1], 10);
    const n = parseInt(input[2], 10);
    let ptr = 3;
    const x = [0], y = [0];
    for (let i = 0; i < n; i++) {
        x.push(parseInt(input[ptr++], 10));
        y.push(parseInt(input[ptr++], 10));
    }
    x.push(w + 1);
    y.push(h + 1);
    x.sort((a, b) => a - b);
    y.sort((a, b) => a - b);
    let maxX = 0, maxY = 0;
    for (let i = 1; i < x.length; i++) maxX = Math.max(maxX, x[i] - x[i - 1] - 1);
    for (let i = 1; i < y.length; i++) maxY = Math.max(maxY, y[i] - y[i - 1] - 1);
    console.log(maxX * maxY);
}

main();
