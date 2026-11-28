// P001092 - Kth Ancestor of a Node
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const node = parseInt(input[1], 10);
    const k = parseInt(input[2], 10);
    let ptr = 3;
    const parent = [];
    for (let i = 0; i < n; i++) parent.push(parseInt(input[ptr++], 10));
    let curr = node;
    for (let i = 0; i < k; i++) {
        if (curr === -1 || curr >= n) {
            curr = -1;
            break;
        }
        curr = parent[curr];
    }
    console.log(curr);
}

main();
