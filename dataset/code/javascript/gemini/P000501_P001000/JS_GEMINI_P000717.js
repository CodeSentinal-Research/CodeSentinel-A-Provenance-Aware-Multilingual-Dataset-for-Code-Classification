const fs = require('fs');
function isPal(s) { return s === s.split('').reverse().join(''); }
function palPartition(s, start, cur) {
    if (start === s.length) {
        console.log(cur.join(' '));
        return;
    }
    for (let end = start + 1; end <= s.length; end++) {
        const sub = s.slice(start, end);
        if (isPal(sub)) {
            palPartition(s, end, [...cur, sub]);
        }
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        palPartition(tokens[0], 0, []);
    }
}
main();