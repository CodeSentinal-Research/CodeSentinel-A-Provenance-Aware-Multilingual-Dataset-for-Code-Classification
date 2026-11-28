// P001020 - Smallest Range Covering K Sorted Lists
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const k = parseInt(input[0], 10);
    let ptr = 1;
    const lists = [];
    for (let i = 0; i < k; i++) {
        const len = parseInt(input[ptr++], 10);
        const cur = [];
        for (let j = 0; j < len; j++) cur.push(parseInt(input[ptr++], 10));
        lists.push(cur);
    }
    const pointers = new Array(k).fill(0);
    let bestRange = [0, Infinity];
    while (true) {
        let minVal = Infinity, minIdx = -1, maxVal = -Infinity;
        for (let i = 0; i < k; i++) {
            const val = lists[i][pointers[i]];
            if (val < minVal) { minVal = val; minIdx = i; }
            if (val > maxVal) { maxVal = val; }
        }
        if (maxVal - minVal < bestRange[1] - bestRange[0]) {
            bestRange = [minVal, maxVal];
        }
        pointers[minIdx]++;
        if (pointers[minIdx] >= lists[minIdx].length) break;
    }
    console.log(bestRange[0] + " " + bestRange[1]);
}

main();
