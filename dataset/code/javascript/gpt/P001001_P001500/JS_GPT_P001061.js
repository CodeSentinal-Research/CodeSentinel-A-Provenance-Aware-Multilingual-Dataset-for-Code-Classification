// P001061 - Detect Cycle in a Directed Graph
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const adj = Array.from({ length: n }, () => []);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const val = parseInt(input[ptr++], 10);
            if (val === 1) adj[i].push(j);
        }
    }
    for (let i = 0; i < n; i++) {
        console.log(i + ": " + adj[i].join(" "));
    }
}

main();
