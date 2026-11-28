const fs = require('fs');

function firstUniqChar(s) {
    const counts = {};
    for (const c of s) counts[c] = (counts[c] || 0) + 1;
    for (let i = 0; i < s.length; i++) {
        if (counts[s[i]] === 1) return i;
    }
    return -1;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        console.log(firstUniqChar(input[0]));
    }
}

main();