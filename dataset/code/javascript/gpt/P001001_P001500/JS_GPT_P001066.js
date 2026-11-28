// P001066 - Find All Neighbors of a Vertex
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const target = parseInt(input[2], 10);
    let ptr = 3;
    const neighbors = [];
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        if (u === target) neighbors.push(v);
        else if (v === target) neighbors.push(u);
    }
    neighbors.sort((a, b) => a - b);
    console.log(neighbors.join(" "));
}

main();
