const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const s = tokens[0];
        const m = parseInt(tokens[1], 10);
        const dict = new Set(tokens.slice(2, 2 + m));
        const memo = new Map();
        function backtrack(idx) {
            if (memo.has(idx)) return memo.get(idx);
            if (idx === s.length) return [""];
            const res = [];
            for (let end = idx + 1; end <= s.length; end++) {
                const w = s.slice(idx, end);
                if (dict.has(w)) {
                    const sub = backtrack(end);
                    for (const sent of sub) {
                        res.push((w + (sent === "" ? "" : " ") + sent));
                    }
                }
            }
            memo.set(idx, res);
            return res;
        }
        const res = backtrack(0).sort();
        for (const sent of res) console.log(sent);
    }
}
main();