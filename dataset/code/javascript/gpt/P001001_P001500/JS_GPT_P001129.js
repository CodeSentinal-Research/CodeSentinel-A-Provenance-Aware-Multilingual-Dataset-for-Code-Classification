// P001129 - Remove Maximum Number of Edges While Keeping Graph Fully Traversable
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const edges = [];
    for (let i = 0; i < m; i++) {
        const type = parseInt(input[ptr++], 10);
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        edges.push([type, u, v]);
    }
    const parentA = Array.from({ length: n + 1 }, (_, i) => i);
    const parentB = Array.from({ length: n + 1 }, (_, i) => i);
    function find(parent, i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent, parent[i]);
    }
    let usedEdges = 0;
    let countA = 1, countB = 1;
    for (const [type, u, v] of edges) {
        if (type === 3) {
            const ra = find(parentA, u), rb = find(parentA, v);
            const rba = find(parentB, u), rbb = find(parentB, v);
            let used = false;
            if (ra !== rb) {
                parentA[ra] = rb;
                countA++;
                used = true;
            }
            if (rba !== rbb) {
                parentB[rba] = rbb;
                countB++;
                used = true;
            }
            if (used) usedEdges++;
        }
    }
    for (const [type, u, v] of edges) {
        if (type === 1) {
            const ra = find(parentA, u), rb = find(parentA, v);
            if (ra !== rb) {
                parentA[ra] = rb;
                countA++;
                usedEdges++;
            }
        } else if (type === 2) {
            const rb = find(parentB, u), rbb = find(parentB, v);
            if (rb !== rbb) {
                parentB[rb] = rbb;
                countB++;
                usedEdges++;
            }
        }
    }
    if (countA === n && countB === n) {
        console.log(m - usedEdges);
    } else {
        console.log(-1);
    }
}

main();
