const fs = require('fs');

function checkAlmostEquivalent(word1, word2) {
    const count = new Array(26).fill(0);
    for (let i = 0; i < word1.length; i++) count[word1.charCodeAt(i) - 97]++;
    for (let i = 0; i < word2.length; i++) count[word2.charCodeAt(i) - 97]--;
    for (let i = 0; i < 26; i++) {
        if (Math.abs(count[i]) > 3) return false;
    }
    return true;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(checkAlmostEquivalent(input[0], input[1]) ? "Yes" : "No");
    }
}

main();