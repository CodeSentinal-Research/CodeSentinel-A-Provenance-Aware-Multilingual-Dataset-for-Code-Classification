// P001262 - Course Schedule III
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const courses = [];
    for (let i = 0; i < n; i++) {
        courses.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    }
    courses.sort((a, b) => a[1] - b[1]);
    const maxHeap = [];
    let curTime = 0;
    for (const [dur, lastDay] of courses) {
        curTime += dur;
        let low = 0, high = maxHeap.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (maxHeap[mid] < dur) low = mid + 1;
            else high = mid;
        }
        maxHeap.splice(low, 0, dur);
        if (curTime > lastDay) {
            curTime -= maxHeap.pop();
        }
    }
    console.log(maxHeap.length);
}

main();
