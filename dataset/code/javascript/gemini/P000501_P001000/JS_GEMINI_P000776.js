const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const s = tokens[0];
        const m = parseInt(tokens[1], 10);
        const dict = new Set(tokens.slice(2, 2 + m));
        const res = [];
        function backtrack(idx, cur) {
            if (idx === s.length) {
                res.push(cur);
                return;
            }
            for (let end = idx + 1; end <= s.length; end++) {
                const w = s.slice(idx, end);
                if (dict.has(w)) {
                    backtrack(end, [...cur, w]);
                }
            }
        }
        backtrack(0, []);
        res.sort((a, b) => {
            for (let i = 0; i < Math.min(a.length, b.length); i++) {
                if (a[i] !== b[i]) return a[i].localeCompare(b[i]);
            }
            return a.length - b.length;
        });
        for (const part of res) console.log(part.join(' '));
    }
}
main();