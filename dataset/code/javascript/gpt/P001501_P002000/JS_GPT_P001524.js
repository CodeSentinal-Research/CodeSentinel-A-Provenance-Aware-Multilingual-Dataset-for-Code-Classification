// P001524 - Maximize Confusion of an Exam
const fs = require("fs");

function maxConsecutive(s, k, char) {
    let l = 0, count = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        if (s[r] !== char) count++;
        while (count > k) {
            if (s[l] !== char) count--;
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    console.log(Math.max(maxConsecutive(s, k, 'T'), maxConsecutive(s, k, 'F')));
}

main();
