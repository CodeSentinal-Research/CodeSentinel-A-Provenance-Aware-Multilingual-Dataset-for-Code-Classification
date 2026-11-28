// P001570 - Longest Continuous Subarray With Positive Product
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 4) return;
    const s = input[0];
    const maxLetters = parseInt(input[1], 10);
    const minSize = parseInt(input[2], 10);
    const maxSize = parseInt(input[3], 10);
    const freq = new Map();
    let maxOcc = 0;
    for (let i = 0; i + minSize <= s.length; i++) {
        const sub = s.substring(i, i + minSize);
        const unique = new Set(sub).size;
        if (unique <= maxLetters) {
            const count = (freq.get(sub) || 0) + 1;
            freq.set(sub, count);
            maxOcc = Math.max(maxOcc, count);
        }
    }
    console.log(maxOcc);
}

main();
