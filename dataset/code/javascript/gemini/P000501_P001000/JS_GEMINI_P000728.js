const fs = require('fs');
function isValid(s) {
    let cnt = 0;
    for (const c of s) {
        if (c === '(') cnt++;
        else if (c === ')') {
            cnt--;
            if (cnt < 0) return false;
        }
    }
    return cnt === 0;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        let level = new Set([s]);
        while (level.size > 0) {
            const valid = Array.from(level).filter(isValid).sort();
            if (valid.length > 0) {
                for (const ans of valid) console.log(ans);
                return;
            }
            const nextLevel = new Set();
            for (const item of level) {
                for (let i = 0; i < item.length; i++) {
                    if (item[i] === '(' || item[i] === ')') {
                        nextLevel.add(item.slice(0, i) + item.slice(i + 1));
                    }
                }
            }
            level = nextLevel;
        }
    }
}
main();