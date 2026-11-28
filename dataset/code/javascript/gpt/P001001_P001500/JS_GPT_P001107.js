// P001107 - Transitive Closure of a Directed Graph
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const reach = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) {
            row.push(parseInt(input[ptr++], 10));
        }
        row[i] = 1;
        reach.push(row);
    }
    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (reach[i][k] && reach[k][j]) {
                    reach[i][j] = 1;
                }
            }
        }
    }
    for (let i = 0; i < n; i++) {
        console.log(reach[i].join(" "));
    }
}

main();
