const fs = require('fs');

function canConstruct(ransomNote, magazine) {
    const counts = {};
    for (const c of magazine) counts[c] = (counts[c] || 0) + 1;
    for (const c of ransomNote) {
        if (!counts[c]) return false;
        counts[c]--;
    }
    return true;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(canConstruct(input[0], input[1]) ? "Yes" : "No");
    }
}

main();