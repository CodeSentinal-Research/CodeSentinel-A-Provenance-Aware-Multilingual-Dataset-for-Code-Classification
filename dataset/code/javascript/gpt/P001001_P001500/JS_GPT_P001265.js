// P001265 - Maximum Performance of a Team
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    let ptr = 2;
    const speed = [];
    for (let i = 0; i < n; i++) speed.push(BigInt(input[ptr++]));
    const efficiency = [];
    for (let i = 0; i < n; i++) efficiency.push(BigInt(input[ptr++]));
    const eng = [];
    for (let i = 0; i < n; i++) eng.push({ s: speed[i], e: efficiency[i] });
    eng.sort((a, b) => (b.e > a.e ? 1 : b.e < a.e ? -1 : 0));
    const pq = [];
    let sumSpeed = 0n, maxPerf = 0n;
    for (const e of eng) {
        let low = 0, high = pq.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (pq[mid] < e.s) low = mid + 1;
            else high = mid;
        }
        pq.splice(low, 0, e.s);
        sumSpeed += e.s;
        if (pq.length > k) {
            sumSpeed -= pq.shift();
        }
        const curPerf = sumSpeed * e.e;
        if (curPerf > maxPerf) maxPerf = curPerf;
    }
    const MOD = 1000000007n;
    console.log((maxPerf % MOD).toString());
}

main();
