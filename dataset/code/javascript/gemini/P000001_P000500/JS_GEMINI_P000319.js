const fs = require('fs');

function isOneEditDistance(s, t) {
    if (s === t) return false;
    const m = s.length, n = t.length;
    if (Math.abs(m - n) > 1) return false;
    for (let i = 0; i < Math.min(m, n); i++) {
        if (s[i] !== t[i]) {
            if (m === n) return s.slice(i + 1) === t.slice(i + 1);
            else if (m < n) return s.slice(i) === t.slice(i + 1);
            else return s.slice(i + 1) === t.slice(i);
        }
    }
    return Math.abs(m - n) === 1;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(isOneEditDistance(input[0], input[1]) ? "Yes" : "No");
    } else if (input.length === 1) {
        console.log(isOneEditDistance(input[0], "") ? "Yes" : "No");
    }
}

main();