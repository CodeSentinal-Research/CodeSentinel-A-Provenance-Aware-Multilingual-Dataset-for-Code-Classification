// P001264 - Minimum Initial Energy to Finish Tasks
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const tasks = [];
    for (let i = 0; i < n; i++) {
        tasks.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    }
    tasks.sort((a, b) => (b[1] - b[0]) - (a[1] - a[0]));
    let energy = 0, cur = 0;
    for (const [act, minReq] of tasks) {
        if (cur < minReq) {
            energy += (minReq - cur);
            cur = minReq;
        }
        cur -= act;
    }
    console.log(energy);
}

main();
