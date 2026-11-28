const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        let cur = 0, groupLen = 1;
        const res = [];
        while (cur < n) {
            const actualLen = Math.min(groupLen, n - cur);
            const chunk = vals.slice(cur, cur + actualLen);
            if (actualLen % 2 === 0) res.push(...chunk.reverse());
            else res.push(...chunk);
            cur += actualLen;
            groupLen++;
        }
        console.log(res.join(' '));
    }
}
main();