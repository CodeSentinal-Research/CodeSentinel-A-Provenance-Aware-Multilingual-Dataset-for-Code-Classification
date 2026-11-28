// P001506 - Minimum Window Subsequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s1 = input[0];
    const s2 = input[1];
    let minLen = Infinity, start = -1;
    let i = 0, j = 0;
    while (i < s1.length) {
        if (s1[i] === s2[j]) {
            j++;
            if (j === s2.length) {
                let end = i;
                j--;
                while (j >= 0) {
                    if (s1[i] === s2[j]) j--;
                    i--;
                }
                i++;
                j++;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }
        i++;
    }
    console.log(start === -1 ? "" : s1.substring(start, start + minLen));
}

main();
