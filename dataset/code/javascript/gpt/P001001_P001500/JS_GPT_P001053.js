// P001053 - Priority Queue Simulation
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const q = parseInt(input[0], 10);
    let ptr = 1;
    const pq = [];
    const out = [];
    for (let i = 0; i < q; i++) {
        const type = parseInt(input[ptr++], 10);
        if (type === 1) {
            const val = parseInt(input[ptr++], 10);
            let low = 0, high = pq.length;
            while (low < high) {
                const mid = (low + high) >> 1;
                if (pq[mid] > val) low = mid + 1;
                else high = mid;
            }
            pq.splice(low, 0, val);
        } else if (type === 2) {
            if (pq.length > 0) {
                out.push(pq.shift());
            } else {
                out.push(-1);
            }
        }
    }
    for (const val of out) console.log(val);
}

main();
