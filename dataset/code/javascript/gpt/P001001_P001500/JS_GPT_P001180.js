// P001180 - Vacation Planning
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    let prev = [0, 0, 0];
    for (let i = 0; i < n; i++) {
        const a = parseInt(input[ptr++], 10);
        const b = parseInt(input[ptr++], 10);
        const c = parseInt(input[ptr++], 10);
        const cur0 = a + Math.max(prev[1], prev[2]);
        const cur1 = b + Math.max(prev[0], prev[2]);
        const cur2 = c + Math.max(prev[0], prev[1]);
        prev = [cur0, cur1, cur2];
    }
    console.log(Math.max(...prev));
}

main();
