// P001040 - Maximize Performance of a Team
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
    const engineers = [];
    for (let i = 0; i < n; i++) engineers.push({ s: speed[i], e: efficiency[i] });
    engineers.sort((a, b) => (b.e > a.e ? 1 : b.e < a.e ? -1 : 0));
    const speeds = [];
    let sumSpeed = 0n;
    let maxPerf = 0n;
    for (const eng of engineers) {
        let low = 0, high = speeds.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (speeds[mid] < eng.s) low = mid + 1;
            else high = mid;
        }
        speeds.splice(low, 0, eng.s);
        sumSpeed += eng.s;
        if (speeds.length > k) {
            sumSpeed -= speeds.shift();
        }
        const curPerf = sumSpeed * eng.e;
        if (curPerf > maxPerf) maxPerf = curPerf;
    }
    const MOD = 1000000007n;
    console.log((maxPerf % MOD).toString());
}

main();
