// P001479 - Shortest Unsorted Continuous Subarray
const fs = require("fs");

function isVowel(c) {
    const v = "aeiouAEIOU";
    return v.indexOf(c) !== -1;
}

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const chars = s.split("");
    let l = 0, r = chars.length - 1;
    while (l < r) {
        while (l < r && !isVowel(chars[l])) l++;
        while (l < r && !isVowel(chars[r])) r--;
        if (l < r) {
            const t = chars[l];
            chars[l] = chars[r];
            chars[r] = t;
            l++;
            r--;
        }
    }
    console.log(chars.join(""));
}

main();
