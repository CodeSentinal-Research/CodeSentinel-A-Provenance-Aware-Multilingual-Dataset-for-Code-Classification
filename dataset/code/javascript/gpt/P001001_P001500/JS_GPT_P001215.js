// P001215 - Remove Boxes
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const time = parseInt(input[1], 10);
    let ptr = 2;
    const maxReach = new Array(time + 1).fill(0);
    for (let i = 0; i < n; i++) {
        const start = parseInt(input[ptr++], 10);
        const end = parseInt(input[ptr++], 10);
        if (start <= time) {
            maxReach[start] = Math.max(maxReach[start], end);
        }
    }
    let clips = 0, curEnd = 0, farthest = 0;
    for (let i = 0; i < time; i++) {
        farthest = Math.max(farthest, maxReach[i]);
        if (i === curEnd) {
            clips++;
            curEnd = farthest;
            if (curEnd <= i) {
                console.log(-1);
                return;
            }
        }
    }
    console.log(clips);
}

main();
