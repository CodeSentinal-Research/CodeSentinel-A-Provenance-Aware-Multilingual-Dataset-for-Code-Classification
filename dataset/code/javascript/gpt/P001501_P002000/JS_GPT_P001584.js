// P001584 - Longest Substring With At Most K Vowels
const fs = require("fs");

function isVowel(c) {
    const v = "aeiouAEIOU";
    return v.indexOf(c) !== -1;
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    let l = 0, vowels = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        if (isVowel(s[r])) vowels++;
        while (vowels > k) {
            if (isVowel(s[l])) vowels--;
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
