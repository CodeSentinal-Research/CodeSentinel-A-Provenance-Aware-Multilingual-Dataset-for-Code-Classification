const fs = require('fs');

function backtrack(s, index, parts, res) {
    if (parts.length === 4) {
        if (index === s.length) {
            res.push(parts.join('.'));
        }
        return;
    }
    for (let len = 1; len <= 3 && index + len <= s.length; len++) {
        const segment = s.slice(index, index + len);
        if (segment.length > 1 && segment[0] === '0') continue;
        const val = parseInt(segment, 10);
        if (val > 255) continue;
        parts.push(segment);
        backtrack(s, index + len, parts, res);
        parts.pop();
    }
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const s = input[0];
        const res = [];
        backtrack(s, 0, [], res);
        res.forEach(ip => console.log(ip));
    }
}

main();