// P001395 - Number of Boomerangs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const points = [];
    for (let i = 0; i < n; i++) {
        points.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    }
    let boomerangs = 0;
    for (let i = 0; i < n; i++) {
        const distCount = new Map();
        for (let j = 0; j < n; j++) {
            if (i !== j) {
                const dx = points[i][0] - points[j][0];
                const dy = points[i][1] - points[j][1];
                const d2 = dx * dx + dy * dy;
                distCount.set(d2, (distCount.get(d2) || 0) + 1);
            }
        }
        for (const count of distCount.values()) {
            boomerangs += count * (count - 1);
        }
    }
    console.log(boomerangs);
}

main();
