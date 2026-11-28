// P001360 - Maximum Score Words Formed by Letters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const numLetters = parseInt(input[1], 10);
    let ptr = 2;
    const words = [];
    for (let i = 0; i < n; i++) words.push(input[ptr++]);
    const letterCount = new Array(26).fill(0);
    for (let i = 0; i < numLetters; i++) {
        const c = input[ptr++];
        letterCount[c.charCodeAt(0) - 97]++;
    }
    const score = [];
    for (let i = 0; i < 26; i++) score.push(parseInt(input[ptr++], 10));
    let maxScore = 0;
    function backtrack(idx, curScore) {
        if (curScore > maxScore) maxScore = curScore;
        for (let i = idx; i < n; i++) {
            let canForm = true;
            let gain = 0;
            const w = words[i];
            for (const c of w) {
                const code = c.charCodeAt(0) - 97;
                letterCount[code]--;
                if (letterCount[code] < 0) canForm = false;
                gain += score[code];
            }
            if (canForm) {
                backtrack(i + 1, curScore + gain);
            }
            for (const c of w) {
                letterCount[c.charCodeAt(0) - 97]++;
            }
        }
    }
    backtrack(0, 0);
    console.log(maxScore);
}

main();
