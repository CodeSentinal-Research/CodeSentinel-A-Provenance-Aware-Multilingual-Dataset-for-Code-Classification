// P001555 - Maximum Number of Vowels in a Substring of Length K
const fs = require("fs");

function isVowel(c) {
    return c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u';
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    let cur = 0;
    for (let i = 0; i < k; i++) if (isVowel(s[i])) cur++;
    let maxV = cur;
    for (let i = k; i < s.length; i++) {
        if (isVowel(s[i])) cur++;
        if (isVowel(s[i - k])) cur--;
        maxV = Math.max(maxV, cur);
    }
    console.log(maxV);
}

main();
