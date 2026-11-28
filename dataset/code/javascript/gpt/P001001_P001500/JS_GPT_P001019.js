// P001019 - K Closest Points to the Origin
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const points = [];
    let ptr = 2;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        const y = parseInt(input[ptr++], 10);
        points.push([x, y]);
    }
    points.sort((a, b) => (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]));
    for (let i = 0; i < k; i++) {
        console.log(points[i][0] + " " + points[i][1]);
    }
}

main();
