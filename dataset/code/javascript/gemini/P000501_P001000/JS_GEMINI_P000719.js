const fs = require('fs');
function restoreIp(s, idx, parts) {
    if (parts.length === 4) {
        if (idx === s.length) console.log(parts.join('.'));
        return;
    }
    for (let l = 1; l <= 3 && idx + l <= s.length; l++) {
        const part = s.slice(idx, idx + l);
        if ((part[0] === '0' && part.length > 1) || Number(part) > 255) continue;
        restoreIp(s, idx + l, [...parts, part]);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        restoreIp(tokens[0], 0, []);
    }
}
main();