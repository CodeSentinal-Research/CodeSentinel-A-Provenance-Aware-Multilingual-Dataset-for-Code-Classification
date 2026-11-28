// P001539 - Count Vowel Substrings of a String
const fs = require("fs");

function isVowel(c) {
    return c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u';
}

function main() {
    const word = fs.readFileSync(0, "utf8").trim();
    if (!word) return;
    let count = 0;
    for (let i = 0; i < word.length; i++) {
        if (!isVowel(word[i])) continue;
        const set = new Set();
        for (let j = i; j < word.length; j++) {
            if (!isVowel(word[j])) break;
            set.add(word[j]);
            if (set.size === 5) count++;
        }
    }
    console.log(count);
}

main();
