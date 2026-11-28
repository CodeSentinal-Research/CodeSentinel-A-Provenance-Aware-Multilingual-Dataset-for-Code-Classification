const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const words = tokens.slice(1, 1 + n);
        const masks = [];
        for (const w of words) {
            let m = 0, dup = false;
            for (const ch of w) {
                const b = 1 << (ch.charCodeAt(0) - 97);
                if (m & b) { dup = true; break; }
                m |= b;
            }
            if (!dup) masks.push([m, w.length]);
        }
        let maxLen = 0;
        function backtrack(idx, curM, curLen) {
            maxLen = Math.max(maxLen, curLen);
            for (let i = idx; i < masks.length; i++) {
                const [m, l] = masks[i];
                if (!(curM & m)) {
                    backtrack(i + 1, curM | m, curLen + l);
                }
            }
        }
        backtrack(0, 0, 0);
        console.log(maxLen);
    }
}
main();