const fs = require('fs');

function shortestToChar(s, c) {
    const n = s.length;
    const res = new Array(n).fill(Infinity);
    let prev = -Infinity;
    for (let i = 0; i < n; i++) {
        if (s[i] === c) prev = i;
        res[i] = i - prev;
    }
    prev = Infinity;
    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === c) prev = i;
        res[i] = Math.min(res[i], prev - i);
    }
    return res;
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        console.log(shortestToChar(input[0], input[1]).join(' '));
    }
}

main();