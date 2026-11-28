// P001511 - Max Consecutive Answers
const fs = require("fs");

function maxConsecutiveChar(s, k, target) {
    let l = 0, count = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        if (s[r] !== target) count++;
        while (count > k) {
            if (s[l] !== target) count--;
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const answerKey = input[0];
    const k = parseInt(input[1], 10);
    const ans = Math.max(maxConsecutiveChar(answerKey, k, 'T'), maxConsecutiveChar(answerKey, k, 'F'));
    console.log(ans);
}

main();
