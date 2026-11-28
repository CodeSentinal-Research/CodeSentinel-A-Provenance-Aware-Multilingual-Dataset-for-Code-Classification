const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const s = input[0];
        let ones = 0;
        for (const c of s) if (c === '1') ones++;
        let maxScore = 0, zeros = 0;
        for (let i = 0; i < s.length - 1; i++) {
            if (s[i] === '0') zeros++;
            else ones--;
            maxScore = Math.max(maxScore, zeros + ones);
        }
        console.log(maxScore);
    }
}

main();