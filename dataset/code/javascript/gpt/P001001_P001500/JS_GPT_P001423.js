// P001423 - Find and Replace Pattern
const fs = require("fs");

function isVowel(c) {
    return c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u';
}

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    let ans = 0;
    for (let i = 0; i < s.length; i++) {
        let v = 0, c = 0;
        for (let j = i; j < s.length; j++) {
            if (isVowel(s[j])) v++;
            else c++;
            if (v === c && (v * c) % k === 0) {
                ans++;
            }
        }
    }
    console.log(ans);
}

main();
