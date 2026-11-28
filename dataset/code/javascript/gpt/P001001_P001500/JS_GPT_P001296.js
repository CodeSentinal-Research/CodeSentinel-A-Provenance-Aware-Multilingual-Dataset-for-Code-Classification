// P001296 - Earliest Full Bloom
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const plant = [];
    for (let i = 0; i < n; i++) plant.push(parseInt(input[ptr++], 10));
    const grow = [];
    for (let i = 0; i < n; i++) grow.push(parseInt(input[ptr++], 10));
    const plants = [];
    for (let i = 0; i < n; i++) plants.push([plant[i], grow[i]]);
    plants.sort((a, b) => b[1] - a[1]);
    let curTime = 0, maxBloom = 0;
    for (const [p, g] of plants) {
        curTime += p;
        maxBloom = Math.max(maxBloom, curTime + g);
    }
    console.log(maxBloom);
}

main();
