// P001041 - Minimum Cost to Hire K Workers
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    let ptr = 2;
    const quality = [];
    for (let i = 0; i < n; i++) quality.push(parseFloat(input[ptr++]));
    const wage = [];
    for (let i = 0; i < n; i++) wage.push(parseFloat(input[ptr++]));
    const workers = [];
    for (let i = 0; i < n; i++) {
        workers.push({ q: quality[i], r: wage[i] / quality[i] });
    }
    workers.sort((a, b) => a.r - b.r);
    const maxHeap = [];
    let qSum = 0;
    let minCost = Infinity;
    for (const w of workers) {
        let low = 0, high = maxHeap.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (maxHeap[mid] < w.q) low = mid + 1;
            else high = mid;
        }
        maxHeap.splice(low, 0, w.q);
        qSum += w.q;
        if (maxHeap.length > k) {
            qSum -= maxHeap.pop();
        }
        if (maxHeap.length === k) {
            minCost = Math.min(minCost, qSum * w.r);
        }
    }
    console.log(minCost.toFixed(5));
}

main();
