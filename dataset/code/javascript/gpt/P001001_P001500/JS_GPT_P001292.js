// P001292 - Eliminate Maximum Number of Monsters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const dist = [];
    for (let i = 0; i < n; i++) dist.push(parseInt(input[ptr++], 10));
    const speed = [];
    for (let i = 0; i < n; i++) speed.push(parseInt(input[ptr++], 10));
    const time = [];
    for (let i = 0; i < n; i++) time.push(dist[i] / speed[i]);
    time.sort((a, b) => a - b);
    for (let i = 0; i < n; i++) {
        if (time[i] <= i) {
            console.log(i);
            return;
        }
    }
    console.log(n);
}

main();
