// P001124 - Cheapest Flight Within K Stops
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 5) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const src = parseInt(input[2], 10);
    const dst = parseInt(input[3], 10);
    const k = parseInt(input[4], 10);
    let ptr = 5;
    const flights = [];
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        const w = parseInt(input[ptr++], 10);
        flights.push([u, v, w]);
    }
    let dist = new Array(n).fill(Infinity);
    dist[src] = 0;
    for (let i = 0; i <= k; i++) {
        const temp = [...dist];
        for (const [u, v, w] of flights) {
            if (dist[u] !== Infinity && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        dist = temp;
    }
    console.log(dist[dst] === Infinity ? -1 : dist[dst]);
}

main();
