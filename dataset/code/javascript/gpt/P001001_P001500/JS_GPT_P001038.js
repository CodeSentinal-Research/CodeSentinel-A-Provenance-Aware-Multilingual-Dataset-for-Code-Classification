// P001038 - IPO Capital Maximization
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const k = parseInt(input[0], 10);
    let w = parseInt(input[1], 10);
    const n = parseInt(input[2], 10);
    let ptr = 3;
    const profits = [];
    for (let i = 0; i < n; i++) profits.push(parseInt(input[ptr++], 10));
    const capital = [];
    for (let i = 0; i < n; i++) capital.push(parseInt(input[ptr++], 10));
    const projects = [];
    for (let i = 0; i < n; i++) projects.push({ c: capital[i], p: profits[i] });
    projects.sort((a, b) => a.c - b.c);
    let pIdx = 0;
    const available = [];
    for (let step = 0; step < k; step++) {
        while (pIdx < n && projects[pIdx].c <= w) {
            available.push(projects[pIdx].p);
            pIdx++;
        }
        if (available.length === 0) break;
        available.sort((a, b) => b - a);
        w += available.shift();
    }
    console.log(w);
}

main();
