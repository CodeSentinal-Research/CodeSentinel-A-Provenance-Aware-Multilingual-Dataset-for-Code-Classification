const fs = require('fs');

function isVowel(c) {
    return 'aeiouAEIOU'.includes(c);
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const s = input[0];
        // Calculate midpoint to prevent potential overflow
        const mid = s.length / 2;
        let c1 = 0, c2 = 0;
        for (let i = 0; i < mid; i++) if (isVowel(s[i])) c1++;
        for (let i = mid; i < s.length; i++) if (isVowel(s[i])) c2++;
        console.log(c1 === c2 ? "Yes" : "No");
    }
}

main();