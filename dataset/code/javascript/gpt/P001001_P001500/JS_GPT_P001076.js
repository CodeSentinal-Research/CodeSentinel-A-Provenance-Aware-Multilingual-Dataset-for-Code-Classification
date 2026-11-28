// P001076 - Floyd-Warshall All-Pairs Shortest Path
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const dist = [];
    for (let i = 0; i < n; i++) {
        const row = [];
        for (let j = 0; j < n; j++) {
            const val = parseInt(input[ptr++], 10);
            row.push(val === -1 ? Infinity : val);
        }
        dist.push(row);
    }
    for (let k = 0; k < n; k++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (dist[i][k] !== Infinity && dist[k][j] !== Infinity) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    for (let i = 0; i < n; i++) {
        console.log(dist[i].map(d => (d === Infinity ? -1 : d)).join(" "));
    }
}

main();
