// P001231 - Assign Cookies
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const activities = [];
    for (let i = 0; i < n; i++) {
        const start = parseInt(input[ptr++], 10);
        const end = parseInt(input[ptr++], 10);
        activities.push({ start, end });
    }
    activities.sort((a, b) => a.end - b.end);
    let count = 0, lastEnd = -Infinity;
    for (const act of activities) {
        if (act.start >= lastEnd) {
            count++;
            lastEnd = act.end;
        }
    }
    console.log(count);
}

main();
