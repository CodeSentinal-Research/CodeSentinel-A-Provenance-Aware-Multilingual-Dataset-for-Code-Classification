// P001056 - Smallest Infinite Set Operations
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const q = parseInt(input[0], 10);
    let ptr = 1;
    let minAvail = 1;
    const addedBack = new Set();
    const out = [];
    for (let i = 0; i < q; i++) {
        const op = input[ptr++];
        if (op === "popSmallest") {
            if (addedBack.size > 0) {
                const minAdded = Math.min(...addedBack);
                addedBack.delete(minAdded);
                out.push(minAdded);
            } else {
                out.push(minAvail++);
            }
        } else if (op === "addBack") {
            const num = parseInt(input[ptr++], 10);
            if (num < minAvail) {
                addedBack.add(num);
            }
        }
    }
    for (const val of out) console.log(val);
}

main();
