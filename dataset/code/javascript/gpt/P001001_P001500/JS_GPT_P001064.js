// P001064 - Check Whether an Edge Exists
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const queryU = parseInt(input[2], 10);
    const queryV = parseInt(input[3], 10);
    let ptr = 4;
    let found = false;
    for (let i = 0; i < m; i++) {
        const u = parseInt(input[ptr++], 10);
        const v = parseInt(input[ptr++], 10);
        if ((u === queryU && v === queryV) || (u === queryV && v === queryU)) {
            found = true;
        }
    }
    console.log(found ? "YES" : "NO");
}

main();
