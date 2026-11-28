// P001397 - Brick Wall
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const numRows = parseInt(input[0], 10);
    let ptr = 1;
    const edges = new Map();
    let maxEdges = 0;
    for (let i = 0; i < numRows; i++) {
        const len = parseInt(input[ptr++], 10);
        let pos = 0;
        for (let j = 0; j < len; j++) {
            const w = parseInt(input[ptr++], 10);
            pos += w;
            if (j < len - 1) {
                const count = (edges.get(pos) || 0) + 1;
                edges.set(pos, count);
                if (count > maxEdges) maxEdges = count;
            }
        }
    }
    console.log(numRows - maxEdges);
}

main();
