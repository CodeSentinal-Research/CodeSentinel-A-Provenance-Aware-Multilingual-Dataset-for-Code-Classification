const fs = require('fs');

function sameCharacters(s1, s2) {
    if (s1.length !== s2.length) return false;
    const count = {};
    for (const c of s1) count[c] = (count[c] || 0) + 1;
    for (const c of s2) {
        if (!count[c]) return false;
        count[c]--;
    }
    return true;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(sameCharacters(input[0], input[1]) ? "Yes" : "No");
    }
}

main();