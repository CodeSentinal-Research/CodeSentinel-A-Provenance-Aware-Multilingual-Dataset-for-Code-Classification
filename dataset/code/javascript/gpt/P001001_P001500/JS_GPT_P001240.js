// P001240 - Erase Overlapping Intervals
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const points = [];
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        const y = parseInt(input[ptr++], 10);
        points.push([x, y]);
    }
    points.sort((a, b) => a[1] - b[1]);
    let arrows = 1;
    let arrowPos = points[0][1];
    for (let i = 1; i < n; i++) {
        if (points[i][0] > arrowPos) {
            arrows++;
            arrowPos = points[i][1];
        }
    }
    console.log(arrows);
}

main();
