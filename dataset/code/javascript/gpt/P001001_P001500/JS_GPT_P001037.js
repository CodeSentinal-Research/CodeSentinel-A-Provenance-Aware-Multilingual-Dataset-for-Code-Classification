// P001037 - Task Scheduler with Cooling Time
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length === 0) return;
    const tasks = lines[0].trim().split(/\s+/);
    const n = lines.length > 1 ? parseInt(lines[1].trim(), 10) : 0;
    const freq = new Map();
    let maxFreq = 0;
    for (const t of tasks) {
        const count = (freq.get(t) || 0) + 1;
        freq.set(t, count);
        if (count > maxFreq) maxFreq = count;
    }
    let maxCount = 0;
    for (const count of freq.values()) {
        if (count === maxFreq) maxCount++;
    }
    const ans = Math.max(tasks.length, (maxFreq - 1) * (n + 1) + maxCount);
    console.log(ans);
}

main();
