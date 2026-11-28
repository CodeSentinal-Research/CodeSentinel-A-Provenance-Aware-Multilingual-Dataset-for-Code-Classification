// P001303 - Maximize Capital by Selecting Projects
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
    const avail = [];
    for (let step = 0; step < k; step++) {
        while (pIdx < n && projects[pIdx].c <= w) {
            avail.push(projects[pIdx].p);
            pIdx++;
        }
        if (avail.length === 0) break;
        avail.sort((a, b) => b - a);
        w += avail.shift();
    }
    console.log(w);
}

main();
