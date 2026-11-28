// P001580 - Longest Subarray With At Most K Odd Numbers
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const n = parseInt(input[0], 10);
    const angle = parseInt(input[1], 10);
    const px = parseInt(input[2], 10);
    const py = parseInt(input[3], 10);
    let ptr = 4;
    let same = 0;
    const angles = [];
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        const y = parseInt(input[ptr++], 10);
        if (x === px && y === py) {
            same++;
        } else {
            let deg = (Math.atan2(y - py, x - px) * 180) / Math.PI;
            if (deg < 0) deg += 360;
            angles.push(deg);
        }
    }
    angles.sort((a, b) => a - b);
    const m = angles.length;
    for (let i = 0; i < m; i++) angles.push(angles[i] + 360);
    let maxVisible = 0, r = 0;
    for (let l = 0; l < m; l++) {
        while (r < angles.length && angles[r] <= angles[l] + angle) {
            r++;
        }
        maxVisible = Math.max(maxVisible, r - l);
    }
    console.log(maxVisible + same);
}

main();
