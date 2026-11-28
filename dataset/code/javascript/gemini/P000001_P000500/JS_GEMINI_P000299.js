const fs = require('fs');

function backtrack(res, current, open, close, max) {
    if (current.length === max * 2) {
        res.push(current);
        return;
    }
    if (open < max) {
        backtrack(res, current + '(', open + 1, close, max);
    }
    if (close < open) {
        backtrack(res, current + ')', open, close + 1, max);
    }
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const n = parseInt(input[0], 10);
        const res = [];
        backtrack(res, '', 0, 0, n);
        res.forEach(s => console.log(s));
    }
}

main();